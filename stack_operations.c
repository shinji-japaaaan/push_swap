// stack_operations.c

#include "push_swap.h"

// スタックに値をプッシュする関数
void push(t_stack *stack, int value) {
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

// スタックから値をポップする関数
int pop(t_stack *stack) {
    if (stack->top == NULL)
        return -1; // エラー値、もしくは適切なエラーハンドリングを追加
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

// スタックの上部の2つの要素を交換する関数
void swap(t_stack *stack) {
    if (stack->top && stack->top->next) {
        int temp = stack->top->value;
        stack->top->value = stack->top->next->value;
        stack->top->next->value = temp;
    }
}

// スタックの全要素を1つ上にシフトする関数
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

// スタックの全要素を1つ下にシフトする関数
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

// スタックの内容を表示する関数（デバッグ用）
void print_stack(t_stack *stack) {
    t_node *current = stack->top;
    while (current) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int stack_length(t_stack *stack) {
    int length = 0;
    t_node *current = stack->top;
    while (current) {
        length++;
        current = current->next;
    }
    return length;
}
