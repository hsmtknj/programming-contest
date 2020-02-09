#include <bits/stdc++.h>

int main()
{
    std::string S, T, U;
    int A, B;

    std::cin >> S >> T;
    std::cin >> A >> B;
    std::cin >> U;

    if (U == S)
        A--;
    if (U == T)
        B--;

    std::cout << A << " " << B << std::endl;

    return 0;
}