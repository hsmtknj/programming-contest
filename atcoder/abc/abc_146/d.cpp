#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;

    const int MAX = 100000;
    int n_rows = MAX;     // 行数
    int n_cols = MAX;     // 列数
    int init_value = -1;  // 初期値
    // std::vector<std::vector<int>> map(n_rows+1, std::vector<int>(n_cols+1, init_value));

    std::cout << "Hello" << std::endl;

    // std::vector<std::vector<long long>> g(N);
    // std::vector<int> pair(N);
    // for (int i = 0; i < N - 1; i++)
    // {
    //     std::cout << "in" << std::endl;
    //     int a, b;
    //     std::cin >> a >> b;
    //     a--;
    //     b--;
    //     g[a].push_back(b);
    //     g[b].push_back(a);

    //     pair.push_back(a);
    //     pair.push_back(b);
    // }

    // // 塗り分けるのに最小の色数
    // int max_color_num = 0;
    // for (int i = 0; i < N; i++)
    // {
    //     if (g[i].size() > max_color_num) max_color_num = g[i].size();
    // }

    // std::cout << max_color_num << std::endl;

    return 0;
}