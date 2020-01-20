#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> p(N);
    for (int i = 0; i < N; i++)
        std::cin >> p[i];

    int min_num = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (min_num > p[i])
            min_num = p[i];
        
        if (p[i] <= min_num)
            cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}