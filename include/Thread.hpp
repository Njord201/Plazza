/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** Thread.hpp
*/

#pragma once

#include <pthread.h>

class Thread {
public:
    /**
     * @brief Default constructor for Thread class.
     */
    Thread();

    /**
     * @brief Constructor for Thread class.
     * @param start_routine The function to be executed by the thread.
     * @param arg The argument to be passed to the start_routine function.
     */
    Thread(void *(*start_routine)(void *), void *arg);

    /**
     * @brief Destructor for Thread class.
     */
    ~Thread();

    /**
     * @brief Creates a new thread.
     * @param start_routine The function to be executed by the thread.
     * @param arg The argument to be passed to the start_routine function.
     */
    void createThread(void *(*start_routine)(void *), void *arg);

    /**
     * @brief Waits for the thread to terminate.
     */
    void joinThread();

private:
    pthread_t _thread;
};