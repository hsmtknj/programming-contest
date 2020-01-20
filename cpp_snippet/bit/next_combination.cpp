#include <bits/stdc++.h>

int next_combination(int sub)
{
    int x = sub & -sub;
    int y = sub + x;
    return ((sub & ~y) / x) >> 1 | y;
}

int main ()
{
    /*
        nCk の組み合わせを全て列挙
            n = 5: {0, 1, 2, 3, 4}
            k = 3: {0, 1, 2}, {0, 1, 3}, ...
    */
    int n = 5;
    int k = 3;

    for (int bit = (1<<k)-1; bit < (1<<n); bit = next_combination(bit))
    {
        std::cout << std::bitset<5>(bit) << std::endl;
    }

    return 0;
}