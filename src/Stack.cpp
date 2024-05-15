/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Stack.cpp
*/

#include "Stack.hpp"

Stack::~Stack()
{
    while (!_stack.empty()) {
        _stack.pop();
    }
}

template <typename T>
void Stack<T>::push(T value)
{
    _stack.push(value);
}

template <typename T>
T Stack<T>::pop()
{
    T value = _stack.top();
    _stack.pop();
    return value;
}

template <typename T>
T Stack<T>::top()
{
    return _stack.top();
}

template <typename T>
bool Stack<T>::empty()
{
    return _stack.empty();
}

template <typename T>
int Stack<T>::size()
{
    return _stack.size();
}
