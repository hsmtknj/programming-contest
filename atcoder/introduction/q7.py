# coding: utf-8

N = 4
d = [8, 10, 8, 6]

# initialize a dictionary
dic = {}

for i in range(len(d)):
    num = str(d[i])
    if (str(d[i]) in dic):
        # if a dictionary has the number, add one
        dic[str(d[i])] += 1
    else:
        # if a dictionary doesn't have the number, register the number
        dic[str(d[i])] = 1

print(dic)
print(len(dic))


"""
バケット法
    num[i] := 値 i が何個あるか
連想法
    pythonの場合，dictionary
    c++の場合，std::map, std::set

メモリの効率上，連想法の法が良い
"""
