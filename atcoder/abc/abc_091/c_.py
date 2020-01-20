# coding: utf-8

red = []
blue = []

# input
N = int(input())
# red
for i in range(N):
    a, b = map(int, input().split())
    red.append([a, b])
# blue
for i in range(N):
    c, d = map(int, input().split())
    blue.append([c, d])

# solve(WA)
"""
count = 0
for i in range(N):
    for j in range(N):
        # check x and y
        if (red[i][0] < blue[i][0] and red[j][1] < blue[j][1]):
            count += 1

print(count)
"""
