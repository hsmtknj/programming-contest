#include <bits/stdc++.h>

int main()
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> v(N);

    for (int k = 0; k < K; k++)
    {
        // k番目のお菓子をもらった人の数を取得
        int okashi_num;
        std::cin >> okashi_num;

        // k番目のお菓子をもらった人のインデックスを取得
        for (int i = 0; i < okashi_num; i++)
        {
            int num;
            std::cin >> num;
            v[--num]++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        // お菓子を持っていなければカウント
        if (v[i] == 0)
            cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}