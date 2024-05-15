/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** IMutex.hpp
*/

#pragma once

/**
 * @class IMutex
 * @brief Interface for a mutex object.
 *
 * This interface defines the basic operations that a mutex object should provide.
 */
class IMutex {
    public:
    /**
     * @brief Destructor for IMutex.
     */
    virtual ~IMutex() = default;

    /**
     * @brief Locks the mutex.
     */
    virtual void lock() = 0;

    /**
     * @brief Unlocks the mutex.
     */
    virtual void unlock() = 0;

    /**
     * @brief Tries to lock the mutex.
     * @return True if the lock was acquired, false otherwise.
     */
    virtual void trylock() = 0;
};