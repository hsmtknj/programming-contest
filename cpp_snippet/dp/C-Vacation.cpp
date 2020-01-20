#include <bits/stdc++.h>

int N_MAX = pow(10, 5);
int N;
std::vector<int> a;
std::vector<int> b;
std::vector<int> c;

// i日目で
//  - 最後にAを選んだ最大値を memo[i][0]
//  - 最後にBを選んだ最大値を memo[i][1]
//  - 最後にCを選んだ最大値を memo[i][2]
// とする
std::vector<std::vector<int>> dp(N_MAX + 1, std::vector<int>(3, -1));

int main()
{
    // 入力
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a_in, b_in, c_in;
        std::cin >> a_in >> b_in >> c_in;
        a.push_back(a_in);
        b.push_back(b_in);
        c.push_back(c_in);
    }

    // 問題を解く
    for (int i = 0; i <= N; i++)
    {
        // 0日目は何も選んでいないのですべて0
        if (i == 0)
        {
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
            continue;
        }

        // 1日目以降
        if (i > 0)
        {
            dp[i][0] = std::max(dp[i - 1][1] + a[i - 1], dp[i - 1][2] + a[i - 1]);
            dp[i][1] = std::max(dp[i - 1][0] + b[i - 1], dp[i - 1][2] + b[i - 1]);
            dp[i][2] = std::max(dp[i - 1][0] + c[i - 1], dp[i - 1][1] + c[i - 1]);
        }
    }
    int ans = *max_element(dp[N].begin(), dp[N].end());
    std::cout << ans << std::endl;
    return 0;
}