/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Stack.cpp
*/

#include "Stack.hpp"
#include "APizza.hpp"

template <typename T>
Stack<T>::Stack() : _size(0), _capacity(10), _stack(new T[_capacity]) {}

template <typename T>
Stack<T>::~Stack() {
    delete[] _stack;
}

template <typename T>
void Stack<T>::push(T value) {
    _stack[_size++] = value;
}

template <typename T>
T Stack<T>::pop() {
    if (_size <= 0) {
        throw std::underflow_error("Stack is empty");
    }
    return _stack[--_size];
}

template <typename T>
T Stack<T>::top() {
    if (_size <= 0) {
        throw std::underflow_error("Stack is empty");
    }
    return _stack[_size - 1];
}

template <typename T>
bool Stack<T>::empty() {
    return _size == 0;
}

template <typename T>
int Stack<T>::size() {
    return _size;
}

template class Stack<int>;
template class Stack<APizza>;
