#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;

    int ans;
    if (N % 2 == 0)
        ans = N / 2;
    else
        ans = N / 2 + 1;

    std::cout << ans << std::endl;
}