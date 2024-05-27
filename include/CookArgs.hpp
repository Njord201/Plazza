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
#include "Kitchen.hpp"

class CookArgs {
public:
    CookArgs(int id, Kitchen *kitchen)
        : _id(id), _kitchen(kitchen) {}
    ~CookArgs() = default;

    int getId() const { return _id; }
    Kitchen *getKitchen() const { return _kitchen; }

private:
    int _id;
    Kitchen *_kitchen;
};
