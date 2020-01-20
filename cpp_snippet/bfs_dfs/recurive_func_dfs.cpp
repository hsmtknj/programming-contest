/*
部分和問題を深さ優先探索で解く
    - 深さ優先探索は再帰関数で実装
    - 高速化のため下記を実装
        - 枝狩り
        - メモ化（メモ化再帰）
*/

#include <bits/stdc++.h>

bool dfs(const int &given_num,
         const std::vector<int> &given_array,
         int ind,
         int total_sum,
         std::vector<std::vector<int>> &ans_array,
         std::vector<int> searched_array,
         std::vector<std::vector<int>> &memo)
{
    // 枝狩り
    if (total_sum > given_num) return false;

    // ベースケース
    //  最後まで探索したら判定
    if (ind == given_array.size())
    {
        if (total_sum == given_num)
        {
            ans_array.push_back(searched_array);
            return true;
        }
        return false;
    }

    // 再帰関数に入力する前にメモをチェック
    if (memo[ind][total_sum] != -1) return 0;

    // 再帰関数
    std::vector<int> searched_array_0 = searched_array;
    searched_array_0.push_back(0);
    std::vector<int> searched_array_1 = searched_array;
    searched_array_1.push_back(1);
    //  - 足さない場合
    if (dfs(given_num, given_array, ind+1, total_sum, ans_array, searched_array_0, memo))
    {
        // trueをメモしながらリターン
        memo[ind][total_sum] = 1;
        return true;
    }
    //  - 足す場合
    if (dfs(given_num, given_array, ind+1, total_sum + given_array[ind], ans_array, searched_array_1, memo))
    {
        // trueをメモしながらリターン
        memo[ind][total_sum] = 1;
        return true;
    }

    // どっちもだめだったらfalseをメモしながらリターン
    memo[ind][total_sum] = 0;
    return false;
}

int main ()
{
    // 入力
    int given_num = 9;
    std::vector<int> given_array = {1, 3, 6, 14};

    // 再帰関数で解く準備
    int ind = 0;
    int total_sum = 0;
    std::vector<int> searched_array;
    std::vector<std::vector<int>> ans_array;

    // メモ化再帰の準備
    const int MAX = 100000;
    // int memo[given_array.size()][100000];
    // std::fill(memo[0], memo[given_array.size()], -1);
    std::vector<std::vector<int>> memo(given_array.size()+1, std::vector<int>(MAX+1, -1));
    
    // 深さ優先探索で解く
    bool ans = dfs(given_num, given_array, ind, total_sum, ans_array, searched_array, memo);

    // 解答出力
    if (ans) 
    {
        std::cout << "Yes" << std::endl;
        for (int i = 0; i < ans_array.size(); i++)
        {
            for (int j = 0; j < given_array.size(); j++)
            {
                std::cout << ans_array[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    else std::cout << "No" << std::endl;

    return 0;
}