#include <bits/stdc++.h>

int main()
{
    /* Input */
    int N, X, Y;
    std::cin >> N >> X >> Y;

    /* Solve */

    // 最短距離をインデックスに持つ配列
    // 最短距離を算出するごとに対応するインデックスをカウントアップ
    std::vector<int> map(N+1, 0);
    int min_dist = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            // 閉路はひとつでノードからノードへの移動は2通りしかないため小さい方を採用
            min_dist = std::min(j-i, std::abs(X-i) + std::abs(Y-j) + 1);
            map[min_dist]++;
        }
    }

    // show result
    for (int i = 1; i < N; i++)
        std::cout << map[i] << std::endl;

    return 0;
}