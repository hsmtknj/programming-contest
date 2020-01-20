# coding: utf-8

N = 9
Y = 45000

for a in range(0, N+1):
    for b in range(0, N+1-a):
        c = N - a - b
        total = 10000 * a + 5000 * b + 1000 * c
        if (total == Y):
            print(a, b, c)

"""
1秒間で処理できるfor文ループの回数: 10^8程度
"""
