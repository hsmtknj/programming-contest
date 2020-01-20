#include <bits/stdc++.h>

int main ()
{
    long long N;
    long long count;
    std::cin >> N;
    std::vector<std::string> s(N);
    std::unordered_map<std::string, long long> map;

    for (int i = 0; i < N; i++)
    {
        // 受け取った文字列をソート
        std::cin >> s[i];
        std::sort(s[i].begin(), s[i].end());

        std::string tgt_s = {s[i]};
        if (map.count(tgt_s) == 0)
        {
            map[tgt_s] = 1;
        }
        else if (map.count(tgt_s) > 0)
        {
            count += map[tgt_s];
            map[tgt_s]++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}