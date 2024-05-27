/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Reception
*/

#include "Reception.hpp"
#include "SocketUnix/Server.hpp"

#include <algorithm>
#include <unistd.h>

Plazza::Reception::Reception()
{
    _input = std::make_unique<Plazza::InputParser>();
    _server = std::make_unique<SocketU::Server>();
    _kitchens = std::vector<std::pair<int, int>>();
    _stateKitchens = std::vector<std::pair<int, int>>();
}

Plazza::Reception::~Reception()
{
    for (auto &kitchen : _kitchens) {
        close(kitchen.second);
    }
}

void Plazza::Reception::status()
{
    // TODO
    for (const auto &kitchen : _kitchens) {
        std::cout << "Kitchen " << kitchen.first << ": " << "..." << std::endl;
    }
}

void Plazza::Reception::run()
{
    bool kitchenAnswer = false;

    while (true) {
        FD_ZERO(&_server->_readfds);
        FD_SET(0, &_server->_readfds);
        for (const auto &kitchen : _kitchens) {
            FD_SET(kitchen.second, &_server->_readfds);
        }
        _server->selectRead();
        std::vector<Plazza::Pizza> pizzas;
        try {
            if (FD_ISSET(0, &_server->_readfds))
                pizzas = _input->parseLine();
            for (const auto &kitchen : _kitchens) {
                if (FD_ISSET(kitchen.second, &_server->_readfds)) {
                    // A an order gestion system
                    // std::string state = server->receive(kitchen.second);
                    // std::cout << "Kitchen " << kitchen.first << ": " << state << std::endl;
                    kitchenAnswer = true;
                }
            }
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
            continue;
        }
        if (pizzas.empty() && !kitchenAnswer) {
            status();
        }
        for (const auto &pizza : pizzas) {
            std::cout << "In for loop\n";
            this->getStateKitchens();
            this->sortStateKitchens();
            if (this->_stateKitchens.empty())
                this->createKitchen();
            // if (this->_stateKitchens[0].second == 0)
            //     this->createKitchen();
            // this->assignPizzaToKitchen(0, pizza);
            (void) pizza;
            std::cout << "Pizza assigned\n";
        }
        kitchenAnswer = false;
    }
}

void Plazza::Reception::createKitchen()
{
    // auto kitchen = std::make_shared<Kitchen>(2, 5, 1);

    // int fd = fork();

    // if (fd == 0) {
    //     // kitchen->loop();
    //     close(fd);
    // } else {
    //     auto pair = std::make_pair(kitchen->getId(), fd);
    //     _kitchens.push_back(pair);
    // }
}

void Plazza::Reception::createOrder()
{
    // auto order = std::make_shared<Order>();
}

void Plazza::Reception::closeOrder()
{

}

void Plazza::Reception::assignPizzaToKitchen(int idKitchen, const Plazza::Pizza &pizza)
{
    FD_ZERO(&_server->_writefds);
    FD_SET(_kitchens[idKitchen].second, &_server->_writefds);
    _server->selectWrite();
    _server->send(pizza.getInfos(), _kitchens[idKitchen].second);
}

void Plazza::Reception::getStateKitchens()
{
    for (auto &kitchen : _kitchens) {
        FD_ZERO(&_server->_writefds);
        FD_SET(getpid(), &_server->_readfds);
        _server->selectRead();
        // std::string state = _server.receive(getpid());
        int id = kitchen.first;
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
