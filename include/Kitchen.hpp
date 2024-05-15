/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include <list>
#include <unordered_map>
#include "Mutex.hpp"
#include "Thread.hpp"
#include "Timer.hpp"
#include "Ingredient.hpp"
#include "Semaphore.hpp"
#include "MessageQueue.hpp"
#include "Stack.hpp"
#include "IPizza.hpp"

class Kitchen {
public:
    Kitchen(int nbCooks, int restockTime, int id);
    ~Kitchen();
    void restock();
    void *cookFunction(void *arg);
    //getters and setters
    //internal functions
    //communication functions
private:
    std::list<Thread> _cooks;
    Mutex _startCooking;
    MessageQueue _orderQueue;
    MessageQueue _finishedPizzasQueue;
    Semaphore _semPizzasToCook;
    Stack<IPizza> _stackPizzasToCook;

    std::unordered_map<Ingredient, int> _stock;
    int _totalPizzas;
    int _cooksOccupied; //shared memory? -> Socket UNIX?
    bool _saturated; //shared memory? -> Socket UNIX?

    int _restockTime;
    int _id;

    Timer _totalTime;
    Timer _idleTime;
}
