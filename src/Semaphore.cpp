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

void Semaphore::trywait()
{
    sem_trywait(&_sem);
}

void Semaphore::timedwait(const struct timespec *restrict abstime)
{
    sem_timedwait(&_sem, abstime);
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
