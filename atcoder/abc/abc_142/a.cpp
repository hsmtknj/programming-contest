#include <iostream>

int main()
{
    // input
    int N;
    std::cin >> N;

    // solve
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1)
        {
            cnt++;
        }
    }

    // answer
    double ans = double(cnt) / double(N);
    std::cout << ans << std::endl;
}
