#include <bits/stdc++.h>

void rec(long &ans, long x, long n)
{
    if (n <= 0) return;
    else
    {
        // 1ビット目が1のときに掛け算する
        if ((n & 1) == 1) ans *= x; 

        // xは自乗していく
        x *= x;

        // nは1ビットずらす
        //  - 計算回数がわかる
        //  - 掛け算するタイミングが分かる
        n >>= 1;

        // 再帰関数
        rec(ans, x, n);
    }
}

// べき乗 x^n を求める
long my_pow(long x, long n)
{
    long ans = 1;
    rec(ans, x, n);
    return ans;
}

int main()
{
    long num = my_pow(2, 5);
    std::cout << num << std::endl;
    return 0;
}