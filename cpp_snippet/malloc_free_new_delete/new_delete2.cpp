#include <iostream>

int main()
{
    // ポインタを宣言
    int *p1;

    // メモリ確保（実体化）
    p1 = new int;
    *p1 = 1000;
    std::cout << *p1 << std::endl;

    // 一度解放
    delete p1;

    // 再メモリ確保（再実体化）
    p1 = new int;
    *p1 = 2000;
    std::cout << *p1 << std::endl;

    // ポインタ2を用意して，ポインタ1のアドレスを渡し，delete
    int *p2;
    p2 = p1;
    delete p2;

    // メモリ解放はされたが，まだ書き換わっていないため値は出る？
    // これは異常な動作？
    std::cout << *p1 << std::endl;

    return 0;
}