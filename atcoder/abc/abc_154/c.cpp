#include <bits/stdc++.h>

int main()
{
    long long N;
    std::cin >> N;
    long long A;
    std::unordered_map<std::string, int> map;

    bool ans = true;
    for (int i = 0; i < N; i++)
    {
        std::cin >> A;
        std::string A_str = std::to_string(A);

        if (map.count(A_str) == 0)
            map[A_str] = 1;
        else
        {
            ans = false;
        }
    }

    if (ans == true)
        std::cout << "YES" << std::endl;
    else
        std::cout << "NO" << std::endl;

    return 0;
}