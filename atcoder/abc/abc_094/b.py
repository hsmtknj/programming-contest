# -*- coding: utf-8 -*-

# input
N, M, X = map(int, input().split())
A = list(map(int, input().split()))

# solve
right = 0
left = 0

for i in range(len(A)):
    if (A[i] > X):
        right += 1
    if (A[i] < X):
        left += 1

if (right < left):
    print(right)
else:
    print(left)
