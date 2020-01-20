# coding: utf-8

S = "dreameraser"
t = ["dream", "dreamer", "erase", "eraser"]

# solve
# reverse string
S = S[::-1]
for i in range(len(t)):
    t[i] = t[i][::-1]

# indexが文字列長を越えると終了
i = 0
while (i < len(S)):
    print(i)
    if (S[i:i+5] == t[0] or S[i:i+5] == t[2]):
        i = i + 5
    elif (S[i:i+6] == t[3]):
        i = i + 6
    elif (S[i:i+7] == t[1]):
        i = i + 7
    else:
        break

if (i == len(S)):
    print("Yes")

"""
後ろから解く（曖昧性がなく，文字列が一意に決まり区切れる）
"dream" "dreamer" のような一意に決まらない関係を prefix という
"""
