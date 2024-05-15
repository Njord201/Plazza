/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** IKitchen.hpp
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
    Kitchen(int nbCooks, int restockTime);
    ~Kitchen();
    void restock();
    void *cookFunction(void *arg);
    //getters and setters
    //internal functions
    //communication functions
private:
    std::list<Thread> cooks;
    Mutex startCooking;
    MessageQueue orderQueue;
    MessageQueue finishedPizzasQueue;
    Semaphore pizzasToCook;
    Stack<IPizza> pizzasToCook;

    std::unordered_map<Ingredient, int> stock;
    int totalPizzas;
    int cooksOccupied; //shared memory? -> Socket UNIX?
    bool saturated; //shared memory? -> Socket UNIX?

    Timer totalTime;
    Timer idleTime;
}
