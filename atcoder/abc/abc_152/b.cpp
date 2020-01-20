#include <bits/stdc++.h>

int main()
{
    int a, b;
    std::cin >> a >> b;

    int num_a = 0;
    int num_b = 0;
    for (int i = 0; i < b; i++)
    {
        num_a *= 10;
        num_a += a;
    }
    for (int i = 0; i < a; i++)
    {
        num_b *= 10;
        num_b += b;
    }

    if (a < b)
        std::cout << num_a << std::endl;
    else
        std::cout << num_b << std::endl;

    return 0;
}