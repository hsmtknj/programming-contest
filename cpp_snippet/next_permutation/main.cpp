/*
順列生成: next_permutation
<https://qiita.com/siser/items/a91022071b24952d27d9>

USAGE:
    1. 順列生成したい配列をソートする
    2. do-while() の while() にnext_permutation() を入れる
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    // 配列は昇順でソートする
    std::vector<int> v = {1, 2, 3};
    do
    {
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i];
            if (i != v.size() - 1)
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    while(next_permutation(v.begin(), v.end()));

    return 0;
}