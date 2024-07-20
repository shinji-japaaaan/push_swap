// main.c

#include "push_swap.h"

void init_stack(t_stack *stack) {
    stack->top = NULL;
}

void free_stack(t_stack *stack) {
    while (stack->top) {
        pop(stack);
    }
}

int main(int argc, char **argv) {
    t_stack a;
    t_stack b;

    // スタックの初期化
    init_stack(&a);
    init_stack(&b);

    // 入力のパース
    if (argc < 2) {
        write(2, "Error: No arguments provided\\n", 29);
        return 1;
    }

    parse_input(argc, argv, &a);

    // ソート前のスタックを表示
    printf("Initial stack:\n");
    print_stack(&a);

    // Quick Sort を実行
    quick_sort(&a);

    // ソート後のスタックを表示
    printf("Sorted stack:\n");
    print_stack(&a);

    // 必要なクリーンアップ
    free_stack(&a);
    free_stack(&b);

    return 0;
}
