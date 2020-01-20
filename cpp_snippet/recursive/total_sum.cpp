#include <bits/stdc++.h>

int total_sum(int n)
{
    if (n == 0) return 0;
    return n + total_sum(n-1);
}

int main()
{
    int ans = total_sum(10);
    std::cout << ans << std::endl;
    return 0;
}