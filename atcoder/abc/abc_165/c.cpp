#include <bits/stdc++.h>

int main()
{
    /* Input */
    long long N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<long long> a(Q), b(Q), c(Q), d(Q);
    for (int i = 0; i < Q; i++)
    {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    }


    /* Solve */

    /**
     *  1 <= A1 <= A2 <= ... <= AN のタネを作る
     *      - 0: 仕切り
     *      - 1: ボール
     * ボールが仕切りのどこにあるかで配列を作る
     * 
     * e.g. N==3, M==4
     *      {1 | 2 | 3   | 4}
     *      {o |   | o o |  }
     *          => {1, 3, 3}
    */
    std::vector<long long> X(N + M-1, 1);
    for (int i = 0; i < M-1; i++) X[i] = 0;

    long long max_score = 0;
    do {
        // スコア初期化
        long long score = 0;

        // 配列 A を作る
        std::vector<long long> A;
        int cnt = 1;
        for (int i = 0; i < X.size(); i++)
        {
            if (X[i] == 1) A.push_back(cnt);
            else cnt++;
        }

        // スコア計算
        for (int i = 0; i < Q; i++)
        {
            if ((A[b[i]-1] - A[a[i]-1]) == c[i])
                score += d[i];
        }

        max_score = std::max(max_score, score);
    }
    while (std::next_permutation(X.begin(), X.end()));

    std::cout << max_score << std::endl;    

    return 0;
}