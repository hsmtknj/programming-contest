/*
    <名称>
        マージソート: merge sort
    <計算量>
        O(Nlog(N))
    <特徴>
        - 外部ソートで安定ソート
        - メモリを使うが，現在は潤沢にメモリを使えるため，ほとんど問題なし
        - 実用的なアルゴリズムだが，クイックソートのが高速なことが多い
            - ただし，クイックソートは安定ではない！！
    <アルゴリズム>
        - 再帰関数で実装（postorder）
        - (array, left, right）を引数として渡す
            - right は配列外を渡す
*/

#include <bits/stdc++.h>

void merge_sort(std::vector<int> &v, int left, int right)
{
    std::cout << left << ", " << right << std::endl;
    // ベースケース
    if (right - left == 1) return;

    // 中間インデックスを計算
    int mid = left + (right - left) / 2;

    // 再帰に底まで探索
    merge_sort(v, left, mid);   // 左側をソート
    merge_sort(v, mid, right);  // 右側をソート

    // 左右ソートが終わった or 底まで行ったら マージ
    std::cout << std::endl;
    std::cout << "left:" << v[left] << "[" << left << "]" << ", right:" << v[right - 1] << "[" << right-1 <<"]" << std::endl;

    std::vector<int> buf;
    for (int i = left; i < mid; i++) buf.push_back(v[i]);
    for (int i = right - 1; i >= mid; i--) buf.push_back(v[i]);
    
    std::cout << "buf:";
    for (int i = 0; i < buf.size(); i++) std::cout << buf[i] << " ";
    std::cout << std::endl;

    int buf_iter_left = 0;
    int buf_iter_right = right - left - 1;
    std::cout << "buf_iter_left:" << buf_iter_left << ", " << "buf_iter_right:" << buf_iter_right << std::endl;
    for(int i = left; i < right; i++)
    {
        if (buf[buf_iter_left] <= buf[buf_iter_right])
        {
            v[i] = buf[buf_iter_left];
            buf_iter_left++;
        }
        else
        {
            v[i] = buf[buf_iter_right];
            buf_iter_right--;
        }
    }
    std::cout << "sorted: ";
    for (int i = left; i < right; i++) std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

}

int main()
{
    std::vector<int> v = {30, 88, 17, 12, 20, 25};
    merge_sort(v, 0, v.size());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
