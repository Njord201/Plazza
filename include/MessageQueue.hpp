/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** MessageQueue.hpp
*/

#pragma once

#include <mqueue.h>
#include <cstring>

/**
 * @class MessageQueue
 * @brief Represents a message queue for inter-process communication.
 */
class MessageQueue {
    public:
    /**
     * @brief Default constructor.
     */
    MessageQueue();

    /**
     * @brief Destructor.
     */
    ~MessageQueue();

    /**
     * @brief Sends a message to the message queue.
     * @param message The message to be sent.
     */
    void sendMessage(const char *message);

    /**
     * @brief Receives a message from the message queue.
     * @param message The buffer to store the received message.
     */
    void receiveMessage(char *message);

    /**
     * @brief Receives a message from the message queue.
     * @return A pointer to the received message.
     */
    void *receiveMessage();

    /**
     * @brief Closes the message queue.
     */
    void closeQueue();

    private:
    mqd_t _queue; /**< The message queue descriptor. */
};