#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;

    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        // 桁数を見る
        std::string s = std::to_string(i);
        if (s.size() % 2 == 1) cnt++;
    }
    std::cout << cnt << std::endl;

    return 0;
}