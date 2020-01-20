/*
    <名称>
        クイックソート: quick sort
    <計算量>
        O(N^2)
    <特徴>
        - 内部ソートで Not 安定ソート
        - 速さは pivot の選び方に依存する
            - pivot による左右分割が真ん中だと最速の O(Nlog(N) となる
            - 逆に分割が完全に片方に偏ると最悪時間の O(N^2) となる
    <アルゴリズム>
        - 再帰関数で実装 (preorder)
        - (array, pivot, left, right）を引数として渡す
            - right は配列外を渡す
        - 入力配列の偏り対策としてピボットの選び方を乱拓化することは有効！！
*/

#include <bits/stdc++.h>

void quick_sort(std::vector<int> &v, int left, int pivot, int right)
{
    // ベースケース
    if (right - left <= 1) return;

    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "pivot:" << v[pivot] << std::endl;

    // クイックソート
    // ピボットと右端をスワップ
    int pivot_num = v[pivot];
    std::swap(v[pivot], v[right-1]);

    // ピボット左をピボット以下，ピボット右をピボット以上に並べ換え
    int i = left;
    int j = left;
    for (; j < right - 1; j++)
    {
        // std::cout << v[j] << ", " << pivot_num << std::endl;
        if (v[j] < pivot_num)
        {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right-1]);
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // 再帰関数を呼ぶ
    int pivot_left = left + (i - left) / 2;
    int pivot_right = i+1 + (right - (i+1)) / 2;
    std::cout << left << ", " << pivot_left << ", " << i << std::endl;
    std::cout << i+1 << ", " << pivot_right << ", " << right << std::endl;
    quick_sort(v, left, pivot_left, i);
    quick_sort(v, i+1, pivot_right, right);
}

int main()
{
    std::vector<int> v = {30, 88, 17, 12, 20, 25};
    int pivot = v.size() / 2;
    quick_sort(v, 0, pivot, v.size());

    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}