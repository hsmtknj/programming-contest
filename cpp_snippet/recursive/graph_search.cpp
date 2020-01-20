#include <bits/stdc++.h>

int N = 8;
int M = 12;
std::vector<std::vector<int>> graph = {{5},
                                       {3, 6},
                                       {5, 7},
                                       {0, 7},
                                       {1, 2, 6},
                                       {},
                                       {7},
                                       {0}};

std::vector<bool> searched(N, false);

void search(int n)
{
    // 探索したら表示
    std::cout << n << std::endl;
    searched[n] = true;

    // 隣接ノードを持っているかを確認
    if (!graph[n].empty())
    {
        // 隣接ノードがあれば探索
        for (int i = 0; i < graph[n].size(); i++)
        {
            // 探索済みかどうかを確認
            if (searched[graph[n][i]] == true) continue;
            else search(graph[n][i]);
        }
    }
}

int main()
{
    // グラフ探索
    for (int i = 0; i < N; i++)
    {
        // 探索済みであれば飛ばす
        if (searched[i] == true) continue;
        // 未探索であれば探索
        else search(i);
    }

    return 0;
}
