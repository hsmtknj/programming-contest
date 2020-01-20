#include <bits/stdc++.h>

int main()
{
    int N = 100;

    // 2からNまでで素数を表示
    int count;
    for(int i = 2; i <= N; i++)
    {
        count = 0;
        // 素数かどうかを判定
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0) count++;
            if (count > 0) break;
        }
        // if (count == 0) std::cout << i << std::endl;
    }
    std::cout << "END" << std::endl;
    return 0;
}