/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** APizza.hpp
*/

#pragma once

#include "IPizza.hpp"
#include "Ingredient.hpp"
#include <vector>
#include <string>
#include <iostream>

class APizza : public IPizza {
public:
    APizza();
    APizza(PizzaType type, PizzaSize size, std::vector<Ingredient> ingredients, int cookingTime);
    ~APizza() = default;
    void packPizza() = 0;
    void cook() = 0;

    PizzaType getType() const;
    PizzaSize getSize() const;
    std::vector<Ingredient> getIngredients() const;
    int getCookingTime() const;
private:
    PizzaType _type;
    PizzaSize _size;
    std::vector<Ingredient> _ingredients;
    int _cookingTime;
};
