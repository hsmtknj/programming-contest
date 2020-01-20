#include <bits/stdc++.h>

int rec(std::vector<int> &h, std::vector<int> &dp, int i)
{
    // ベースケース
    if (i == 0) return dp[i] = 0;  // メモを取りながら返す

    // メモチェック
    if (dp[i] < INT_MAX) return dp[i];

    // 再帰関数
    if (i == 1) return dp[i] = (rec(h, dp, i-1) + abs(h[i] - h[i-1]));  // メモを取りながら返す
    if (i > 1)
    {
        int num1 = rec(h, dp, i-1) + abs(h[i] - h[i-1]);
        int num2 = rec(h, dp, i-2) + abs(h[i] - h[i-2]);
        return dp[i] = std::min(num1, num2);  // メモを取りながら返す
    }
    return 0;
}

int main()
{
    // 入力
    int N;
    std::cin >> N;
    std::vector<int> h(N);
    for (int i = 0; i < N; i++) std::cin >> h[i];
    
    // 問題を解く
    std::vector<int> dp(N, INT_MAX);
    int ans = rec(h, dp, N-1);

    // 出力
    std::cout << ans << std::endl;
    return 0;
}
