import numpy as np

N = input()
p_list = list(map(int, input().split()))
p = np.array(p_list)

cnt = 0
for i in range(len(p)):
    p_where = np.where(p > p[i], 1, 0)
    total = sum(p_where[0:i])
    
    if (total == i):
        cnt += 1

print(cnt)
