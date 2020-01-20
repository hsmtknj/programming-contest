// TLE: どこかで時間を食っている

#include <bits/stdc++.h>

int N_MAX = pow(10, 5);
int N;
std::vector<int> a;
std::vector<int> b;
std::vector<int> c;
std::vector<std::vector<int>> dp(N_MAX + 1, std::vector<int>(3, -1));

std::vector<int> rec(int i)
{
    std::vector<int> out(3);

    // ベースケース: 0日目は何もしないのですべて0
    if (i == 0)
    {
        out[0] = out[1] = out[2] = 0;
        return dp[0] = out; // メモ
    }

    // メモチェック（今回の問題では意味はないが，一応実装）
    // 既に計算している場合
    if (dp[i - 1][0] != -1)
    {
        out[0] = std::max(dp[i - 1][1] + a[i - 1], dp[i - 1][2] + a[i - 1]);
        out[1] = std::max(dp[i - 1][0] + b[i - 1], dp[i - 1][2] + b[i - 1]);
        out[2] = std::max(dp[i - 1][0] + c[i - 1], dp[i - 1][1] + c[i - 1]);        
    }
    // まだ計算していない場合
    else
    {
        // 再帰関数
        out[0] = std::max(rec(i - 1)[1] + a[i - 1], rec(i - 1)[2] + a[i - 1]);
        out[1] = std::max(rec(i - 1)[0] + b[i - 1], rec(i - 1)[2] + b[i - 1]);
        out[2] = std::max(rec(i - 1)[0] + c[i - 1], rec(i - 1)[1] + c[i - 1]);
    }
    return out;
}

int main()
{
    // 入力
    std::cin >> N;
    a = std::vector<int>(N);
    b = std::vector<int>(N);
    c = std::vector<int>(N);
    for (int i = 0; i < N; i++)
        std::cin >> a[i] >> b[i] >> c[i];

    // 問題を解く
    std::vector<int> ans_vec = rec(N);
    int ans = *max_element(ans_vec.begin(), ans_vec.end());
    std::cout << ans << std::endl;

    return 0;
}