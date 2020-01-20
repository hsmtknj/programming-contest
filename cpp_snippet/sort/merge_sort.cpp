#include <bits/stdc++.h>

void merge_sort(std::vector<int> &v, int left, int right)
{
    // ベースケース
    if (right - left == 1) return;

    // 中間インデックス計算
    int mid = left + (right - left) / 2;

    // 再帰関数
    merge_sort(v, left, mid);
    merge_sort(v, mid, right);

    // 左右のマージが終わる or 底まで行ったら マージ
    std::vector<int> buf;
    for (int i = left; i < mid; i++) buf.push_back(v[i]);
    for (int i = right - 1; i >= mid; i--) buf.push_back(v[i]);

    int buf_left = 0;
    int buf_right = right - left - 1;
    for (int i = left; i < right; i++)
    {
        if (buf[buf_left] <= buf[buf_right])
        {
            v[i] = buf[buf_left];
            buf_left++;
        }
        else
        {
            v[i] = buf[buf_right];
            buf_right--;
        }
    }
}

int main()
{
    std::vector<int> v = {30, 88, 17, 12, 20, 25};
    merge_sort(v, 0, v.size());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
