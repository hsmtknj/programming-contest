#include <bits/stdc++.h>

int main ()
{
    int A1, A2, A3;
    std::cin >> A1 >> A2 >> A3;

    int num = A1 + A2 + A3;
    if (num >= 22) std::cout << "bust" << std::endl;
    if (num <= 21) std::cout << "win" << std::endl;

    return 0;
}