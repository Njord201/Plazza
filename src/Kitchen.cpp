/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"

static void *cookFunction(void *arg) {
    /*auto cookArgs = static_cast<CookArgs*>(arg);

    std::cout << "Cook nb " << cookArgs->getId() << " started" << std::endl;
    while (true) {
        cookArgs->getMutex()->lock();
        cookArgs->getSem()->wait();
        if (cookArgs->getStack()->size() == 0) {
            cookArgs->getMutex()->unlock();
            continue;
        }
        Plazza::APizza pizza = cookArgs->getStack()->pop();
        std::cout << "Cook nb " << cookArgs->getId() << " cooking " << pizza.getType() << std::endl;
        cookArgs->getMutex()->unlock();
        cookArgs->getSem()->post();
        pizza.cook();
        cookArgs->getFinishedPizzasQueue()->sendPizza(&pizza);
    }*/
    return arg;
}


Kitchen::Kitchen(int nbCooks, long restockTime, int id)
{
    _id = id;
    _restockTime = restockTime;

    _cooks = std::list<std::unique_ptr<Thread>>();
    for (int i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Thread>(&cookFunction, (void *) new CookArgs(i, _semPizzasToCook, _stackPizzasToCook, _startCooking, _finishedPizzasQueue)));
    }
    int i = 0;
    while (i < Ingredient::INGREDIENTS) {
        _stock.insert(std::pair<Ingredient, int>((Ingredient)i, 5));
        i++;
    }
    _startCooking = std::make_shared<Mutex>();
    _orderQueue = std::make_shared<MessageQueue>();
    _finishedPizzasQueue = std::make_shared<MessageQueue>();
    _semPizzasToCook = std::make_shared<Semaphore>(2 * nbCooks);
    _semPizzasToCook->post(2 * nbCooks);
    _stackPizzasToCook = std::make_shared<Stack<Plazza::APizza>>();
    _totalPizzas = 0;
    _cooksOccupied = 0;
    _saturated = false;
    _refillTime = std::make_unique<Timer>();
    _idleTime = std::make_unique<Timer>();
}

Kitchen::~Kitchen() {
    std::cout << "Kitchen " << _id << " destroyed" << std::endl;
}

void Kitchen::restock()
{
    // std::cout << "Refill ingredients" << std::endl;
    for (auto &ingredient : _stock) {
        ingredient.second += 1;
    }
}

int Kitchen::loop()
{
    //timers
    if (_refillTime->elapsedMilliseconds() > _restockTime) {
        restock();
        _refillTime->reset();
    }
    if (_idleTime->elapsedSeconds() > 5) {
        return 1;
    }
    if (_orderQueue->size() > 0) {
        _idleTime->reset();

        //get order
        Plazza::APizza *order = _orderQueue->receivePizza();

        //check if enough ingredients
        if (!order->packPizza(_stock)) {
            _orderQueue->sendPizza(order);
        } else {
            _stackPizzasToCook->push(*order);
            _semPizzasToCook->post();
        }
    }
    //std::cout << "Kitchen " << _id << " is cooking " << _stackPizzasToCook->size() << " pizzas" << std::endl;
    //_client->send("KITCHEN " + std::to_string(_id) + " " + std::to_string(_totalPizzas));
    return 0;
}
