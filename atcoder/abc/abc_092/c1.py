# -*- coding: utf-8 -*-
import numpy as np
N = input()
A = map(int, input().split())
A = list(A)

A = [0] + A + [0]
total_sum = 0
for i in range(0, len(A) - 1):
    total_sum += abs(A[i + 1] - A[i])

for i in range(1, len(A) - 1):
    partial_sum = total_sum - abs(A[i + 1] - A[i]) - abs(A[i] - A[i - 1]) + abs(A[i + 1] - A[i - 1])
    print(partial_sum)
