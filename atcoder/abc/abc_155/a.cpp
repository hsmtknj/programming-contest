#include <bits/stdc++.h>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;

    int cnt = 0;
    if (A == B)
        cnt++;
    if (A == C)
        cnt++;
    if (B == C)
        cnt++;

    if (cnt == 1)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}