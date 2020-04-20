#include <bits/stdc++.h>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int even = 0;
    int odd = 0;

    if (N <= 1)
        even = 0;
    else
        even = N * (N - 1) / 2;

    if (M <= 1)    
        odd = 0;
    else
        odd = M * (M - 1) / 2;

    std::cout << even + odd << std::endl;

    return 0;
}