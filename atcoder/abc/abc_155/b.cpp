#include <bits/stdc++.h>

int main()
{
    int N, A;
    std::cin >> N;

    int even_cnt = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> A;
        if (A % 2 == 0)
        {
            even_cnt++;
            if (A % 3 == 0 | A % 5 == 0)
                cnt++;
        }
    }

    if (even_cnt == 0)
        std::cout << "APPROVED" << std::endl;
    else if (even_cnt > 0 && even_cnt == cnt)
        std::cout << "APPROVED" << std::endl;
    else
        std::cout << "DENIED" << std::endl;

    return 0;
}