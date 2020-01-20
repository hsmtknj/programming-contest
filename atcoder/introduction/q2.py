# coding: utf-8

# input
s = "101001"

# count "1"
count = 0
for i in range(len(s)):
    if (int(s[i]) == 1):
        count += 1
print(count)