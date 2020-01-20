#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;
    
    // 組み合わせ配列初期化
    int cmb[10][10];  // 先頭, 末尾
    for (int head = 0; head < 10; head++)
    {
        for (int tail = 0; tail < 10; tail++)
        {
            cmb[head][tail] = 0;
        }
    }

    // 組み合わせ配列を先に求める
    for (int i = 1; i <= N; i++)
    {
        std::string s = std::to_string(i);
        int head = s[0] - '0';
        int tail = s[s.size()-1] - '0';
        cmb[head][tail]++;
    }

    // AとBの組み合わせ数を求める
    int ans = 0;
    for (int head = 1; head <= 9; head++)
    {
        for (int tail = 1; tail <= 9; tail++)
        {
            ans += cmb[head][tail] * cmb[tail][head];
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
