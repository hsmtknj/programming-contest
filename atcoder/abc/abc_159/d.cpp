/**
 * 1. まったくボールを抜かないときに何通りあるかをまずは算出する
 * 2. 抜いた数字の個数が n のとき，選び出す数は total から次の値だけ引かれることになる
 *      {n * (n-1) / 2} - {(n-1) * (n-2) / 2} => n-1
 *      よって total - (n - 1) が k を抜いたときの選び出す数
 */

#include <bits/stdc++.h>

int main()
{
    long long N;
    std::cin >> N;
    std::vector<long long> A(N);
    std::vector<long long> map(N+1, 0);

    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
        map[A[i]]++;
    }

    long long total = 0;
    for (int k = 1; k <= N; k++)
        total += map[k] * (map[k]-1) / 2;

    for (int k = 1; k <= N; k++)
        std::cout << total - (map[A[k-1]] - 1) << std::endl;

    return 0;
}