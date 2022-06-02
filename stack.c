

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack init_stack_in_stack()
{
    struct stack new_stack = {.base = nullptr, .size = 0, .push_item = push_item, .pop_item = pop_item, .print_items = print_items};
    return new_stack;
}

struct stack *init_stack_in_heap()
{
    struct stack(*new_stack) = (struct stack(*))malloc(sizeof(struct stack));
    new_stack->base = nullptr;
    new_stack->size = 0;
    new_stack->push_item = push_item;
    new_stack->pop_item = pop_item;
    new_stack->print_items = print_items;
    return new_stack;
}

void push_item(struct stack(*stack_ptr), struct edge(*edge))
{
    struct node(*new_node) = (struct node(*))malloc(sizeof(struct node));
    new_node->edge = edge;
    new_node->next_node = nullptr;
    if (stack_ptr->size > 0)
        new_node->next_node = stack_ptr->base;
    stack_ptr->base = new_node;
    stack_ptr->size++;
}

struct wrapper pop_item(struct stack(*stack_ptr))
{
    struct wrapper ret;
    ret.none = 1;
    if (stack_ptr->size == 0)
        return ret;
    ret.e = stack_ptr->base->edge;
    if (ret.e == nullptr)
        return ret;
    ret.none = 0;
    struct node(*old_node) = stack_ptr->base;
    stack_ptr->base = stack_ptr->base->next_node;
    stack_ptr->size--;
    free(old_node);
    return ret;
}

void print_items(struct stack(*stack_ptr))
{
    if (stack_ptr->size == 0)
        return;
    printf("********\n");
    struct node(*node_iter) = stack_ptr->base;
    while (node_iter != nullptr)
    {
        printf("Value : %d -- Address : %p -- Next : %p \n", node_iter->edge->data, node_iter, node_iter->next_node);
        node_iter = node_iter->next_node;
    }
    printf("********\n");
}

bool find_value(struct stack(*stack_ptr), struct wrapper option, int target)
{
    if (option.none)
        return false;
    if (option.e->data == target)
        return true;

    int count = 0;
    while (count < option.e->size)
    {
        struct edge(*e) = option.e->links[count].to_edge;
        stack_ptr->push_item(stack_ptr, e);
        count++;
    }
    return find_value(stack_ptr, stack_ptr->pop_item(stack_ptr), target);
}