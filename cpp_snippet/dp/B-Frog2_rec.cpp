// TLE: どこかで時間を食っている

#include <bits/stdc++.h>

// グローバル変数
int N;
int K;
std::vector<int> h;
std::vector<int> memo;

int rec(int i)
{
    // ベースケース
    if (i == 0) return memo[i] = 0;

    // メモチェック
    if (memo[i] < INT_MAX) return memo[i];

    // 再帰関数
    int out = INT_MAX;
    for (int k = 1; k <= K; k++)
    {
        // 遡れなかったら飛ばす
        if (i - k < 0) continue;
        
        // 遡った先を既に計算している場合
        if (memo[i-k] < INT_MAX) out = std::min(out, memo[i-k] + abs(h[i] - h[i-k]));
        // まだ計算していない場合
        else out = std::min(out, rec(i-k) + abs(h[i] - h[i-k]));
    }
    return out;
}

int main()
{
    // 入力
    std::cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tgt_h;
        std::cin >> tgt_h;
        h.push_back(tgt_h);
    }

    // 問題を再帰関数で解く
    for (int i = 0; i < N; i++) memo.push_back(INT_MAX);
    int ans = rec(N-1);

    // 出力
    std::cout << ans << std::endl;
    return 0;
}