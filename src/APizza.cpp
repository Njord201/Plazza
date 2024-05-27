/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** APizza.cpp
*/

#include "APizza.hpp"

Plazza::APizza::APizza() {
    _type = Regina;
    _size = S;
    _cookingTime = 2;
    _ingredients = {Ingredient::DOUGH, Ingredient::TOMATO, Ingredient::GRUYERE, Ingredient::HAM, Ingredient::MUSHROOMS};
}

Plazza::APizza::APizza(Plazza::PizzaType type, Plazza::PizzaSize size, std::vector<Ingredient> ingredients, int cookingTime)
{
    _type = type;
    _size = size;
    _ingredients = ingredients;
    _cookingTime = cookingTime;
}

Plazza::PizzaType Plazza::APizza::getType() const
{
    return _type;
}

Plazza::PizzaSize Plazza::APizza::getSize() const
{
    return _size;
}

int Plazza::APizza::getCookingTime() const
{
    return _cookingTime;
}

std::vector<Ingredient> Plazza::APizza::getIngredients() const
{
    return _ingredients;
}

bool Plazza::APizza::packPizza(std::unordered_map<Ingredient, int> &stock)
{
    std::cout << "Packing pizza..." << std::endl;
    for (auto &ingredient : _ingredients) {
        if (stock[ingredient] == 0) {
            return false;
        }
    }
    for (auto &ingredient : _ingredients) {
        stock[ingredient] -= 1;
    }
    return true;
}

void Plazza::APizza::cook()
{
    sleep(_cookingTime);
}

std::string Plazza::APizza::getInfos() const
{
    std::string type;
    std::string size;

    switch (_type) {
        case Plazza::PizzaType::Regina:
            type = "Regina";
            break;
        case Plazza::PizzaType::Margarita:
            type = "Margarita";
            break;
        case Plazza::PizzaType::Americana:
            type = "Americana";
            break;
        case Plazza::PizzaType::Fantasia:
            type = "Fantasia";
            break;
    }
    switch (_size) {
        case Plazza::PizzaSize::S:
            size = "S";
            break;
        case Plazza::PizzaSize::M:
            size = "M";
            break;
        case Plazza::PizzaSize::L:
            size = "L";
            break;
        case Plazza::PizzaSize::XL:
            size = "XL";
            break;
        case Plazza::PizzaSize::XXL:
            size = "XXL";
            break;
    }
    return type + " " + size;
}
