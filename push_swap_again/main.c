/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:04:34 by root              #+#    #+#             */
/*   Updated: 2024/07/22 06:36:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// メイン関数
#include "push_swap.h"

int main(int argc, char **argv) {
    t_stack a;
    t_stack b;

    // スタックの初期化
    init_stack(&a);
    init_stack(&b);

    // 入力のパース
    if (argc < 2) {
        write(2, "Error\n", 6);
        return 1;
    }

    parse_input(argc, argv, &a);

    // スタックをソート
    sort_stack(&a, &b);

    // 必要なクリーンアップ
    free_stack(&a);
    free_stack(&b);

    return 0;
}


