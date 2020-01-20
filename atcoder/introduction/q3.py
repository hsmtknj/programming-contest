# coding: utf-8

N = 3
A = [16, 12, 24]

# solve
count_sub = 0
count = 0
flag = 0
while(flag == 0):
    count_sub = 0
    for i in range(len(A)):
        if (A[i] % 2 == 0):
            A[i] = A[i]/2
            count_sub += 1
        else:
            flag = 1
            break
    if (count_sub == N):
        count += 1

print(count)