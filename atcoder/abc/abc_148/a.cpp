#include <bits/stdc++.h>

int main()
{
    int A;
    int B;
    std::cin >> A;
    std::cin >> B;

    for (int i = 1; i <= 3; i++)
    {
        if (i == A | i == B)
        {
            continue;
        }
        else std::cout << i << std::endl;
    }
    return 0;
}