/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** IPizza.hpp
*/

#pragma once

/**
 * @enum PizzaType
 * @brief Enumeration representing the types of pizza.
 */
enum PizzaType
{
    Regina = 1, /**< Regina pizza */
    Margarita = 2, /**< Margarita pizza */
    Americana = 4, /**< Americana pizza */
    Fantasia = 8 /**< Fantasia pizza */
};

/**
 * @enum PizzaSize
 * @brief Enumeration representing the sizes of pizza.
 */
enum PizzaSize
{
    S = 1, /**< Small size */
    M = 2, /**< Medium size */
    L = 4, /**< Large size */
    XL = 8, /**< Extra large size */
    XXL = 16 /**< Double extra large size */
};

/**
 * @class IPizza
 * @brief Interface for a pizza.
 */
class IPizza {
public:
    /**
     * @brief Virtual destructor for IPizza.
     */
    virtual ~IPizza() = default;

    /**
     * @brief Packs the pizza.
     */
    virtual void packPizza() = 0;

    /**
     * @brief Cooks the pizza.
     */
    virtual void cook() = 0;
};
