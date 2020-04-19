#include <bits/stdc++.h>

int main()
{
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    std::swap(X, Y);
    std::swap(X, Z);

    std::cout << X << " " << Y << " " << Z << std::endl;

    return 0;
}