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

/**
 * @class APizza
 * @brief Abstract base class for pizza objects.
 */
class APizza : public IPizza {
public:
    /**
     * @brief Default constructor for APizza.
     */
    APizza();

    /**
     * @brief Constructor for APizza.
     * @param type The type of the pizza.
     * @param size The size of the pizza.
     * @param ingredients The ingredients of the pizza.
     * @param cookingTime The cooking time of the pizza.
     */
    APizza(PizzaType type, PizzaSize size, std::vector<Ingredient> ingredients, int cookingTime);

    /**
     * @brief Default destructor for APizza.
     */
    ~APizza() = default;

    /**
     * @brief Packs the pizza.
     * @note Pure virtual function, must be implemented by derived classes.
     */
    void packPizza() = 0;

    /**
     * @brief Cooks the pizza.
     * @note Pure virtual function, must be implemented by derived classes.
     */
    void cook() = 0;

    /**
     * @brief Gets the type of the pizza.
     * @return The type of the pizza.
     */
    PizzaType getType() const;

    /**
     * @brief Gets the size of the pizza.
     * @return The size of the pizza.
     */
    PizzaSize getSize() const;

    /**
     * @brief Gets the ingredients of the pizza.
     * @return The ingredients of the pizza.
     */
    std::vector<Ingredient> getIngredients() const;

    /**
     * @brief Gets the cooking time of the pizza.
     * @return The cooking time of the pizza.
     */
    int getCookingTime() const;

private:
    PizzaType _type; /**< The type of the pizza. */
    PizzaSize _size; /**< The size of the pizza. */
    std::vector<Ingredient> _ingredients; /**< The ingredients of the pizza. */
    int _cookingTime; /**< The cooking time of the pizza. */
};
