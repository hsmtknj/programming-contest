# coding: utf-8


# input
A = int(input())
B = int(input())
C = int(input())
D = int(input())


# solve
s = 0

if (A < B):
    s += A
else:
    s += B

if (C < D):
    s += C
else:
    s += D

print(s)
