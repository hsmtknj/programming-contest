#include <bits/stdc++.h>

int main()
{
    std::string S;
    std::cin >> S;

    int N = S.size();
    int left, right;
    bool flag = true;
    bool flag_l = true;
    bool flag_r = true;

    left = 0;
    right = S.size() - 1;
    while (right - left > 0)
    {
        if (S[left] != S[right])
        {
            flag = false;
            break;
        }
        left++;
        right--;
    }

    left = 0;
    right = (N - 1) / 2 - 1;
    while (right - left > 0)
    {
        if (S[left] != S[right])
        {
            flag_l = false;
            break;
        }
        left++;
        right--;
    }

    left = (N + 3) / 2 - 1;
    right = N - 1;
    while (right - left > 0)
    {
        if (S[left] != S[right])
        {
            flag_r = false;
            break;
        }
        left++;
        right--;
    }

    if (flag == true && flag_l == true && flag_r == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}