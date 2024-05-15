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
    Stack();
    ~Stack();
    void push(T value);
    T pop();
    T top();
    bool empty();
    int size();

private:
    int _size;
    int _capacity;
    T *_stack;
};
