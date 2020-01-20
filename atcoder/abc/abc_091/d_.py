# coding: utf-8

# input
N = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

# solve(TLE)
"""
flag = 1
for i in range(N):
    for j in range(N):
        if (flag == 1):
            num = a[i] + b[j]
            flag = 0
        else:
            num = num ^ (a[i] + b[j])
print(num)
"""

"""
Don't use double for
"""
