/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Semaphore.hpp
*/

#pragma once

#include <semaphore.h>
#include <time.h>
#include <iostream>

class Semaphore {
public:
    Semaphore(int pshared, unsigned int value);
    Semaphore(unsigned int value);
    ~Semaphore();
    void wait();
    void post();
    void trywait();
    int getvalue();
    sem_t *getsem();
    void setsem(sem_t sem);
    void setvalue(int value);

private:
    sem_t _sem;
};
