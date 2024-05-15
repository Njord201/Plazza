/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Stack.hpp
*/

#pragma once

#include <iostream>

template <typename T>
class Stack {
    public:
    Stack() : _size(0), _capacity(10), _stack(new T[_capacity]) {};
    ~Stack();
    void push(T value);
    T pop();
    T top();
    bool empty();
    int size();

    private:
    T *_stack;
    int _size;
    int _capacity;
};