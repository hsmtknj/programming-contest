# -*- coding: utf-8 -*-
import bisect

# input
S = input()
# S = "abcdefghijklmnopqrstuvwzyx"
# S = "atcoder"
# S = "qpwoeirutyalskdjfhgzmxnvcb"

s = list(S)
a = []
for i in range(len(s)):
    a.append(ord(s[i]))

t = [chr(i) for i in range(97, 97+26)]
b = [i for i in range(97, 97+26)]


# function
def func(s_):
    ss_ = []
    for i in range(len(s_)):
        ss_.append(chr(s_[i]))
    ss_ = ''.join(ss_)
    return ss_


# solve
if (len(s) < 26):
    for i in range(len(s)):
        b.remove(a[i])
    a.append(min(b))
    print(func(a))

if (len(s) == 26):
    for i in reversed(range(len(s))):
        if (a[i] < a[i-1]):
            if (i == 1):
                print(-1)
                break
            else:
                continue
        else:
            c = a[0:i]
            d = a[i:len(a)]
            d = sorted(d)
            # a[i-1]よりも大きくて最も小さいものをa[i]-a[len(a)]から探す
            num = c.pop()  # a[i-1]
            ind = bisect.bisect_left(d, num)
            c.append(d[ind])
            print(func(c))
            break
