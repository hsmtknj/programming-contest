#include <iostream>

int main()
{
    int K;
    int X;
    std::cin >> K >> X;

    for (int i = X - K + 1; i < X + K; i++)
    {
        std::cout << i << " ";
    }
}
