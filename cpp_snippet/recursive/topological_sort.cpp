/*
    [トポロジカルソート]
        - どのリンクに対しても次のように1列に並び替える
            - 流入元ノードが前
            - 流出先ノードが後
        - 答えは1通りではないことが多い

    [アルゴリズム]
        - グラフを探索していく際に「再帰関数を抜けた順」で配列に格納する

    [この例の出力]
        4 -> 2 -> 1 -> 6 -> 3 -> 7 -> 0 -> 5 -> 
*/

#include <bits/stdc++.h>

int N = 8;
int M = 12;
std::vector<std::vector<int>> G = {{5},
                                  {3, 6},
                                  {5, 7},
                                  {0, 7},
                                  {1, 2, 6},
                                  {},
                                  {7},
                                  {0}};


void search(int n, std::vector<int> &searched, std::vector<int> &order)
{
    // このノードを探索済みに変更
    searched[n] = true;

    // 隣接ノードがあれば探索
    if (!G[n].empty())
    {
        for (int i = 0; i < G[n].size(); i++)
        {
            // 探索済みかどうか確認
            if (searched[G[n][i]]) continue;
            else search(G[n][i], searched, order);
        }
    }

    // 再帰関数を抜けるときに加える
    order.push_back(n);
}

int main()
{
    std::vector<int> order;               // トポロジカルソート順を格納
    std::vector<int> searched(N, false);  // 探索済みかどうかを格納

    // 各ノードを for 文で回る
    for(int n = 0; n < N; n++)
    {
        // 探索済みなら飛ばす
        if (searched[n]) continue;
        // 未探索であれば探索
        else search(n, searched, order);
    }

    // トポロジカルソートの結果を表示
    std::reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); i++)
    {
        std::cout << order[i] << " -> ";
    }
    std::cout << std::endl;

    return 0;
}
