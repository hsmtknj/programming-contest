# coding: utf-8

N = 20
A = 2
B = 5

# solve
sum = 0
for i in range(N+1):
    # compute summantion of each digit
    sum_tmp = 0
    for j in range(len(str(i))):
        sum_tmp += int(str(i)[j])
    # see if constraing is satisfied or not
    if (sum_tmp >= A and sum_tmp <= B):
        sum += i

print(sum)


"""
There is another way to use "%10"

decimal system (10進法): %10
binary system (2進法): %2
"""
