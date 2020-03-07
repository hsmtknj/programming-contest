#include <bits/stdc++.h>

int main()
{
    int N_MAX = 2000;

    double A, B;
    std::cin >> A >> B;

    int ans = -1;
    for (int i = 0; i < N_MAX; i++)
    {
        double tgt_num = double(i);

        int num_A = tgt_num * 0.08;
        int num_B = tgt_num * 0.10;
        // std::cout << i << ": " << num_A << ", " << num_B << std::endl;

        if (num_A == A && num_B == B)
        {
            ans = i;
            break;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}