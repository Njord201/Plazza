/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Timer.hpp
*/

#pragma once
#include <chrono>

class Timer {
public:
    Timer();
    ~Timer() = default;
    void reset();
    double elapsedSeconds() const;
private:
    std::chrono::steady_clock::time_point startTime;
};