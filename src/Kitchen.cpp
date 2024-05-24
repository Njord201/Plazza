/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"

Kitchen::Kitchen(int nbCooks, int restockTime, int id)
{
    _id = id;
    _restockTime = restockTime;

    for (int i = 0; i < nbCooks; i++) {
        _cooks.push_back(new Cook());
    }
    int i = 0;
    while (i < Ingredient::NULL) {
        _stock.insert(std::pair<Ingredient, int>((Ingredient)i, 5));
        i++;
    }
    _startCooking = new Mutex();
    _orderQueue = new MessageQueue();
    _finishedPizzasQueue = new MessageQueue();
    _semPizzasToCook = new Semaphore(2 * nbCooks);
    _stackPizzasToCook = new Stack<IPizza>();
    _totalPizzas = 0;
    _cooksOccupied = 0;
    _saturated = false;
    _totalTime = new Timer();
    _idleTime = new Timer();
}

Kitchen::~Kitchen()
{
    delete _startCooking;
    delete _orderQueue;
    delete _finishedPizzasQueue;
    delete _semPizzasToCook;
    delete _stackPizzasToCook;
    for (auto cook : _cooks) {
        delete cook;
    }
}

void Kitchen::restock()
{
    for (auto &ingredient : _stock) {
        ingredient.second += 1;
    }
}

void *Kitchen::cookFunction(void *arg)
{
    //TO DO
}

int Kitchen::getId() const
{
    return _id;
}
