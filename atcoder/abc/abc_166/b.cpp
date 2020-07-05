#include <bits/stdc++.h>

int main() {

    int N, K;
    std::cin >> N >> K;

    std::vector<bool> A(N, false);

    for (int i = 0; i < K; i++) {
        // お菓子 i の個数を取得
        int num;
        std::cin >> num;

        // お菓子 i をもらった人を true に変えていく
        for (int j = 0; j < num; j++) {
            int ind;
            std::cin >> ind;
            A[ind-1] = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == false) ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}