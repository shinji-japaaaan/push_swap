#!/bin/bash

# 100 個のランダムな整数を生成
ARG=$(seq 1 500 | shuf)

# push_swap を実行して操作回数をカウント
OP_COUNT=$(echo "$ARG" | xargs ./push_swap | wc -l)

# 操作回数を表示
echo "Operations count: $OP_COUNT"

