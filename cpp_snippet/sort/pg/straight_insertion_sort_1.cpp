#include <bits/stdc++.h>

void sort(std::vector<int> &v)
{
    int ind = 0;
    for (int i = 1; i < v.size(); i++)
    {
        // 挿入したい値を保持
        int tgt_num = v[i];

        // 自分より前で適切な挿入位置を決定する
        int j;  // 挿入位置
        for (j = i; j > 0; j--)
        {
            if (v[j-1] > tgt_num) v[j] = v[j-1];
            else break;
        }
        v[j] = tgt_num;
    }
}

int main()
{
    std::vector<int> v = {30, 88, 20, 17, 25};
    sort(v);
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}