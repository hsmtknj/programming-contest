#include <bits/stdc++.h>

int main()
{
    int A;
    int B;
    int C;
    std::cin >> A >> B >> C;

    int ans = C - (A - B);
    if (ans < 0) ans = 0;
    std::cout << ans << std::endl;
    
    return 0;
}
