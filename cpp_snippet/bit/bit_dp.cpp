/*
[INPUT (1)]
3
0 5 2
5 0 4
2 4 0

-> ans: 6

[INPUT (2)]
4
0 8 7 3
8 0 9 1
7 9 0 4
3 1 4 0

-> ans: 11
*/

#include <iostream>
#include <bitset>
#include <limits.h>

const int N_MAX = 20;
int N;                          // ノード数（訪問場所数）
int dp[(1<<N_MAX)+1][N_MAX+1];  // 状態数
int dist[N_MAX][N_MAX];         // ノード間の距離


int rec(int bit, int v)
{
    /* 探索済みであれば dp の値を返す */
    if (dp[bit][v] != -1) return dp[bit][v];

    /* ベースケース: スタート地点が決まったとき，初期値を入れる */
    if (bit == (1<<v)) return dp[bit][v] = 0;

    /* 最後に訪問した地点をベースとして遡る */
    // 前状態を求める
    int prev_bit = bit & ~(1<<v);

    // 前状態から現状態に遷移するパターンのうち最小のものを採用する
    int ans = INT_MAX;
    for (int u = 0; u < N; u++)
    {
        // 既に探索済みのところのみから遡る（未訪問の場所が最後に訪れた場所にはなり得ない）
        if (bit & 1<<u)
        {
            int cost_u = rec(prev_bit, u) + dist[u][v];
            if (cost_u < ans) ans = cost_u;
        }
    }
    return ans;
}


int main()
{
    /* 入力を受け付ける */
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> dist[i][j];
        }
    }

    /* dp の初期化 */
    for (int i = 0; i < (1<<N); i++)
    {
        for (int j = 0; j < N; j++)
        {
            // -1:未探索で初期化
            dp[i][j] = -1;
        }
    }

    /* 探索 */
    int ans = INT_MAX;
    for (int v = 0; v < N; v++)
    {
        int cost_v = rec((1<<N)-1, v);
        if (cost_v < ans) ans = cost_v;
    }

    std::cout << ans << std::endl;

    return 0;
}