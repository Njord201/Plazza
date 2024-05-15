/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Semaphore.hpp
*/

#pragma once

#include <semaphore.h>

class Semaphore {
public:
    Semaphore(int pshared, unsigned int value);
    ~Semaphore();
    void wait();
    void post();
    void trywait();
    void timedwait(const struct timespec *restrict abstime);
    int getvalue();
    sem_t *getsem();
    void setsem(sem_t sem);
    void setvalue(int value);

private:
    sem_t _sem;
};
