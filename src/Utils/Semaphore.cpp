/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Semaphore.cpp
*/

#include "Semaphore.hpp"

Semaphore::Semaphore(int pshared, unsigned int value)
{
    sem_init(&_sem, pshared, value);
}

Semaphore::Semaphore(unsigned int value)
{
    sem_init(&_sem, 0, value);
}

Semaphore::Semaphore()
{
    sem_init(&_sem, 0, 0);
}

Semaphore::~Semaphore()
{
    sem_destroy(&_sem);
}

void Semaphore::wait()
{
    sem_wait(&_sem);
}

void Semaphore::post()
{
    sem_post(&_sem);
}

void Semaphore::post(int value)
{
    for (int i = 0; i < value; i++)
        sem_post(&_sem);
}

void Semaphore::trywait()
{
    sem_trywait(&_sem);
}

int Semaphore::getvalue()
{
    int value;
    sem_getvalue(&_sem, &value);
    return value;
}

sem_t *Semaphore::getsem()
{
    return &_sem;
}

void Semaphore::setsem(sem_t sem)
{
    _sem = sem;
}

void Semaphore::setvalue(int value)
{
    sem_init(&_sem, 0, value);
}
