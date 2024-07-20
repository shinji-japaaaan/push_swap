// quick_sort.c

#include "push_swap.h"

// スタックの中の値を配列にコピー
void stack_to_array(t_stack *stack, int arr[]) {
    t_node *current = stack->top;
    int i = 0;
    while (current) {
        arr[i++] = current->value;
        current = current->next;
    }
}

// 配列をスタックにコピー
void array_to_stack(int arr[], int len, t_stack *stack) {
    for (int i = len - 1; i >= 0; i--) {
        push(stack, arr[i]);
    }
}

// スワップ関数
void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// パーティション関数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// クイックソートのメイン関数
void quick_sort_array(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort_array(arr, low, pi - 1);
        quick_sort_array(arr, pi + 1, high);
    }
}

// スタックをクリアする関数
void clear_stack(t_stack *stack) {
    while (stack->top) {
        pop(stack);
    }
}

// スタックをクイックソートする関数
void quick_sort(t_stack *stack) {
    int len = stack_length(stack);
    if (len <= 1) return;

    int *arr = (int *)malloc(len * sizeof(int));
    if (!arr) return;

    stack_to_array(stack, arr);
    quick_sort_array(arr, 0, len - 1);

    // スタックをクリアしてソートされた配列をプッシュ
    clear_stack(stack);
    array_to_stack(arr, len, stack);

    free(arr);
}



