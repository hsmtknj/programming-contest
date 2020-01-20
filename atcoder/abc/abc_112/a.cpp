#include <iostream>

int main()
{
    int N, A, B;

    std::cin >> N;

    if (N == 1)
    {
        std::cout << "Hello World" << std::endl;
    }

    if (N == 2)
    {
        std::cin >> A;
        std::cin >> B;

        std::cout << A + B << std::endl;
    }

    return 0;
}
