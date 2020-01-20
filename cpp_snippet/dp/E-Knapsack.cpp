// どこかミス

#include <bits/stdc++.h>

int main()
{
    // 入力（1-based indexing）
    int N;
    int N_MAX = 100;
    int V_MAX = pow(10, 3);
    long long W;
    std::cin >> N >> W;
    std::vector<long long> w(N+1, 0);
    std::vector<long long> v(N+1, 0);
    for (int i = 1; i <= N; i++) std::cin >> w[i] >> v[i];

    // 問題を解く
    // dp[i][sum_v]: iまでの品物の中で，sum_v にするときの最小の w
    std::vector<std::vector<long long>> dp(N_MAX+1, std::vector<long long>(V_MAX+1, LLONG_MAX));
    // for (int i = 0; i <= V_MAX; i++) dp[0][i] = 0;
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int sum_v = 0; sum_v <= V_MAX; sum_v++)
        {
            // 選ぶとき
            if (sum_v - v[i] >= 0) dp[i][sum_v] = std::min(dp[i][sum_v], dp[i-1][sum_v-v[i]] + w[i]);

            // 選ばないとき
            dp[i][sum_v] = std::min(dp[i][sum_v], dp[i-1][sum_v]);
        }
    }

    int ans = 0;
    for (int sum_v = 0; sum_v < dp[N].size(); sum_v++)
    {
        if (dp[N][sum_v] <= W) ans = sum_v;
    }
    std::cout << ans << std::endl;
    return 0;
}