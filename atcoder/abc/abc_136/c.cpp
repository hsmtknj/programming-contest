#include <bits/stdc++.h>

int main ()
{
    long long N;
    std::cin >> N;
    std::vector<long long> H(N);
    for (int i = 0; i < N; i++) std::cin >> H[i];

    bool ans = true;
    for (int i = 1; i < N; i++)
    {
        int diff = H[i] - H [i-1];

        if (diff == 0)
        {
            continue;
        }
        else if (diff >= 1)
        {
            H[i]--;
        }
        else if (diff < 0)
        {
            ans = false;
            break;
        }
    }

    if (ans == true) std::cout << "Yes" << std::endl;
    else if (ans == false) std::cout << "No" << std::endl;

    return 0;
}