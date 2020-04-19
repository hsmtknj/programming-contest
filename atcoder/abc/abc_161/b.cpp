#include <bits/stdc++.h>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    int A_total = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> A[i];
        A_total += A[i];
    }
    // A_total = std::accumulate(A.begin(), A.end(), 0);  // 合計はこれでも算出できる

    
    double th = (double)A_total / (4 * (double)M);
    std::sort(A.begin(), A.end(), std::greater<int>());
    if (A[M-1] >= th)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    // bool flag = true;
    // for (int i = 0; i < M; i++)
    // {
    //     if ((float)A[i] < th)
    //     {
    //         flag = false;
    //         break;
    //     }
    // }

    // if (flag == true)
    //     std::cout << "Yes" << std::endl;
    // else if (flag == false)
    //     std::cout << "No" << std::endl;

    return 0;
}