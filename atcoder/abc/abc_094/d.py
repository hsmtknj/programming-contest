# -*- coding: utf-8 -*-

# input
N = int(input())
A = list(map(int, input().split()))


# solve
def comb(n, r):
    if n < 0 or r < 0 or n < r:
        return 0
    elif n == 0 or r == 0:
        return 1
    return comb(n-1, r-1) + comb(n-1, r)

# def comb(n, r):
#     if n == 0 or r == 0: return 1
#     return comb(n, r-1) * (n-r+1) / r


A = sorted(A)[::-1]
max_num = 0
for i in range(len(A)-1):
    for j in range(i+1, len(A), 1):
        if (max_num <= comb(A[i], A[j])):
            max_num = comb(A[i], A[j])
            pair = []
            pair.append(A[i])
            pair.append(A[j])

print(pair[0], pair[1])
