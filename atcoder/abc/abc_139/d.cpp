// ============================================================================
// オーバーフローを起こしていることになかなか気付かずWA量産
// ============================================================================

#include <iostream>

int main()
{
    unsigned long long N;
    std::cin >> N;

    // int s = 0;
    // for (int i = 1; i < N; i++)
    // {
    //     s += i;
    // }

    unsigned long long s;
    s = ((N - 1) * N) / 2;

    std::cout << s << std::endl;
}
