/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"

static void *cookFunction(void *arg)
{
    return arg;
}

Kitchen::Kitchen(int nbCooks, int restockTime, int id)
{
    _id = id;
    _restockTime = restockTime;

    _cooks = std::list<std::unique_ptr<Thread>>();
    for (int i = 0; i < nbCooks; i++) {
        _cooks.push_back(std::make_unique<Thread>(&cookFunction, nullptr));
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
    _stackPizzasToCook = std::make_unique<Stack<APizza>>();
    _totalPizzas = 0;
    _cooksOccupied = 0;
    _saturated = false;
    _refillTime = std::make_unique<Timer>();
    _idleTime = std::make_unique<Timer>();
}

Kitchen::~Kitchen()
{

}

void Kitchen::restock()
{
    for (auto &ingredient : _stock) {
        ingredient.second += 1;
    }
}

/*void Kitchen::loop()
{
    //timers
    if (_refillTime->getElapsedTime() > _restockTime) {
        restock();
        _refillTime->reset();
    }
    //get si quelque chose dans la msg queue
}*/
