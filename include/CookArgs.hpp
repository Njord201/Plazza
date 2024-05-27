/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** CookArgs.hpp
*/

#pragma once

#include <memory>
#include "Semaphore.hpp"
#include "Stack.hpp"
#include "APizza.hpp"
#include "Mutex.hpp"
#include "MessageQueue.hpp"

class CookArgs {
public:
    CookArgs(int id, std::shared_ptr<Semaphore> sem, std::shared_ptr<Stack<Plazza::APizza>> stack, std::shared_ptr<Mutex> mutex, std::shared_ptr<MessageQueue> finishedPizzasQueue)
        : _id{id}, _sem{sem}, _stack{stack}, _mutex{mutex}, _finishedPizzasQueue{finishedPizzasQueue} {}
    ~CookArgs() = default;

    //getters

    int getId() const { return _id; }
    Semaphore *getSem() const { return _sem.get(); }
    Stack<Plazza::APizza> *getStack() const { return _stack.get(); }
    Mutex *getMutex() const { return _mutex.get(); }
    MessageQueue *getFinishedPizzasQueue() const { return _finishedPizzasQueue.get(); }

private:
    int _id;
    std::shared_ptr<Semaphore> _sem;
    std::shared_ptr<Stack<Plazza::APizza>> _stack;
    std::shared_ptr<Mutex> _mutex;
    std::shared_ptr<MessageQueue> _finishedPizzasQueue;
};