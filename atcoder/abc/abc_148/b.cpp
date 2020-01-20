#include <bits/stdc++.h>

int main()
{
    int N;
    std::string S;
    std::string T;
    std::cin >> N;
    std::cin >> S >> T;

    std::string ans;
    for (int i = 0; i < N; i++)
    {
        ans.push_back(S[i]);
        ans.push_back(T[i]);
    }

    std::cout << ans << std::endl;
    return 0;
}