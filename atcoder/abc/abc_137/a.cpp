#include <iostream>

int main()
{
    int A;
    int B;
    std::cin >> A >> B;
    std::cout << std::max({A + B, A - B, A * B}) << std::endl;
}
