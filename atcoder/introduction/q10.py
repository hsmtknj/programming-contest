# coding: utf-8

N = 2
p = [[3, 1, 2], [6, 1, 1]]

for i in range(N):
    # compute manhattan distance and traveling time
    if (i == 0):
        md = abs(p[i][1]) + abs(p[i][2])
        tt = p[i][0]
    else:
        md = abs(p[i][1] - p[i-1][1]) + abs(p[i][2] - p[i-1][2])
        tt = p[i][0] - p[i-1][0]

    # check
    if (md > tt):
        print("No")
        break
    elif ((tt - md) % 2 == 0):
        # return "Yes" if mission complete
        if (i == N-1):
            print("Yes")
        else:
            continue
    else:
        print("No")
        break
