#include <bits/stdc++.h>

int main()
{
    long long N, M, K;
    std::cin >> N >> M >> K;
    std::vector<std::vector<long long>> map(N, std::vector<long long>(N, -1));
    std::vector<long long> A(M), B(M), C(K), D(K);
    for (int i = 0; i < M; i++)
    {
        std::cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        map[A[i]][B[i]] = 1;
        map[B[i]][A[i]] = 1;
    }
    for (int i = 0; i < K; i++)
    {
        std::cin >> C[i] >> D[i];
        C[i]--;
        D[i]--;
        map[C[i]][D[i]] = 1;
        map[D[i]][C[i]] = 1;
    }

    std::vector<long long> ans(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (i == j)
                continue;

            if (map[i][j] != 1)
            {
                ans[i]++;
                ans[j]++;
            }
        }
    }

    for (int i = 0; i < N; i++)
        std::cout << ans[i] << " ";
    std::cout << std::endl;

    return 0;
}