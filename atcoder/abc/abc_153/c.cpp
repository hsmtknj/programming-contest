#include <bits/stdc++.h>

int main()
{
    long long N, K;
    std::cin >> N >> K;

    std::vector<long long> H(N);
    for (int i = 0; i < N; i++)
        std::cin >> H[i];

    // ソート
    std::sort(H.begin(), H.end(), std::greater<long long>());

    long long cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (K > 0)
        {
            K--;
        }
        else
        {
            cnt += H[i];
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}