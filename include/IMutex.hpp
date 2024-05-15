/*
** EPITECH PROJECT, 2024
** bsPlazza
** File description:
** IMutex.hpp
*/

#pragma once

class IMutex {
    public:
    virtual ~IMutex() = default;
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual void trylock() = 0;
};