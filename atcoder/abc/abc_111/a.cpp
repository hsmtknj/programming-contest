#include <iostream>
#include <math.h>

int main()
{
    int N;
    std::cin >> N;

    std::string s;
    s = std::to_string(N);

    int out = 0;
    for (int i = 0; i < 3; i++)
    {
        if (s[i] == '1')
        {
            out += 9 * pow(10, 2 - i);
        }
        else if (s[i] == '9')
        {
            out += 1 * pow(10, 2 - i);
        }
    }

    std::cout << out << std::endl;

    return 0;
}