/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** ScopedLock.cpp
*/

#include "ScopedLock.hpp"

ScopedLock::ScopedLock(IMutex &mutex) : _mutex(mutex)
{
    _mutex.lock();
}

ScopedLock::~ScopedLock()
{
    _mutex.unlock();
}