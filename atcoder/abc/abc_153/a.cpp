#include <bits/stdc++.h>

int main()
{
    int H, A;
    std::cin >> H >> A;

    int cnt = 0;
    while (H > 0)
    {
        H -= A;
        cnt++;
    }
    
    std::cout << cnt << std::endl;
    return 0;
}