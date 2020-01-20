#include <iostream>
#include <string>

int main()
{
    int N;
    std::string S;

    std::cin >> N;
    std::cin >> S;

    // 奇数ならNo
    if (S.size() % 2 == 1)
    {
        std::cout << "No" << std::endl;
        return 0;
    }

    // 偶数なら判定
    bool flag = true;
    for (int i = 0; i < S.size() / 2; i++)
    {
        if (S[i] != S[i+S.size()/2])
        {
            flag = false;
        }
    }

    if (flag)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }
    


    return 0;
}