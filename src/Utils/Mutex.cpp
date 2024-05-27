/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** Mutex.cpp
*/

#include "Mutex.hpp"

Mutex::Mutex()
{
    pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{
    pthread_mutex_destroy(&_mutex);
}

void Mutex::lock()
{
    pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
    pthread_mutex_unlock(&_mutex);
}

void Mutex::trylock()
{
    pthread_mutex_trylock(&_mutex);
}
