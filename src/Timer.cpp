/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

Timer::Timer()
{
    startTime = std::chrono::steady_clock::now();
}

void Timer::reset()
{
    startTime = std::chrono::steady_clock::now();
}

double Timer::elapsedSeconds() const
{
    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedTime = endTime - startTime;
    return elapsedTime.count();

}
