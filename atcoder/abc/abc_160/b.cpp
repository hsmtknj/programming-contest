#include <bits/stdc++.h>

int main()
{
    long long X;
    std::cin >> X;

    long long ans = 0;
    while (true)
    {
        if (X - 500 >= 0)
        {
            ans += 1000;
            X -= 500;
        }
        else if (X - 5 >= 0)
        {
            ans += 5;
            X -= 5;
        }
        else
            break;
    }

    std::cout << ans << std::endl;
    return 0;
}