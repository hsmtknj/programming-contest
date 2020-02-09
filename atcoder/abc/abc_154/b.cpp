#include <bits/stdc++.h>

int main()
{
    std::string S;
    std::cin >> S;

    std::string ans = "";
    for (int i = 0; i < S.size(); i++)
        ans += "x";

    std::cout << ans << std::endl;

    return 0;
}