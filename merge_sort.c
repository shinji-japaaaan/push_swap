#include "push_swap.h"

static t_node *find_middle(t_node *head) {
    if (!head) return NULL;

    t_node *slow = head;
    t_node *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void split_stack(t_stack *stack, t_stack *left, t_stack *right) {
    t_node *middle = find_middle(stack->top);
    if (!middle || !middle->next) {
        left->top = stack->top;
        right->top = NULL;
        return;
    }

    left->top = stack->top;
    right->top = middle->next;
    middle->next = NULL;
}

static void merge(t_stack *stack, t_node *left, t_node *right) {
    t_node dummy;
    t_node *current = &dummy;
    dummy.next = NULL;

    while (left && right) {
        if (left->value <= right->value) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left) {
        current->next = left;
    } else {
        current->next = right;
    }

    stack->top = dummy.next;
}

static void merge_sort_stack(t_stack *stack) {
    if (!stack->top || !stack->top->next) {
        return;
    }

    t_stack left;
    t_stack right;
    split_stack(stack, &left, &right);

    merge_sort_stack(&left);
    merge_sort_stack(&right);

    merge(stack, left.top, right.top);
}

void merge_sort(t_stack *stack) {
    merge_sort_stack(stack);
}

