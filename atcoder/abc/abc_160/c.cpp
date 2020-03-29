#include <bits/stdc++.h>

int main()
{
    int K, N;
    std::cin >> K >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++)
        std::cin >> A[i];

    int min_dist = INT_MAX;
    int a;
    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            a = A[A.size()-1] - A[0];
        else if (i > 0)
            a = (K - A[i]) + A[i-1];
        
        if (a < min_dist)
            min_dist = a;
    }
    std::cout << min_dist << std::endl;
    
    return 0;
}
