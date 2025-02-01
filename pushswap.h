
#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int num;
    int binid;
    struct node *next;

} t_node;
// typedef struct stack
// {
//     t_node *a;
//     t_node *b;
// } t_stack;

// void swap(node *x);
// void ss(node *x, node *y);
// void push(node *x, node *y);
// void rotate(node *x);
// void rr(node *x, node *y);
// void revrotate(node *x);
// void rrr(node *x, node *y);


t_node* makeNode(int data);
void append(t_node** head, int data);
void push(t_node** fromList, t_node** toList);
void printList(t_node* head);
void freeList(t_node* head);
void control(int ac, char **av);
int *stacka;
int *stackb;
int *SortedList;
int len;

#endif