#include <bits/stdc++.h>

#define LEN 255

int main()
{
    std::string S;
    int N;
    std::cin >> N;
    std::cin >> S;

    std::string ans = "";
    int num;
    for (int i = 0; i < S.size(); i++)
    {
        num = (S[i] - 'A' + N) % 26;
        ans += ('A' + num);
    }
    std::cout << ans << std::endl;
    
    return 0;
}