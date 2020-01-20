# coding: utf-8


# input
# N = int(input())
# A = map(int, input().split())
# A = list(A)

# N = 3
# A = [3, 5, -1]

N = 6
A = [-679, -2409, -3258, 3095, -3291, -4462]

dic = {}

# # solve
# for i in range(N):
#     t = 0
#     B = list(A)
#     B.pop(i)
#     j = 0
#     while (True):
#         # 最初
#         if (j == 0):
#             t += abs(B[j])
#             j += 1
#         # 最後
#         elif (j == len(B)):
#             t += abs(B[j-1])
#             break
#         else:
#             t += abs(B[j] - B[j-1])
#             j += 1
#     print(t)


# function
def search(m, l):
    global dic

    # 過去に計算したことがある
    if (str(l) in dic):
        return m + dic[str(l)]
    # 過去に計算したことがない
    elif (len(l) == 1):
        return m + abs(l[0])
    elif (len(l) > 1):
        # m_ = m + abs(l[1] - l[0])
        # l.pop(0)
        # search(m_, list(l))
        # 計算して登録
        j = 1
        t = 0
        while (True):
            if (j == len(B)):
                t += abs(B[j-1])
                break
            else:
                t += abs(B[j] - B[j-1])
                j += 1
        # 辞書に登録
        dic[str(l)] = m + t
        return m + t


# solve
for i in range(N):
    t = 0
    B = list(A)
    B.pop(i)
    t = search(abs(B[0]), list(B))
    print(t)
