#include "push_swap.h"

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

void error_exit(void) {
    fprintf(stderr, "Error\n");
    exit(EXIT_FAILURE);
}

void parse_input(int argc, char **argv, t_stack *a) {
    for (int i = 1; i < argc; i++) {
        long value = strtol(argv[i], NULL, 10);
        
        // 数値範囲チェック
        if (value < INT_MIN || value > INT_MAX) {
            error_exit();
        }
        
        // 重複チェック
        if (is_duplicate(a, (int)value)) {
            error_exit();
        }
        
        push(a, (int)value);
    }
}