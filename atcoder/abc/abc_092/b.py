# coding: utf-8


# input
N = int(input())
(D, X) = map(int, input().split())
A = []
for i in range(N):
    A.append(int(input()))


# solve
t = 0
for i in range(N):
    j = 0
    while (True):
        if (1+j*A[i] <= D):
            t += 1
            j += 1
        else:
            break

print(t+X)
