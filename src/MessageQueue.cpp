/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** MessageQueue.cpp
*/

#include "MessageQueue.hpp"

MessageQueue::MessageQueue()
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 8192;
    attr.mq_curmsgs = 0;
    _queue = mq_open("/plazza", O_CREAT | O_RDWR, 0644, &attr);
}

MessageQueue::~MessageQueue()
{
    closeQueue();
}

void MessageQueue::sendMessage(const char *message)
{
    mq_send(_queue, message, strlen(message), 0);
}

void MessageQueue::receiveMessage(char *message)
{
    mq_receive(_queue, message, 8192, 0);
}

void *MessageQueue::receiveMessage()
{
    char *message = new char[8192];
    mq_receive(_queue, message, 8192, 0);
    return message;
}

void MessageQueue::closeQueue()
{
    mq_close(_queue);
}