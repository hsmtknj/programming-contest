#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // sizeof() はその型のバイト数を返す
    std::cout << "int: " << sizeof(int) << " byte" << std::endl;

    // sizeof() の返り値は基本 size_t 型で受ける
    //      - size_t の大きさは環境依存 (プリミティブ型ではなくtypedef)
    //      - size_t は符号なし
    size_t size = sizeof(long);
    std::cout << "long: " <<  size << " byte" << std::endl;

    // sizeof() と配列
    // サイズは sizeof(要素型) * 要素数 となる
    int a[10];
    size = sizeof(a);
    std::cout << "a[10]: " << size << " byte" << std::endl;

    return 0;
}
