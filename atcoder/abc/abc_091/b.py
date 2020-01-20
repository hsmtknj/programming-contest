# coding: utf-8

b = []
r = []

# input
N = int(input())
for i in range(N):
    arg = input()
    b.append(arg)

M = int(input())
for i in range(M):
    arg = input()
    r.append(arg)

# solve
br = b + r
for i in range(len(br)):
    # initialize
    count_b = 0
    count_r = 0
    # target string
    s = br[i]
    # check blue cards
    for j in range(len(b)):
        if (b[j] == s):
            count_b += 1
    # check red cards
    for j in range(len(r)):
        if (r[j] == s):
            count_r += 1
    # check difference
    diff = count_b - count_r
    if (i == 0):
        X = diff
    elif (diff > X):
        X = diff
if (X < 0):
    X = 0

print(X)
