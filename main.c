// main.c

#include "push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        write(2, "Error: No arguments provided\\n", 29);
        return 1;
    }

    t_stack a = {NULL};
    t_stack b = {NULL};

    parse_input(argc, argv, &a);

    // ソート前のスタックを表示
    write(1, "Initial stack:\n", 15);
    print_stack(&a);

    // バブルソートを実行
    bubble_sort(&a, &b);

    // ソート後のスタックを表示
    write(1, "Sorted stack:\n", 14);
    print_stack(&a);

    return 0;
}

