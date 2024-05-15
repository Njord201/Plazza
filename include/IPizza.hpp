/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** IPizza.hpp
*/

#pragma once

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class IPizza {
public:
    virtual ~IPizza() = default;
    virtual void packPizza() = 0;
    virtual void cook() = 0;
};
