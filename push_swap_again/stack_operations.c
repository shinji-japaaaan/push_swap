/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:05:33 by root              #+#    #+#             */
/*   Updated: 2024/07/22 06:41:34 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(t_stack *stack) {
    if (stack->top == NULL)
        return -1; // エラー値、もしくは適切なエラーハンドリングを追加
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

void swap(t_stack *stack) {
    if (stack->top && stack->top->next) {
        int temp = stack->top->value;
        stack->top->value = stack->top->next->value;
        stack->top->next->value = temp;
    }
}

void rotate(t_stack *stack) {
    if (stack->top && stack->top->next) {
        t_node *temp = stack->top;
        t_node *last = stack->top;
        while (last->next)
            last = last->next;
        stack->top = temp->next;
        temp->next = NULL;
        last->next = temp;
    }
}

void reverse_rotate(t_stack *stack) {
    if (stack->top && stack->top->next) {
        t_node *last = stack->top;
        t_node *second_last = NULL;
        while (last->next) {
            second_last = last;
            last = last->next;
        }
        if (second_last) {
            second_last->next = NULL;
            last->next = stack->top;
            stack->top = last;
        }
    }
}

void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void init_stack(t_stack *stack) {
    stack->top = NULL;
}

void free_stack(t_stack *stack) {
    while (stack->top) {
        pop(stack);
    }
}

void error_exit(void) {
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

void parse_input(int argc, char **argv, t_stack *a) {
    for (int i = 1; i < argc; i++) {
        long value = strtol(argv[i], NULL, 10);
        if (value < INT_MIN || value > INT_MAX) {
            error_exit();
        }
        if (is_duplicate(a, (int)value)) {
            error_exit();
        }
        push(a, (int)value);
    }
}

int is_duplicate(t_stack *stack, int value) {
    t_node *current = stack->top;
    while (current) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void execute_operation(const char *operation, t_stack *a, t_stack *b) {
    if (strcmp(operation, "sa") == 0) {
        swap(a);
    } else if (strcmp(operation, "sb") == 0) {
        swap(b);
    } else if (strcmp(operation, "ss") == 0) {
        swap(a);
        swap(b);
    } else if (strcmp(operation, "pa") == 0) {
        if (b->top) {
            int value = pop(b);
            push(a, value);
        }
    } else if (strcmp(operation, "pb") == 0) {
        if (a->top) {
            int value = pop(a);
            push(b, value);
        }
    } else if (strcmp(operation, "ra") == 0) {
        rotate(a);
    } else if (strcmp(operation, "rb") == 0) {
        rotate(b);
    } else if (strcmp(operation, "rr") == 0) {
        rotate(a);
        rotate(b);
    } else if (strcmp(operation, "rra") == 0) {
        reverse_rotate(a);
    } else if (strcmp(operation, "rrb") == 0) {
        reverse_rotate(b);
    } else if (strcmp(operation, "rrr") == 0) {
        reverse_rotate(a);
        reverse_rotate(b);
    }
}

void print_operation(const char *op) {
    printf("%s\n", op);
}


// スタックの長さを取得する関数
int stack_length(t_stack *stack) {
    int length = 0;
    t_node *current = stack->top;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}