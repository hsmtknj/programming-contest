/*
    二分探索
        - 二分探索実装テク
        <https://pyteyon.hatenablog.com/entry/2019/02/20/194140#C-%E3%81%A7%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2%E3%82%92%E5%AE%9F%E8%A3%85>
*/

#include <bits/stdc++.h>

bool binary_search(const std::vector<int> &v, int tgt_num)
{
    // ** 実装テク(1) **
    //      - right の初期値は N-1 ではなく N（配列外）
    int left = 0;
    int right = v.size();
    int mid;

    // ** 実装テク(3) **
    //      - 終了条件は left が right に追いついたとき
    while(right - left > 0)
    {
        // ** 実装テク(4) **
        //    - mid は切り捨てで求める
        mid = left + (right - left) / 2;
        
        if (v[mid] == tgt_num)
        {
            return true;
        }
        else if (v[mid] < tgt_num)
        {
            // ** 実装テク(2) **
            //      - 大きい側のときは +1
            //          - 左側は常に探索対象にしたい
            //          - +1していると右端まで行くと left = right となる
            left = mid + 1;
        }
        else if (v[mid] >= tgt_num)
        {
            right = mid;
        }
    }
    return false;
}

int main()
{
    std::vector<int> v = {1, 5, 24, 30, 40, 98};
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << binary_search(v, v[i]) << std::endl;
    }
    
    return 0;
}