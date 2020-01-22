#include <iostream>

int main()
{
    // サイズ10の配列を宣言し，0で初期
    int a[10] = {};

    // 配列のサイズを取得する
    int len = sizeof(a) / sizeof(a[0]);

    return 0;
}