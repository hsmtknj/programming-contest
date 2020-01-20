#include <bits/stdc++.h>

void merge_sort(std::vector<int> &v, int left, int right)
{
    // ベースケース
    if (right - left == 1) return;

    // 中間インデックスを求める
    int mid = left + (right - left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid, right);

    // マージソート
    std::vector<int> buf;
    for (int i = left; i < mid; i++) buf.push_back(v[i]);
    for (int i = right-1; i >= mid; i--) buf.push_back(v[i]);

    int l_ind = 0;
    int r_ind = right - left - 1;
    for (int i = left; i < right; i++)
    {
        if (buf[l_ind] <= buf[r_ind])
        {
            v[i] = buf[l_ind];
            l_ind++;
        }
        else
        {
            v[i] = buf[r_ind];
            r_ind--;
        }
    }
}

int main()
{
    std::vector<int> v = {30, 88, 25, 17, 20};
    merge_sort(v, 0, v.size());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}