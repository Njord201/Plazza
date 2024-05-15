/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** Stack.hpp
*/

#pragma once

#include <iostream>

/**
 * @brief A generic stack data structure implementation.
 *
 * @tparam T The type of elements stored in the stack.
 */
template <typename T>
class Stack {
public:
    /**
     * @brief Constructs an empty stack.
     */
    Stack();

    /**
     * @brief Destroys the stack and frees the memory.
     */
    ~Stack();

    /**
     * @brief Pushes a value onto the top of the stack.
     *
     * @param value The value to be pushed onto the stack.
     */
    void push(T value);

    /**
     * @brief Removes and returns the top element of the stack.
     *
     * @return The top element of the stack.
     */
    T pop();

    /**
     * @brief Returns the top element of the stack without removing it.
     *
     * @return The top element of the stack.
     */
    T top();

    /**
     * @brief Checks if the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     */
    bool empty();

    /**
     * @brief Returns the number of elements in the stack.
     *
     * @return The number of elements in the stack.
     */
    int size();

private:
    int _size; /**< The number of elements in the stack. */
    int _capacity; /**< The maximum capacity of the stack. */
    T *_stack; /**< The array to store the elements of the stack. */
};
