/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** MessageQueue.hpp
*/

#pragma once

#include <mqueue.h>
#include <cstring>

class MessageQueue {
    public:
    MessageQueue();
    ~MessageQueue();
    void sendMessage(const char *message);
    void receiveMessage(char *message);
    void *receiveMessage();
    void closeQueue();

    private:
    mqd_t _queue;
};