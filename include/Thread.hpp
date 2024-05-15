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
    Thread();
    Thread(void *(*start_routine)(void *), void *arg);
    ~Thread();
    void createThread(void *(*start_routine)(void *), void *arg);
    void joinThread();

    private:
    pthread_t _thread;
};