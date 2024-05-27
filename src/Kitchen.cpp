/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"

static void *cookFunction(void *arg)
{
    //std::cout << "Cook nb " << ((CookArgs *)arg)->getId() << " started" << std::endl;
    while (1) {
        ((CookArgs *)arg)->getMutex()->lock();
        ((CookArgs *)arg)->getSem()->wait();
        Plazza::APizza pizza = ((CookArgs *)arg)->getStack()->pop();
        std::cout << "Cook nb " << ((CookArgs *)arg)->getId() << " cooking " << pizza.getType() << std::endl;
        ((CookArgs *)arg)->getMutex()->unlock();
        ((CookArgs *)arg)->getSem()->post();
        pizza.cook();
        //std::cout << "Cook nb " << ((CookArgs *)arg)->getId() << " finished cooking " << pizza.getType() << std::endl;
        ((CookArgs *)arg)->getFinishedPizzasQueue()->sendPizza(&pizza);
    }
    return arg;
}

Kitchen::Kitchen(int nbCooks, long restockTime, int id)
{
    _id = id;
    _restockTime = restockTime;

    _cooks = std::list<std::unique_ptr<Thread>>();
    for (int i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Thread>(&cookFunction, (void *) new CookArgs(i, std::make_unique<Semaphore>(0), std::make_unique<Stack<Plazza::APizza>>(), std::make_unique<Mutex>(), std::make_unique<MessageQueue>())));
    }
    int i = 0;
    while (i < Ingredient::INGREDIENTS) {
        _stock.insert(std::pair<Ingredient, int>((Ingredient)i, 5));
        i++;
    }
    _startCooking = std::make_unique<Mutex>();
    _orderQueue = std::make_unique<MessageQueue>();
    _finishedPizzasQueue = std::make_unique<MessageQueue>();
    _semPizzasToCook = std::make_unique<Semaphore>(2 * nbCooks);
    _stackPizzasToCook = std::make_unique<Stack<Plazza::APizza>>();
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
    std::cout << "Refill ingredients" << std::endl;
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
        //if not enough, wait
        //else, cook
    }
    return 0;
}
