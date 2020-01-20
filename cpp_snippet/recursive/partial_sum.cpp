#include <bits/stdc++.h>

const int N_MAX = pow(10, 3);
const int X_MAX = pow(10, 5);

// 入力
int N = 4;
int X = 14;
std::vector<int> a = {3, 2, 6, 5};
std::vector<std::vector<int>> memo(N_MAX+1, std::vector<int>(X_MAX+1, -1));
int cnt = 0;

/*
    ind: 現在のインデックス，そのインデックスの値はまだ判定していない
    current_sum: 現段階での部分和
*/
bool rec(int ind, int current_sum)
{
    cnt++;

    // 枝狩り
    if (current_sum > X) return memo[ind][current_sum] = false;

    // ベースケース
    if (ind == N)
    {
        if (current_sum == X) return memo[ind][current_sum] = true;
        else return memo[ind][current_sum] = false;
    }

    // メモチェック
    if (memo[ind][current_sum] != -1) return memo[ind][current_sum];

    // 再帰関数
    if (rec(ind+1, current_sum)) return memo[ind][current_sum] = true;                // 選ばないとき
    else if (rec(ind+1, current_sum + a[ind])) return memo[ind][current_sum] = true;  // 選ぶとき

    // 両方ダメなとき
    return memo[ind][current_sum] = false;
}

int main()
{
    // 部分和問題
    bool ans = rec(0, 0);
    std::cout << "ans: " << ans << std::endl;
    std::cout << "cnt: " << cnt << std::endl;

    return 0;
}