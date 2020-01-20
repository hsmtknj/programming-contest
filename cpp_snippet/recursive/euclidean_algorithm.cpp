/*
    ユークリッドの互除法: GCD(Greatest Common Divisor)
*/

#include <bits/stdc++.h>

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main()
{
    int a = 780;
    int b = 300;
    std::cout << gcd(a, b) << std::endl;

    return 0;
}