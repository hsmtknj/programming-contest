/*
    <名称>
        単純挿入ソート: straight insertion sort
    <計算量>
        O(N^2)
        [5,4,3,2,1] のような配列が最悪のケース
    <特徴>
        ・内部ソート
        ・安定ソート
        ・もともと整列済みの場合は高速 (O(N)かな？)
    <アルゴリズム>
        対象の値を，整列された配列の中で適切な位置に入れる
*/

#include <bits/stdc++.h>

int main()
{
    std::vector<int> v = {10, 2, 5, 8, 3, 9};

    for (int i = 1; i < v.size(); i++)
    {
        // 挿入対象の値を保持しておく（配列の中身が書き換わっていくので）
        int target = v[i];

        // 挿入位置 j を探索する
        int j = i;
        for (; j > 0; j--)
        {
            if (target < v[j-1])
            {
                v[j] = v[j-1];
            }
            else break;
        }
        v[j] = target;

        std::cout << "After Step " << i << ": ";
        for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
