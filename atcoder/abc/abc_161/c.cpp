/**
 * [NOTE]
 * abs() の使い方でハマった
 *  - std::abs() を使うと良い
 */

#include <bits/stdc++.h>

int main()
{
    long long N, K;
    std::cin >> N >> K;

    long long r = N % K;
    long long ans = std::min(r, std::abs(r - K));
    std::cout << ans << std::endl;

    return 0;
}