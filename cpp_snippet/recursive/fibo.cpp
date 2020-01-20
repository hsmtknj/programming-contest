#include <bits/stdc++.h>

int cnt = 0;

int fibo(int n)
{
    cnt++;

    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    int ans = fibo(6);
    std::cout << "ans: " << ans << std::endl;
    std::cout << "cnt: " << cnt << std::endl;

    return 0;
}