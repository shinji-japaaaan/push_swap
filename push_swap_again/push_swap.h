/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:08:05 by root              #+#    #+#             */
/*   Updated: 2024/07/22 06:43:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

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
void init_stack(t_stack *stack);
void free_stack(t_stack *stack);
void parse_input(int argc, char **argv, t_stack *a);
int is_duplicate(t_stack *stack, int value);
void sort_stack(t_stack *a, t_stack *b);
void execute_operation(const char *operation, t_stack *a, t_stack *b);
void print_operation(const char *op);
void error_exit(void);
int stack_length(t_stack *stack);

#endif

