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
    /**
     * @brief Constructs a Mutex object.
     */
    Mutex();

    /**
     * @brief Destroys the Mutex object.
     */
    ~Mutex();

    /**
     * @brief Locks the mutex.
     */
    void lock();

    /**
     * @brief Unlocks the mutex.
     */
    void unlock();

    /**
     * @brief Tries to lock the mutex.
     */
    void trylock();

private:
    pthread_mutex_t _mutex;
};