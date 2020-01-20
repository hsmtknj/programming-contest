#include <iostream>
#include <stdio.h>
#include <stdarg.h>

/*
    平均を求める関数
        - 可変長の引数を受け取ることができる
*/
double average(int arg_length, ...)
{
    // (1) va_list型の arg に任意長の引数をまとめる
    //      - 任意長の引数リストのポインタを渡している
    //      - va_start(va_list リスト, prev)
    //          - prev には最後の固定引数を指定（可変引数のひとつ手前）
    va_list arg;
    va_start(arg, arg_length);

    // (2) va_arg を使って可変引数リストを取り出す
    double sum = 0;
    for (int i = 0; i < arg_length; i++)
    {
        double tgt_num = va_arg(arg, double);
        sum += tgt_num;
    }
    double ave = sum / (double)arg_length;

    // (3) ポインタを NULL にセット
    va_end(arg);

    return ave;
}

int main()
{
    double num = average(3, 3.0, 9.0, 12.0);
    std::cout << num << std::endl;
    return 0;
}