/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 13:05:59 by root              #+#    #+#             */
/*   Updated: 2024/07/21 14:39:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// スタックの中の値を配列にコピー
void stack_to_array(t_stack *stack, int arr[]) {
    t_node *current = stack->top;
    int i = 0;
    while (current) {
        arr[i++] = current->value;
        current = current->next;
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
    while (stack->top) {
        pop(stack);
    }
    // 配列をスタックにコピー
    for (int i = len - 1; i >= 0; i--) {
        push(stack, arr[i]);
    }
    free(arr);
}





