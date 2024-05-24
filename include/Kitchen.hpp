/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include <list>
#include <unordered_map>
#include "Mutex.hpp"
#include "Thread.hpp"
#include "Timer.hpp"
#include "Ingredient.hpp"
#include "Semaphore.hpp"
#include "MessageQueue.hpp"
#include "Stack.hpp"
#include "IPizza.hpp"

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

    /**
     * @brief The function executed by each cook thread.
     *
     * @param arg The argument passed to the cook thread.
     * @return void* The return value of the cook thread.
     */
    void *cookFunction(void *arg);

    /**
     * @brief Get the id of the object.
     *
     * @return int
     */
    int getId() const;

    //getters and setters

    //internal functions

    //communication functions

private:
    std::list<Thread> _cooks; /**< The list of cook threads. */
    Mutex _startCooking; /**< The mutex for synchronizing cook threads. */
    MessageQueue _orderQueue; /**< The message queue for receiving orders. */
    MessageQueue _finishedPizzasQueue; /**< The message queue for sending finished pizzas. */
    Semaphore _semPizzasToCook; /**< The semaphore for tracking pizzas to cook. */
    Stack<IPizza> _stackPizzasToCook; /**< The stack of pizzas to cook. */

    std::unordered_map<Ingredient, int> _stock; /**< The map of ingredient stock. */
    int _totalPizzas; /**< The total number of pizzas cooked. */
    int _cooksOccupied; /**< The number of cooks currently occupied. */ //shared memory? -> Socket UNIX?
    bool _saturated; /**< Indicates if the kitchen is saturated. */ //shared memory? -> Socket UNIX?

    int _restockTime; /**< The time interval for restocking ingredients. */
    int _id; /**< The ID of the kitchen. */

    Timer _totalTime; /**< The timer for tracking total cooking time (used to refill the stocks). */
    Timer _idleTime; /**< The timer for tracking idle time. */
};
