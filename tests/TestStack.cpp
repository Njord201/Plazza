/*
** EPITECH PROJECT, 2024
** Plazza
** File description:
** TestStack.cpp
*/

#include <criterion/criterion.h>
#include "Stack.hpp"

Test(stack_test, initial_empty) {
    Stack<int> stack;
    cr_assert(stack.empty(), "Stack should be initialised empty");
}

Test(stack_test, push_size) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    cr_assert_eq(stack.size(), 2, "Stack size should be 2");
}

Test(stack_test, push_pop_top) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    cr_assert_eq(stack.top(), 20, "Top element should be 20 after pushing 10 and 20");
    stack.pop();
    cr_assert_eq(stack.top(), 10, "Top element should be 10 after popping");
}
