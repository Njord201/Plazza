/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Pizza
*/

#include "Pizza.hpp"

Plazza::Pizza::Pizza(Plazza::PizzaType type, Plazza::PizzaSize size)
    : _type(type), _size(size)
{
}

std::string Plazza::Pizza::getInfos() const
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