#include <iostream>

int main()
{
    // ポインタを宣言
    int *p1;
    int *p2;

    // 実体化（メモリの確保）
    p1 = new int;
    p2 = new int[100];  // バイト数ではなく要素数

    *p1 = 1000;
    p2[0] = 1500;
    *(p2 + 1) = 2000;  // p[1] = 2000; と同じ

    std::cout << *p1 << std::endl;
    std::cout << p2[0] << std::endl;
    std::cout << p2[1] << std::endl;

    // メモリの解放
    delete p1;
    delete[] p2;  // 配列は [] をつける

    return 0;
}