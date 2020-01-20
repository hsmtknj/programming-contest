# coding: utf-8

N = 3
a = [2, 7, 4]

# solve
sum_alice = 0
sum_bob = 0
for i in range(N):
    if (i%2 == 0):
        sum_alice += max(a)
        del(a[a.index(max(a))])
    else:
        sum_bob += max(a)
        del(a[a.index(max(a))])

print(sum_alice - sum_bob)

"""
use sort()
"""
