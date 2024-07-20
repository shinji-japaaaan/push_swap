// push_swap.h

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>


// ノードの構造体
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// スタックの構造体
typedef struct s_stack {
    t_node *top;
} t_stack;

// スタック操作関数のプロトタイプ
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);
void print_stack(t_stack *stack);
void bubble_sort(t_stack *a, t_stack *b);
void parse_input(int argc, char **argv, t_stack *a);
void quick_sort(t_stack *stack, int low, int high);

#endif
