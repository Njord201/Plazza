/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Reception
*/

#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Kitchen.hpp"
#include "Input.hpp"
#include "Order.hpp"
#include "SocketUnix/Server.hpp"

namespace Plazza {

    /**
     * @brief Reception class for the Plazza project.
     * Should be used to manage the reception of orders, send pizza
     * to Kitchens and give the order to the client.
     */
    class Reception;
}

class Plazza::Reception {

    public:

        /**
         * @brief Construct a new Reception object.
         *
         */
        Reception();

        /**
         * @brief Destroy the Reception object.
         *
         */
        ~Reception();

        /**
         * @brief Run the reception.
         *
         */
        void run();

    private:

        /**
         * @brief Create a Kitchen object.
         *
         */
        void createKitchen();

        /**
         * @brief Create a Order object.
         *
         */
        void createOrder();

        /**
         * @brief Close an order.
         *
         */
        void closeOrder();

        /**
         * @brief Assign a pizza to a kitchen.
         *
         */
        void assignPizzaToKitchen(int idKitchen, const Plazza::APizza &pizza);

        /**
         * @brief Get the state of the kitchens.
         *
         */
        void getStateKitchens();

        /**
         * @brief Sort the state of the kitchens.
         *
         */
        void sortStateKitchens();

        void status();

        std::vector<std::pair<int, int>>        _kitchens;      /** Lists of id and fd of Kitchens handle by the reception */
        std::vector<std::shared_ptr<Order>>     _orders;        /** Lists of the current order */
        std::unique_ptr<InputParser>                             _input;         /** Parser of the user input */
        std::vector<std::pair<int, int>>        _stateKitchens; /** State of the kitchens, <id, empty pizza slot> */
        std::unique_ptr<SocketU::Server>        _server;        /** Server to communicate with the client */
};
