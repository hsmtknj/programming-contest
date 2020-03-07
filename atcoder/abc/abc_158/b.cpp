#include <bits/stdc++.h>

int main()
{
    long long N, A, B;
    std::cin >> N >> A >> B;

    long long a, b;

    a = N / (A + B);
    b = N % (A + B);

    //std::cout << a << ", " << b << std::endl;

    long long num1, num2;
    
    num1 = a * A;
    if (b <= A)
        num2 = b;
    else
        num2 = A;

    long long ans = num1 + num2;
    std::cout << ans << std::endl;

    return 0;
}