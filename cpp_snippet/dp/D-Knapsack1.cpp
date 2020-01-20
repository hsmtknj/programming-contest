#include <bits/stdc++.h>

int main()
{
    // 入力 (1-based indexing)
    long long N;
    long long W;
    std::cin >> N >> W;
    std::vector<long long> w(N+1, 0);
    std::vector<long long> v(N+1, 0);
    for (int i = 0; i < N; i++) std::cin >> w[i+1] >> v[i+1];

    // 問題を解く
    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(W+1, 0));

    // i = 0 のアイテムを選択していないときは既に 0 で初期化されているので飛ばす
    for (int i = 1; i <= N; i++)
    {
        // 各アイテムに対して部分和毎に計算
        for (int sum_w = 0; sum_w <= W; sum_w++)
        {
            // 選ぶとき（部分和が足りるときのみ）
            if (sum_w - w[i] >= 0) dp[i][sum_w] = std::max(dp[i][sum_w], dp[i-1][sum_w - w[i]] + v[i]);
            // 選ばないとき
            dp[i][sum_w] = std::max(dp[i][sum_w], dp[i-1][sum_w]);
        }
    }

    long long ans = dp[N][W];
    std::cout << ans << std::endl;

    return 0;
}