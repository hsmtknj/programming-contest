#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int main()
{
    // ========================================================================
    // 探索対象のグラフを定義
    // ========================================================================
    int N = 10;     // ノード数
    int M = N - 1;  // 辺の数
    std::vector<std::vector<int>> graph  = {{1, 2},
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
    // 幅優先探索（キューで実装）
    // ========================================================================
    std::vector<int> que_ind_order(N);
    int que_iter = 0;
    std::queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        // 対象のインデックスを取得
        int target_index = que.front();
        que.pop();

        // 探索した順を格納
        que_ind_order[que_iter] = target_index;
        que_iter++;

        // 隣接ノードがあれば探索対象リストに追加
        if (!graph[target_index].empty())
        {
            for (int i = 0; i < graph[target_index].size(); i++)
            {
                que.push(graph[target_index][i]);
            }
        }
    }

    // 幅優先探索順を表示
    std::cout << "BFS" << std::endl;
    for (int i = 0; i < que_ind_order.size(); i++)
    {
        std::cout << que_ind_order[i] << std::endl;
    }


    // ========================================================================
    // 深さ優先探索 (スタックで実装)
    // ========================================================================
    std::vector<int> sta_ind_order(N);
    int sta_iter = 0;
    std::stack<int> sta;
    sta.push(0);
    while(!sta.empty())
    {
        // 対象のインデックスを取り出す
        int target_index = sta.top();
        sta.pop();

        // 探索した順を格納
        sta_ind_order[sta_iter] = target_index;
        sta_iter++;

        // 隣接ノードがあれば探索対象リストに追加
        if (!graph[target_index].empty())
        {
            for (int i = 0; i < graph[target_index].size(); i++)
            {
                sta.push(graph[target_index][i]);
            }
        }
    }

    // 深さ優先探索順を表示
    std::cout << "BFS" << std::endl;
    for (int i = 0; i < sta_ind_order.size(); i++)
    {
        std::cout << sta_ind_order[i] << std::endl;
    }

}
