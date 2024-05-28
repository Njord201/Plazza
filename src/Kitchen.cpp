/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"
#include "CookArgs.hpp"

static void *cookFunction(void *arg) {
    auto cookArgs = static_cast<CookArgs*>(arg);

    std::cout << "Cook nb " << cookArgs->getId() << " started" << std::endl;
    while (cookArgs->getKitchen()->isRunning()) {
        // std::cout << "i can start cooking" << std::endl;
        cookArgs->getKitchen()->getStartCooking()->lock();
        std::cout << "waiting for pizza to cook" << std::endl;
        while (cookArgs->getKitchen()->getStackPizzasToCook()->size() == 0);
        Plazza::APizza pizza = cookArgs->getKitchen()->getStackPizzasToCook()->pop();
        // std::cout << "Cook nb " << cookArgs->getId() << " cooking " << pizza.getType() << std::endl;
        cookArgs->getKitchen()->getStartCooking()->unlock();
        pizza.cook();
        cookArgs->getKitchen()->getFinishedPizzasQueue()->sendPizza(&pizza);
    }
    return nullptr;
}

Kitchen::Kitchen(int nbCooks, long restockTime, int id)
    : _restockTime(restockTime), _id(id), _running(true)
{
    _startCooking = std::make_shared<Mutex>();
    _orderQueue = std::make_shared<MessageQueue>();
    _finishedPizzasQueue = std::make_shared<MessageQueue>();
    _stackPizzasToCook = std::make_shared<Stack<Plazza::APizza>>();
    _totalPizzas = 0;
    _cooksOccupied = 0;
    _saturated = false;
    _refillTime = std::make_unique<Timer>();
    _idleTime = std::make_unique<Timer>();

    _cooks = std::list<std::unique_ptr<Thread>>();

    for (int i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Thread>(&cookFunction, new CookArgs(i, this)));
    }

    for (int i = 0; i < Ingredient::INGREDIENTS; i++) {
        _stock.insert(std::make_pair(static_cast<Ingredient>(i), 5));
    }
}

Kitchen::~Kitchen() {
    _running = false;
    for (auto &cook : _cooks) {
        cook->joinThread();
    }
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
            std::cout << "not enough ingredients" << std::endl;
            _orderQueue->sendPizza(order);
        } else {
            std::cout << "pushing pizza to cook" << std::endl;
            std::cout << "stack size: " << _stackPizzasToCook->size() << std::endl;
            _stackPizzasToCook->push(*order);
            std::cout << "stack size: " << _stackPizzasToCook->size() << std::endl;
        }
    }
    //std::cout << "Kitchen " << _id << " is cooking " << _stackPizzasToCook->size() << " pizzas" << std::endl;
    //_client->send("KITCHEN " + std::to_string(_id) + " " + std::to_string(_totalPizzas));
    return 0;
}
