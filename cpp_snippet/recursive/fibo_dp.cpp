#include <bits/stdc++.h>

const int N_MAX = pow(10, 5);
std::vector<int> memo(N_MAX, -1);
int cnt = 0;

int fibo(int n)
{
    cnt++;

    // ベースケース
    if (n == 0) return memo[n] = 0;
    else if (n == 1) return memo[n] = 1;

    // メモチェック
    if (memo[n] != -1) return memo[n];

    return memo[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
    int ans = fibo(6);
    std::cout << "ans: " << ans << std::endl;
    std::cout << "cnt: " << cnt << std::endl;

    return 0;
}