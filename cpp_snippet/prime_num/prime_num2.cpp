#include <bits/stdc++.h>

int main()
{
    int N = 1000000000;
    std::vector<int> is_prime(N+1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    int count = 0;
    // 全体の sqrt(N) まで見れば良い
    for(int i = 2; i * i <= N; i++)
    {
        // false なら見る必要なし
        if (is_prime[i] == false) continue;

        // 素数かどうか判定
        count = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) count++;
            if (count > 0) break;
        }

        // 素数だった場合，倍数をふるい落としていく
        if (count == 0)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     if (is_prime[i]) std::cout << i << std::endl;
    // }
    std::cout << "END" << std::endl;
    return 0;
}