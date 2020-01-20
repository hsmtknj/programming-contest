#include <bits/stdc++.h>

void sort(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int tgt_num = v[i];
        
        // 自分より前で挿入位置を見つける
        int j;
        for (j = i; j > 0; j--)
        {
            if (v[j-1] > tgt_num)
            {
                v[j] = v[j-1];
            }
            else
            {
                break;
            }
        }
        v[j] = tgt_num;
    }
}

int main()
{
    std::vector<int> v = {30, 88, 25, 17, 20, 3, 1};
    sort(v);
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}