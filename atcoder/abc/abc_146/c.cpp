#include <bits/stdc++.h>

long long get_digit(long long num){
    return std::to_string(num).length();
}


int main()
{
    const long long N_MAX = 1000000000;
    long long A;
    long long B;
    long long X;
    std::cin >> A >> B >> X;

    // Nの最大が買えるかどうか
    if (A * N_MAX + B * get_digit(N_MAX) <= X)
    {
        std::cout << N_MAX << std::endl;
        return 0;
    }
    // Nの最小が買えるかどうか
    if (A * 1 + B * get_digit(1) >= X)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 二分探索で解く
    int left = 0;
    int right = N_MAX;
    int mid = 0;
    while (right >= left)
    {
        // 探索対象のNを決定
        mid = left + (right - left) / 2;

        // std::cout << left << ", " << mid << ", " << right << std::endl;
        // getchar();

        // 条件調べる
        bool cond1 = A * mid + B * get_digit(mid) <= X;        // 買えるなら true
        bool cond2 = A * (mid+1) + B * get_digit(mid+1) <= X;  // 買えるなら true

        // 買えてひとつでもNをあげると買えない場合，それが最大
        if (cond1 == true && cond2 == false) break;
        // 買えてまだ余裕がある場合
        else if (cond1 == true && cond2 == true)
        {
            left = mid;
            mid = left + (right - left) / 2;
        }
        // 買えないけど，まだNの候補がある場合
        else if (cond1 == false)
        {
            right = mid;
            mid = left + (right - left) / 2;
        }

        // 結局買えない場合
        if (right >= left)
        {
            mid = 0;
        }
    }
    long long ans = mid;
    std::cout << ans << std::endl;

    return 0;
}