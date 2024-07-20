// bubble_sort.c

#include "push_swap.h"

void print_operation(const char *op) {
    printf("%s\\n", op);
}

void bubble_sort(t_stack *a, t_stack *b) {
    (void)b; // bスタックは使わないので無視します
    int len = stack_length(a);
    int swapped;

    if (len < 2)
        return;

    for (int i = 0; i < len - 1; i++) {
        swapped = 0;
        t_node *current = a->top;

        for (int j = 0; j < len - i - 1; j++) {
            if (current->value > current->next->value) {
                // 交換
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                print_operation("sa");
                swapped = 1;
            }
            current = current->next;
        }
        if (!swapped)
            break;
    }
    printf("\n");
}


