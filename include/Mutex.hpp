/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** Mutex.hpp
*/

#pragma once

#include "IMutex.hpp"
#include <pthread.h>

class Mutex : public IMutex {
    public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();
    void trylock();

    private:
    pthread_mutex_t _mutex;
};