#include <bits/stdc++.h>

int main()
{
    bool flag_finish = false;

    int N_MAX = 3;
    int N, M;
    std::cin >> N >> M;
    std::vector<int> s(M);
    std::vector<int> c(M);
    std::vector<int> sc(N_MAX+1, -1);


    for (int i = 0; i < M; i++)
    {
        std::cin >> s[i] >> c[i];

        // 2桁以上で先頭が0のときは終了
        if (N >= 2 && s[i] == 1 && c[i] == 0)
            flag_finish = true;

        // 重複があった場合は終了
        if (sc[s[i]] == -1)
            sc[s[i]] = c[i];
        else if (sc[s[i]] != c[i])
            flag_finish = true;
    }

    if (flag_finish == true)
        std::cout << -1 << std::endl;
    else
    {
        // 初期化
        std::vector<int> v(N, 0);

        // 桁ごとに入れ替え
        for (int i = 0; i < M; i++)
            v[s[i]-1] = c[i];

        // 先頭が不定のときは1にする
        if (v[0] == 0)
            v[0] = 1;

        // 値に変換
        std::string ans = "";
        for (int i = 0; i < N; i++)
            ans += std::to_string(v[i]);

        std::cout << std::stoi(ans) << std::endl;
    }
    

    return 0;
}