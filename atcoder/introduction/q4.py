# coding: utf-8

A = 2  # 500yen
B = 2  # 100yen
C = 2  # 50yen
X = 100

mat = []

# brute-force search
count = 0
for a in range(0, A+1):
    for b in range(0, B+1):
        for c in range(0, C+1):
            if (500 * a + 100 * b + 50 * c == X):
                count += 1
                mat.append([a, b, c])
print(count)
print(mat)
