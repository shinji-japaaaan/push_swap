/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:06:10 by root              #+#    #+#             */
/*   Updated: 2024/07/22 06:42:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 簡単なソートアルゴリズム
void sort_stack(t_stack *a, t_stack *b) {
    int size = stack_length(a);
    int sorted = 0;

    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < size - 1; i++) {
            if (a->top->value > a->top->next->value) {
                execute_operation("sa", a, b);
                print_operation("sa");
                sorted = 0;
            }
            execute_operation("ra", a, b);
            print_operation("ra");
        }
        for (int i = 0; i < size - 1; i++) {
            execute_operation("rra", a, b);
            print_operation("rra");
        }
    }
}




