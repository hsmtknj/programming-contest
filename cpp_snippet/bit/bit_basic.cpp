/*
    明日使えないすごいビット演算
    <https://www.slideshare.net/KMC_JP/slide-www>
*/

#include <iostream>
#include <bitset>
#include <limits.h>

int main()
{
    /* 基本演算 */
    std::cout << "=== 基本演算 ===" << std::endl;
    int a = 0x5;
    int b = 0x3;
    std::cout << "a: " << std::bitset<4>(a) << std::endl;
    std::cout << "b: " << std::bitset<4>(b) << std::endl;
    std::cout << std::endl;

    std::cout << "~a:  " << std::bitset<4>(~a) << std::endl;     // ビット反転: ~
    std::cout << "a&b: " << std::bitset<4>(a&b) << std::endl;    // ビット論理積 AND: &
    std::cout << "a|b: " << std::bitset<4>(a|b) << std::endl;    // ビット論理和 OR: |
    std::cout << "a^b: " << std::bitset<4>(a^b) << std::endl;    // ビット排他的論理和 XOR: ^
    std::cout << "b<<1: " << std::bitset<4>(b<<1) << std::endl;  // ビットシフト: <<
    std::cout << std::endl;


    int bit = 0x36;
    std::cout << "bit: "  << bit << ", " << std::bitset<8>(bit) << std::endl;

    /* AND */
    // 2つめのフラグを落とす
    std::cout << "bit & ~(1<<2): " << std::bitset<8>(bit & ~(1<<2)) << std::endl;
    
    // 2で割ったときの余り
    std::cout << "bit & 1: " << std::bitset<8>(bit & 1) << std::endl;

    // 1になっている一番下の桁を取得する
    std::cout << "bit & (~bit+1): " << std::bitset<8>(bit & (-bit)) << std::endl;

    // 1になっている一番下の桁を0にする
    std::cout << "bit & (bit-1): " << std::bitset<8>(bit & (bit-1)) << std::endl;


    /* OR */
    // 3つめのフラグを立てる
    std::cout << "bit | 1<<3: " << std::bitset<8>(bit | 1<<3) << std::endl;


    /* XOR */
    // 下位2ビットを反転
    std::cout << "bit ^ 0b0011: " << std::bitset<8>(bit ^ 0b0011) << std::endl;


    /* int(32bit) の最大 */
    unsigned int uint_data = 0xffffffff;
    std::cout << uint_data << std::endl;
    std::cout << UINT_MAX << std::endl;


    /* ビットの1の数を数える */
    int data = 0x7a;
    std::cout << "data: " << std::bitset<8>(data) << std::endl;
    int one_cnt = 0;
    while (data != 0)
    {
        data = data & (data - 1);
        std::cout << "data: " << std::bitset<8>(data) << std::endl;
        one_cnt++;
    }
    std::cout << one_cnt << std::endl;

    return 0;
}
