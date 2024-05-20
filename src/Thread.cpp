/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** Thread.cpp
*/

#include "Thread.hpp"

Thread::Thread() {}

Thread::Thread(void *(*start_routine)(void *), void *arg)
{
    createThread(start_routine, arg);
}

Thread::~Thread()
{
    pthread_join(_thread, NULL);
}

void Thread::createThread(void *(*start_routine)(void *), void *arg)
{
    pthread_create(&_thread, NULL, start_routine, arg);
}

void Thread::joinThread()
{
    pthread_join(_thread, NULL);
}
