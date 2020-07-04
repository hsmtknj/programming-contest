#include <bits/stdc++.h>

int main()
{
    // ========================================================================
    // 有向グラフを定義
    // ========================================================================

    int root_ind = 0;
    std::vector<std::vector<int>> graph = {{1, 2},
                                           {3, 4},
                                           {5, 6},
                                           {7},
                                           {},
                                           {8, 9},
                                           {},
                                           {},
                                           {},
                                           {}};


    // ========================================================================
    // 幅優先探索 (BFS: Breadth First Search)
    // ========================================================================

    // 幅優先探索をキューで実装
    std::queue<int> que;                       // 探索対象のインデックスを格納する配列
    std::vector<int> searched_array_que = {};  // 探索したインデックスを順に格納する結果配列

    que.push(root_ind);
    while (!que.empty())
    {
        // 探索対象のインデックスを取り出す
        int target_ind = que.front();
        que.pop();

        // 取り出したインデックスを結果配列に格納する
        searched_array_que.push_back(target_ind);

        // 隣接ノードがあればキューに入れる
        if (!graph[target_ind].empty())
        {
            for (int i = 0; i < graph[target_ind].size(); i++)
            {
                que.push(graph[target_ind][i]);
            }
        }
    }

    // 幅優先探索の探索結果を可視化
    for (int i = 0; i < searched_array_que.size(); i++)
    {
        std::cout << searched_array_que[i] << " ";
    }
    std::cout << std::endl;


    // ========================================================================
    // 深さ優先探索 (DFS: Depth First Search)
    // ========================================================================

    std::stack<int> sta;                      // 探索対象のインデックスを格納する配列
    std::vector<int> searched_array_sta = {}; // 探索したインデックスを順に格納する結果配列

    sta.push(root_ind);

    while (!sta.empty())
    {
        // 探索対象のインデックスを取り出す
        int target_ind = sta.top();
        sta.pop();

        // 取り出したインデックスを結果配列に格納する
        searched_array_sta.push_back(target_ind);

        // 隣接ノードがあればスタックに入れる
        if (!graph[target_ind].empty())
        {
            for (int i = 0; i < graph[target_ind].size(); i++)
            {
                sta.push(graph[target_ind][i]);
            }
        }
    }

    // 深さ優先探索の探索結果を可視化
    for (int i = 0; i < searched_array_sta.size(); i++)
    {
        std::cout << searched_array_sta[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
