#include <bits/stdc++.h>

void quick_sort(std::vector<int> &v, int left, int pivot, int right)
{
    // 底まで行ったら終了
    if (right - left <= 1) return;

    // (1) ピボット値を保持し，右端とスワップ
    int pivot_num = v[pivot];
    std::swap(v[pivot], v[right-1]);

    // (2) ピボット左がピボット未満，ピボット右がピボット以上になるようにソート
    int i = 0;  // 最終的にピボットを挿入する位置
    for (int j = 0; j < right - 1; j++)
    {
        if (v[j] >= pivot_num) continue;
        else
        {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right-1]);

    // (3) 左右に分けてさらにクイックソート
    int pivot_l = left + (pivot - left) / 2;
    int pivot_r = i+1 + (right - (i+1)) / 2;
    quick_sort(v, left, pivot_l, i);
    quick_sort(v, i+1, pivot_r, right);
}

int main()
{
    std::vector<int> v = {30, 88, 25, 17, 20};
    quick_sort(v, 0, 2, v.size());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;
    
    return 0;
}