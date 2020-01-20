#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    int cnt = 0;
    int tgt_num = 1;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == tgt_num) tgt_num++;
        else cnt++;
    }
    
    if (tgt_num == 1) std::cout << -1 << std::endl;
    else std::cout << cnt << std::endl;

    return 0;
}