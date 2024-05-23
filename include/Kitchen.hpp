/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include <list>
#include <memory>
#include <unordered_map>
#include "Mutex.hpp"
#include "Thread.hpp"
#include "Timer.hpp"
#include "Ingredient.hpp"
#include "Semaphore.hpp"
#include "MessageQueue.hpp"
#include "Stack.hpp"
#include "APizza.hpp"

class Kitchen {
public:
    /**
     * @brief Constructs a Kitchen object.
     *
     * @param nbCooks The number of cooks in the kitchen.
     * @param restockTime The time interval for restocking ingredients.
     * @param id The ID of the kitchen.
     */
    Kitchen(int nbCooks, int restockTime, int id);

    /**
     * @brief Destroys the Kitchen object.
     */
    ~Kitchen();

    /**
     * @brief Restocks the ingredients in the kitchen by one unit.
     */
    void restock();

    //getters and setters

    //internal functions

    void loop();

    //communication functions

private:
    std::list<std::unique_ptr<Thread>> _cooks; /**< The list of cook threads. */
    std::unique_ptr<Mutex> _startCooking; /**< The mutex for synchronizing cook threads. */
    std::unique_ptr<MessageQueue> _orderQueue; /**< The message queue for receiving orders. */
    std::unique_ptr<MessageQueue> _finishedPizzasQueue; /**< The message queue for sending finished pizzas. */
    std::unique_ptr<Semaphore> _semPizzasToCook; /**< The semaphore for tracking pizzas to cook. */
    std::unique_ptr<Stack<APizza>> _stackPizzasToCook; /**< The stack of pizzas to cook. */

    std::unordered_map<Ingredient, int> _stock; /**< The map of ingredient stock. */
    int _totalPizzas; /**< The total number of pizzas cooked. */
    int _cooksOccupied; /**< The number of cooks currently occupied. */ //shared memory? -> Socket UNIX?
    bool _saturated; /**< Indicates if the kitchen is saturated. */ //shared memory? -> Socket UNIX?

    int _restockTime; /**< The time interval for restocking ingredients. */
    int _id; /**< The ID of the kitchen. */

    std::unique_ptr<Timer> _refillTime; /**< The timer for tracking refill time. */
    std::unique_ptr<Timer> _idleTime; /**< The timer for tracking idle time. */
};
