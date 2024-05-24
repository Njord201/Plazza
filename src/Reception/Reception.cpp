/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Reception
*/

#include "Reception.hpp"

#include <algorithm>

Plazza::Reception::Reception()
{
}

Plazza::Reception::~Reception()
{
}

void Plazza::Reception::run()
{
    while (true) {
        std::vector<Plazza::Pizza> pizzas;
        try {
            pizzas = _input.parseLine();
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        for (const auto &pizza : pizzas) {
            this->getStateKitchens();
            this->sortStateKitchens();
            if (this->_stateKitchens.empty())
                this->createKitchen();
            if (this->_stateKitchens[0].second == 0)
                this->createKitchen();
            this->assignPizzaToKitchen(0);
        }
    }
}

void Plazza::Reception::createKitchen()
{
    auto kitchen = std::make_shared<Kitchen>(2, 5, 1);
}

void Plazza::Reception::createOrder()
{
    auto order = std::make_shared<Order>();
}

void Plazza::Reception::closeOrder()
{

}

void Plazza::Reception::assignPizzaToKitchen(int idKitchen)
{
    // TODO
}

void Plazza::Reception::getStateKitchens()
{
    for (auto &kitchen : _kitchens) {
        int id = kitchen->getId();
        // std::string state = kitchen->getState();
        std::string state = "2";
        int pizzaSlot = stoi(state);

        auto pair = std::make_pair(id, pizzaSlot);
        _stateKitchens.push_back(pair);
    }
}

void Plazza::Reception::sortStateKitchens()
{
    std::sort(_stateKitchens.begin(), _stateKitchens.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
        return a.second < b.second;
    });
}
