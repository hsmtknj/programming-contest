#include <bits/stdc++.h>

int main()
{
    // 入力
    int N; 
    int K;
    std::cin >> N >> K;
    std::vector<int> h(N);
    for (int i = 0; i < N; i++) std::cin >> h[i];

    // 問題を解く
    std::vector<int> cost(N, INT_MAX);
    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);

    // 3つ以上あるとき
    for (int i = 2; i < N; i++)
    {
        // もらうDP:  コストが最も小さいものを採用
        for (int k = 1; k <= K; k++)
        {
            if (i - k < 0) continue;
            int k_step_cost = cost[i-k] + abs(h[i] - h[i-k]);
            cost[i] = std::min(cost[i], k_step_cost);
        }
    }

    std::cout << cost[N-1] << std::endl;

    return 0;
}
