# -*- coding:utf-8 -*-

# input
N = int(input())
X = list(map(int, input().split()))

# solve
X_sorted = sorted(X)
n0 = X_sorted[int(len(X_sorted)/2-1)]
n1 = X_sorted[int(len(X_sorted)/2)]
for i in range(len(X)):
    if (n1 > X[i]):
        print(n1)
    elif (n0 <= X[i]):
        print(n0)
