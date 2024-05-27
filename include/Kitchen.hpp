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
#include "SocketUnix/Client.hpp"

class Kitchen : public std::enable_shared_from_this<Kitchen> {
public:
    /**
     * @brief Constructs a Kitchen object.
     *
     * @param nbCooks The number of cooks in the kitchen.
     * @param restockTime The time interval for restocking ingredients.
     * @param id The ID of the kitchen.
     */
    Kitchen(int nbCooks, long restockTime, int id);

    /**
     * @brief Destroys the Kitchen object.
     */
    ~Kitchen();

    /**
     * @brief Restocks the ingredients in the kitchen by one unit.
     */
    void restock();

    // Getters and setters
    std::shared_ptr<MessageQueue> &getOrderQueue() { return _orderQueue; }
    std::shared_ptr<MessageQueue> &getFinishedPizzasQueue() { return _finishedPizzasQueue; }
    std::shared_ptr<Stack<Plazza::APizza>> &getStackPizzasToCook() { return _stackPizzasToCook; }
    std::shared_ptr<Mutex> &getStartCooking() { return _startCooking; }
    std::unordered_map<Ingredient, int> &getStock() { return _stock; }
    int getTotalPizzas() const { return _totalPizzas; }
    int getCooksOccupied() const { return _cooksOccupied; }
    bool isSaturated() const { return _saturated; }
    long getRestockTime() const { return _restockTime; }
    int getId() const { return _id; }
    bool isRunning() const { return _running; }

    // Internal functions
    /**
     * @brief The main loop of the kitchen.
     * @return 1 if the kitchen needs to be killed, 0 otherwise.
     */
    int loop();

private:
    std::list<std::unique_ptr<Thread>> _cooks; /**< The list of cook threads. */
    std::shared_ptr<Mutex> _startCooking; /**< The mutex for synchronizing cook threads. */
    std::shared_ptr<MessageQueue> _orderQueue; /**< The message queue for receiving orders. */
    std::shared_ptr<MessageQueue> _finishedPizzasQueue; /**< The message queue for sending finished pizzas. */
    std::shared_ptr<Stack<Plazza::APizza>> _stackPizzasToCook; /**< The stack of pizzas to cook. */

    std::unordered_map<Ingredient, int> _stock; /**< The map of ingredient stock. */
    int _totalPizzas; /**< The total number of pizzas cooked. */
    int _cooksOccupied; /**< The number of cooks currently occupied. */
    bool _saturated; /**< Indicates if the kitchen is saturated. */

    long _restockTime; /**< The time interval for restocking ingredients in milliseconds. */
    int _id; /**< The ID of the kitchen. */
    bool _running; /**< Indicates if the kitchen is running. */

    std::unique_ptr<Timer> _refillTime; /**< The timer for tracking refill time. */
    std::unique_ptr<Timer> _idleTime; /**< The timer for tracking idle time. */

    SocketU::Client _client; /**< The client socket for communication with the reception. */
};
