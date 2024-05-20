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
    /**
     * @brief Constructs a Timer object.
     */
    Timer();

    /**
     * @brief Destructs the Timer object.
     */
    ~Timer() = default;

    /**
     * @brief Resets the start time of the Timer.
     */
    void reset();

    /**
     * @brief Calculates the elapsed time in seconds since the Timer was started.
     * @return The elapsed time in seconds.
     */
    double elapsedSeconds() const;

private:
    std::chrono::steady_clock::time_point startTime;
};