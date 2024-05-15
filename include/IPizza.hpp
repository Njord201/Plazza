/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** IPizza.hpp
*/

#pragma once

class IPizza {
public:
    virtual ~IPizza() = default;
    virtual void packPizza() = 0;
    virtual void cook() = 0;
};
