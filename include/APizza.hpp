/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** APizza.hpp
*/

#pragma once

#include "IPizza.hpp"

class APizza : public IPizza {
public:
    APizza();
    ~APizza() = default;
    void packPizza() = 0;
    void cook() = 0;
};
