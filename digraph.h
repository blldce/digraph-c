#ifndef DIGRAPH_H
#define DIGRAPH_H 1

struct link
{
    char(*link_name);
    struct edge(*from_edge); // Its optional, used for debugging information to where this link come from.
    struct edge(*to_edge);
};

struct edge
{
    int data;
    int size;            // we dont want to use fixed size links, it can vary each node
    struct link links[]; // we dont want to use fixed size links, it can vary each node
};

struct wrapper
{
    struct edge(*e);
    char none;
};

#endif