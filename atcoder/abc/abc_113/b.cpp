#include <iostream>
#include <algorithm>

int main()
{
    // input
    int N, T, A;
    std::cin >> N;
    std::cin >> T >> A;
    
    int v[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &v[i]);
    }

    // find answer
    int diff_min = 1000000000;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        int temp = T * 1000 - v[i] * 6;
        int diff = abs(temp - A * 1000);

        if (diff_min > diff)
        {
            diff_min = diff;
            ans = i + 1;  // one-based indexing
        }

    }

    std::cout << ans << std::endl;

}
