#include <bits/stdc++.h>

int main()
{
    clock_t start = clock();

    long long cnt = 0;
    for (int i = 0; i < 2140000000; i++)
    {
        cnt++;
    }

    clock_t end = clock();

    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    std::cout << time << std::endl;

    return 0;
}
