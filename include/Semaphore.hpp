/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Semaphore.hpp
*/

#pragma once

#include <semaphore.h>
#include <time.h>
#include <iostream>

/**
 * @class Semaphore
 * @brief A class that represents a semaphore.
 */
class Semaphore {
public:
    /**
     * @brief Constructs a Semaphore object.
     * @param pshared The pshared argument indicates whether this semaphore is shared between processes or between threads.
     * @param value The initial value of the semaphore.
     */
    Semaphore(int pshared, unsigned int value);

    /**
     * @brief Constructs a Semaphore object.
     * @param value The initial value of the semaphore.
     */
    Semaphore(unsigned int value);

    /**
     * @brief Constructs a Semaphore object.
     */
    Semaphore();

    /**
     * @brief Destructs the Semaphore object.
     */
    ~Semaphore();

    /**
     * @brief Waits until the semaphore value is greater than zero, then decrements the value by one.
     */
    void wait();

    /**
     * @brief Increments the semaphore value by one.
     */
    void post();

    /**
     * @brief Tries to decrement the semaphore value by one.
     * @return 0 if the decrement was successful, -1 otherwise.
     */
    void trywait();

    /**
     * @brief Gets the current value of the semaphore.
     * @return The current value of the semaphore.
     */
    int getvalue();

    /**
     * @brief Gets the underlying semaphore object.
     * @return A pointer to the underlying semaphore object.
     */
    sem_t *getsem();

    /**
     * @brief Sets the underlying semaphore object.
     * @param sem The semaphore object to set.
     */
    void setsem(sem_t sem);

    /**
     * @brief Sets the value of the semaphore.
     * @param value The value to set.
     */
    void setvalue(int value);

private:
    sem_t _sem; /**< The underlying semaphore object. */
};
