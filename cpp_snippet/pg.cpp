#include <iostream>

int main()
{
    for (int i = 2; i < 100; i++)
    {
        // 1から自分まで確認して「割れるか」みる
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 2) std::cout << i << std::endl;
    }
}