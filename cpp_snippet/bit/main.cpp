#include <iostream>
#include <bitset>

int main()
{
    // ========================================================================
    // ビット演算 基本
    // ========================================================================

    int a = 45;
    int b = 25;
    bool bl = true;

    // AND:&, OR:|, NOT:~(!), XOR:^
    std::cout << a << " AND " << b << " : " << (a&b) << std::endl;
    std::cout << a << " OR " << b << " : " << (a|b) << std::endl;
    std::cout << a << " NOT (ビット否定)) : " << ~a << std::endl;
    std::cout << bl << " NOT (論理否定) : " << !bl << std::endl;
    std::cout << a << " XOR " << b << " : " << (a^b) << std::endl;
    

    // ========================================================================
    // std::bitset 見やすい出力ができる
    // ========================================================================

    int A = 0x2d;
    int B = 0x19;
    std::cout << A << " AND " << B << " : " << (A&B) << std::endl;
    std::cout << std::bitset<8>(A) << " AND " << std::bitset<8>(B) << " : " << std::bitset<8>(A&B) << std::endl;


    // ========================================================================
    // ビットシフト演算子
    // ========================================================================

    int c = 0b00000011;
    int d = c << 2;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}
