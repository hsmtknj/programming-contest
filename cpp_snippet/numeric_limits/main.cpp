#include <iostream>
#include <limits>

int main()
{
    int int_max = std::numeric_limits<int>::max();
    int int_min = std::numeric_limits<int>::min();

    std::cout << "int max: " << int_max << std::endl;
    std::cout << "int min: " << int_min << std::endl;
    return 0;
}