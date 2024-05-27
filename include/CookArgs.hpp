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

class CookArgs {
public:
    CookArgs(int id, std::unique_ptr<Semaphore> sem, std::unique_ptr<Stack<APizza>> stack, std::unique_ptr<Mutex> mutex)
        : _id(id), _sem(std::move(sem)), _stack(std::move(stack)), _mutex(std::move(mutex)) {}
    ~CookArgs() = default;

    //getters

    int getId() const { return _id; }
    Semaphore *getSem() const { return _sem.get(); }
    Stack<APizza> *getStack() const { return _stack.get(); }
    Mutex *getMutex() const { return _mutex.get(); }

private:
    int _id;
    std::unique_ptr<Semaphore> _sem;
    std::unique_ptr<Stack<APizza>> _stack;
    std::unique_ptr<Mutex> _mutex;
};