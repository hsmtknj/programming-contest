#include <bits/stdc++.h>

int main()
{
    int N = 10;

    // 通常のfor:
    //      i=10で条件に入らないので，iは10まで行く
    int i;
    for (i = 0; i < N; i++)
    {
        continue;
    }
    std::cout << i << std::endl;

    // breakのfor: 
    //      breakした時点でforから抜けるので，そのステップではj++は実行されない
    //      つまり下記ではjは5
    int j;
    for (j = 0; j < N; j++)
    {
        if (j == 5) break;
    }
    std::cout << j << std::endl;

    return 0;
}