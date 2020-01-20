/*
    <名称>
        バケットソート（計数ソート）: bucket sort
    <計算量>
        O(n + A)
    <特徴>
        - 小さい値までのソートならめちゃめちゃ早い
    <アルゴリズム>
        - ソートしたい配列:v の他に，バケット配列:b と 累積和配列:sum を用意する
            - 大きさは適当な大きさMAX(配列の最大が入ればOK)
        - b   : どの値が何回出てきているかをチェック
        - sum : bのカウントの累積和を取る
            - この累積和がインデックスそのものになる (one-based-indexing)
        - sorted[--sum[v[i]]] = v[i] で格納
            - 前置デクリメントの役割
                - one-based-indexing -> zero-based-idexing に変換
                - 同じ値でもデクリメントすることで次回登場時に同じインデックスとなることを防ぐ
*/

#include <bits/stdc++.h>

std::vector<int> bucket_sort(std::vector<int> &v)
{
    const int MAX = 100000;
    // const int MAX = 6;
    std::vector<int> b(MAX+1, 0);  // バケット
    std::vector<int> sum(MAX+1);   // 累積和

    // バケットにどの値が何回出てきているかを格納
    for (int i = 0; i < v.size(); i++)
    {
        b[v[i]]++;
    }
    // for (int i = 0; i < b.size(); i++) std::cout << b[i] << " ";
    // std::cout << std::endl;

    // 累積和を計算（これがそのまま one-based-indexing となる）
    sum[0] = b[0];
    for (int i = 1; i < MAX+1; i++)
    {
        sum[i] = sum[i-1] + b[i];
    }
    // for (int i = 0; i < sum.size(); i++) std::cout << sum[i] << " ";
    // std::cout << std::endl;

    // 累積和をもとにソート
    std::vector<int> sorted(v.size());
    for (int i = v.size()-1; i >= 0; i--)
    {
        sorted[--sum[v[i]]] = v[i];
    }

    return sorted;
}

int main()
{
    std::vector<int> v = {30, 88, 17, 12, 20, 25};
    // std::vector<int> v = {5, 1, 3, 2};

    std::vector<int> sorted = bucket_sort(v);
    for (int i = 0; i < sorted.size(); i++) std::cout << sorted[i] << " ";
    std::cout << std::endl;

    return 0;
}