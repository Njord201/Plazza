/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Pizza
*/

#pragma once

namespace Plazza {

    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    /**
     * @brief Pizza class for the Plazza project.
     *
     */
    class Pizza;
}

class Plazza::Pizza {
    public:

        /**
         * @brief Construct a new Pizza object.
         *
         * @param type Type of the pizza.
         * @param size Size of the pizza.
         */
        Pizza(Plazza::PizzaType type, Plazza::PizzaSize size);

        /**
         * @brief Destroy the Pizza object.
         *
         */
        ~Pizza() = default;

    private:

        Plazza::PizzaType _type;
        Plazza::PizzaSize _size;
};
