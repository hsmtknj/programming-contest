/*
    ビット全探索で「0 - 4」までの部分集合を全部出してみる
*/

#include <bits/stdc++.h>

int main ()
{
    int n = 5;

    for (int bit = 0; bit < (1<<n); bit++)
    {
        std::vector<int> v;
        // ビットの1が立っているところを加える
        for (int i = 0; i < n; i++)
        {
            if (bit & (1<<i))
            {
                v.push_back(i);
            }
        }

        // 表示
        std::cout << std::bitset<5>(bit) << ": ";
        for (int i = 0; i < v.size(); i++) std::cout <<v[i] << " ";
        std::cout << std::endl;
    }
    return 0;
}