#include <bits/stdc++.h>

int main()
{
    int N;    
    std::cin >> N;

    std::vector<int> h(N);
    for (int i = 0; i < N; i++) std::cin >> h[i];

    int cost[N];
    cost[0] = 0;
    cost[1] = abs(h[1] - h[0]);
    for (int i = 2; i < N; i++)
    {
        int num1 = cost[i-1] + abs(h[i] - h[i-1]);
        int num2 = cost[i-2] + abs(h[i] - h[i-2]);
        cost[i] = std::min(num1, num2);
    }

    // for (int i = 0; i < N; i++) std::cout << cost[i] << " ";
    // std::cout << std::endl;
    std::cout << cost[N-1] << std::endl;

    return 0;
}
