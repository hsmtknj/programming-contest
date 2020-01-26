#include <bits/stdc++.h>

int main()
{
    long long H;
    std::cin >> H;

    long long cnt = 0;
    long long num = 1;
    while (H > 0)
    {
        H = H / 2;
        cnt += num;
        num *= 2;
    }

    std::cout << cnt << std::endl;
    return 0;
}