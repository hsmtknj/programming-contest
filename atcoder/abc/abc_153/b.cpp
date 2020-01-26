#include <bits/stdc++.h>

int main()
{
    long long H, N;
    std::cin >> H >> N;

    std::vector<long long> A(N);
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
    
    long long sum_num = 0;
    for (int i = 0; i < N; i++)
        sum_num += A[i];
    
    if (sum_num >= H)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}