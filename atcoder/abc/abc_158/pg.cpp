#include <bits/stdc++.h>

int main()
{
    std::vector<std::string> vs;

    for (int i = 0; i < 10; i++)
    {
        std::string s = std::to_string(i);
        vs.push_back(s);
    }

    for (int i = 0; i < vs.size(); i++)
    {
        std::cout << vs[i][0] << std::endl;
    }

    return 0;
}