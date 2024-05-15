/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** APizza.cpp
*/

#include "APizza.hpp"

APizza::APizza() {
    _type = Regina;
    _size = S;
    _cookingTime = 1;
}

APizza::APizza(PizzaType type, PizzaSize size, std::vector<Ingredient> ingredients, int cookingTime)
{
    _type = type;
    _size = size;
    _ingredients = ingredients;
    _cookingTime = cookingTime;
}

PizzaType APizza::getType() const
{
    return _type;
}

PizzaSize APizza::getSize() const
{
    return _size;
}

int APizza::getCookingTime() const
{
    return _cookingTime;
}

std::vector<Ingredient> APizza::getIngredients() const
{
    return _ingredients;
}

void APizza::packPizza()
{
    std::cout << "Packing pizza..." << std::endl;
}

void APizza::cook()
{
    std::cout << "Cooking pizza..." << std::endl;
}
