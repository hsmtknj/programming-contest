import numpy as np

N = input()
p_list = list(map(int, input().split()))
p = np.array(p_list)


print(p[0:3])
print(type(p[0]))

data = np.arange(10)
print(np.where(data%2 == 0))