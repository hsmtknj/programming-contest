/*
    unsigned exponentiol golomb coding : 符号無し指数ゴロム符号
        - ビット演算で符号化を実装
*/

#include <iostream>
#include <cstdio>
#include <bitset>

int main ()
{
    const int BIT_NUM = 32;
    unsigned int stream = 0x23de9b42;
    // unsigned int stream = 0;
    // unsigned int stream = 0b001001101101101011000100100101;
    std::cout << std::bitset<BIT_NUM>(stream) << std::endl;

    /* 符号化 */
    int i = BIT_NUM - 1;  // 最上位ビットにセット
    int zero_cnt = 0;     // ゼロカウンタ

    // 最上位ビットから走査
    while (i >= 0)
    {
        // ビット抽出
        unsigned int tgt_num = (stream>>i) & 1;

        // 0のときはゼロカウンタをカウントアップしてインデックスを進める
        if (tgt_num == 0)
        {
            zero_cnt++;
            i--;
        }
        // 1のときは符号化
        else if (tgt_num == 1)
        {
            // ゼロカウンタから分かるサイズ分を下位ビットに集める
            unsigned int decoded;
            if (i - zero_cnt >= 0) decoded = stream>>(i-zero_cnt);
            else decoded = stream<<(zero_cnt-i);

            // マスク処理でサイズ分取り出す
            unsigned int bit_mask = (1<<(zero_cnt*2+1)) - 1;
            decoded = decoded & bit_mask;
            std::cout << std::bitset<BIT_NUM>(decoded) << ": " << decoded - 1 << std::endl;

            // インデックスとカウンタを更新
            i = i - zero_cnt - 1;
            zero_cnt = 0;
        }
    }

    // ゼロを数えている途中で終了した場合
    if (zero_cnt != 0) std::cout << std::bitset<BIT_NUM>(0) << ": " << 0 << std::endl;

    return 0;
}