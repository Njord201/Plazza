/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** ScopedLock.hpp
*/

#pragma once

#include "IMutex.hpp"

class ScopedLock {
    public:
    ScopedLock(IMutex &mutex);
    ~ScopedLock();

    private:
    IMutex &_mutex;
};