#include <bits/stdc++.h>

int main()
{
    /* INPUT */
    std::vector<std::vector<int>> A(3, std::vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cin >> A[i][j];
        }
    }

    int N;
    std::cin >> N;

    std::vector<int> b(N);
    for (int i = 0; i < N; i++)
        std::cin >> b[i];

    /* SOLVE */
    
    // init
    std::vector<std::vector<int>> B(3, std::vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            B[i][j] = false;
        }
    }

    // 穴をあける
    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] == b[n])
                    B[i][j] = true;
            }
        } 
    }

    // 確認
    bool ans = false;
    if (B[0][0] == true && B[0][1] == true && B[0][2])
        ans = true;
    if (B[1][0] == true && B[1][1] == true && B[1][2])
        ans = true;
    if (B[2][0] == true && B[2][1] == true && B[2][2])
        ans = true;
    if (B[0][0] == true && B[1][0] == true && B[2][0])
        ans = true;
    if (B[0][1] == true && B[1][1] == true && B[2][1])
        ans = true;
    if (B[0][2] == true && B[1][2] == true && B[2][2])
        ans = true;
    if (B[0][0] == true && B[1][1] == true && B[2][2])
        ans = true;
    if (B[0][2] == true && B[1][1] == true && B[2][0])
        ans = true;
    
    // 表示
    if (ans == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    return 0;
}