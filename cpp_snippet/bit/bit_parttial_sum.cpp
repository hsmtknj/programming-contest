#include <bits/stdc++.h>

int main ()
{
    int n = 14;
    std::vector<int> v = {2, 5, 7, 9};

    // bit全探索で全部分和を求める
    for (int bit = 0; bit < (1<<v.size()); bit++)
    {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            // 1が立っているところだけ足す
            if (bit & (1<<i))
            {
                sum += v[i];
            }
        }

        std::cout << std::bitset<4>(bit) << ": " << sum << std::endl;
        std::cout << std::endl;
    }

    return 0;
}