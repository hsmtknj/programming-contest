#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main()
{
    /* 100 のサイズで動的にメモリを確保する */
    int n = 100;
    int *ap = (int*)malloc(sizeof(int) * n);

    /* 初期化 */
    memset(ap, 0, sizeof(int)*n);

    /* 配列を使ってみる */
    std::cout << ap[0] << std::endl;
    std::cout << ap[50] << std::endl;
    
    // 配列25を書き換えてみる
    ap[25] = 1000;
    std::cout << ap[25] << std::endl;
    *(ap + 25) = 2000;
    std::cout << ap[25] << std::endl;

    // ap[1000] = 1000; とかも，範囲外アクセスだがコンパイルエラーにはならない

    // メモリの解放
    free(ap);

    return 0;
}
