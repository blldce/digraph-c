#ifndef STACK_H
#define STACK_H 1

#include <stdbool.h>
#include "digraph.h"

#define nullptr (void(*))0

struct stack
{
    int size;
    struct node(*base);
    void (*push_item)(struct stack(*), struct edge(*));
    struct wrapper (*pop_item)(struct stack(*));
    void (*print_items)(struct stack(*));
};

struct node
{
    struct node(*next_node);
    struct edge(*edge);
};

extern struct stack init_stack_in_stack();
extern struct stack *init_stack_in_heap();

// member funcs
extern void push_item(struct stack(*), struct edge(*));
extern struct wrapper pop_item(struct stack(*));
extern void print_items(struct stack(*));

extern bool find_value(struct stack(*), struct wrapper, int);

#endif