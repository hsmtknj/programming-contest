#include <bits/stdc++.h>

int main ()
{
    std::string S;
    std::cin >> S;

    int left = 0;
    int right = S.size() - 1;

    int cnt = 0;
    while(right - left > 0)
    {
        if (S[left] != S[right])
        {
            cnt++;
        }
        left++;
        right--;
    }

    std::cout << cnt << std::endl;

    return 0;
}