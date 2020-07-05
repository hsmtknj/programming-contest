/**
 * 各展望台すべて true にしておいて
 * 道でつながっている展望台で低い方を false にしていく
 */

#include <bits/stdc++.h>

int main() {
    /* Input */
    long long N, M;
    std::cin >> N >> M;
    std::vector<long long> H(N);

    for (int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    /* Solve */
    std::vector<bool> good(N, true);

    for (int i = 0; i < M; i++) {
        // 道を受け取る (0-based インデクシングに変換)
        long long a, b;
        std::cin >> a >> b;
        a--;
        b--;
        
        // 低い方の展望台を false に変更
        if (H[a] > H[b]) good[b] = false;
        else if (H[a] < H[b]) good[a] = false;
        else if (H[a] == H[b]) good[a] = good[b] = false;
    }

    int cnt = 0;
    for (int i = 0; i < good.size(); i++) {
        if (good[i]) cnt++;
    }

    std::cout << cnt << std::endl;

    return 0;
}