#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N;
    int Q;
    std::cin >> N >> Q;

    // graph definition
    std::vector<std::vector<int>> graph(N);
    for (int i = 0; i < N - 1; i++)
    {
        int a;
        int b;
        std::cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    // solve
    std::vector<long long> cnt(N, 0);
    for (int i = 0; i < Q; i++)
    {
        int p;
        long long x;
        std::cin >> p >> x;
        p--;
        cnt[p] += x;
    }

    std::queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        // select target node
        int target_iter = que.front();
        que.pop();

        // add adjacent node
        if (!graph[target_iter].empty())
        {
            for (int i = 0; i < graph[target_iter].size(); i++)
            {
                cnt[graph[target_iter][i]] += cnt[target_iter];
                que.push(graph[target_iter][i]);
            }
        }
    }

    // show answer
    for (int i = 0; i < N; i++)
    {
        std::cout << cnt[i] << " ";
    }

}
