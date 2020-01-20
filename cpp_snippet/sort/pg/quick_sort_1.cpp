#include <bits/stdc++.h>

void quick_sort(std::vector<int> &v, int left, int pivot, int right)
{
    // 最下層まで行ったら終了
    if (right - left <= 1) return;

    // ピボットソート
    // (1) ピボット値を保持して右端と交換
    int pivot_num = v[pivot];
    std::swap(v[pivot], v[right-1]);

    // (2) pivot左をpivot未満，pivot右をpivot以上にする
    int i = 0;  // 最終的な pivot 挿入位置
    for (int j = 0; j < right-1; j++)
    {
        if (v[j] >= pivot_num) continue;
        else
        {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right-1]);

    // 再帰関数
    int pivot_l = left + (pivot - left) / 2;
    int pivot_r = i+1 + (right - (i+1)) / 2;
    quick_sort(v, left, pivot_l, i);
    quick_sort(v, i+1, pivot_r, right);
}

int main()
{
    std::vector<int> v = {30, 88, 25, 17, 20};
    int pivot = v.size() / 2;
    quick_sort(v, 0, pivot, v.size());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}