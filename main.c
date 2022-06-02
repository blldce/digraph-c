

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct stack my_stack = init_stack_in_stack();

    // edges initialization
    struct edge *D = (struct edge(*))malloc(sizeof(struct edge));
    D->size = 0;
    D->data = 10;

    struct edge *G = (struct edge(*))malloc(sizeof(struct edge));
    G->size = 0;
    G->data = 100;

    struct edge *F = (struct edge(*))malloc(sizeof(struct edge));
    F->size = 0;
    F->data = 23;

    struct edge *C = (struct edge(*))malloc(sizeof(struct edge) + sizeof(struct link));
    C->size = 1;
    C->data = 20;

    struct edge *B = (struct edge(*))malloc(sizeof(struct edge) + sizeof(struct link) * 2);
    B->size = 2;
    B->data = 30;

    struct edge *A = (struct edge(*))malloc(sizeof(struct edge) + sizeof(struct link) * 3);
    A->size = 3;
    A->data = 40;

    // links initialization
    struct link c_to_d = {.from_edge = C, .to_edge = D, .link_name = "c to d link"};
    struct link b_to_g = {.from_edge = B, .to_edge = G, .link_name = "b to g link"};
    struct link b_to_c = {.from_edge = B, .to_edge = C, .link_name = "b to c link"};
    struct link a_to_c = {.from_edge = A, .to_edge = C, .link_name = "a to c link"};
    struct link a_to_b = {.from_edge = A, .to_edge = B, .link_name = "a to b link"};
    struct link a_to_f = {.from_edge = A, .to_edge = F, .link_name = "a to f link"};

    // linking
    C->links[0] = c_to_d;

    B->links[0] = b_to_c;
    B->links[1] = b_to_g;

    A->links[0] = a_to_c;
    A->links[1] = a_to_b;
    A->links[2] = a_to_f;

    struct wrapper start_edge = {.e = A, .none = 0};
    bool res = find_value(&my_stack, start_edge, 23);
    printf("Res : %d \n", res);
    res = find_value(&my_stack, start_edge, 21);
    printf("Res : %d \n", res);
    return 0;
}