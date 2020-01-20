#include <iostream>
#include <bitset>

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main()
{
    // {1, 3, 5} にフラグがたったビット
    unsigned int bit = BIT_FLAG_1 | BIT_FLAG_3 | BIT_FLAG_5;
    std::cout << "{1, 3, 5} = " << std::bitset<8>(bit) << std::endl;

    // ビット {1, 3, 5} について，3番目のフラグが立っていること
    if (bit & BIT_FLAG_3)
    {
        std::cout << "3 is in " << std::bitset<8>(bit) << std::endl;
        std::cout << std::bitset<8>(bit&BIT_FLAG_3) << std::endl;
    }
    
    // ビット {1, 3, 5} について，0番目のフラグが立っていないこと
    if (!(bit & BIT_FLAG_0))
    {
        std::cout << "0 is not in " << std::bitset<8>(bit) << std::endl;
        std::cout << std::bitset<8>(!(bit&BIT_FLAG_0)) << std::endl;
    }

    // 新たなビット
    unsigned int bit2 = BIT_FLAG_0 | BIT_FLAG_3 | BIT_FLAG_4;
    std::cout << std::bitset<8>(bit) << " AND " << std::bitset<8>(bit2) << " : " << std::bitset<8>(bit & bit2) << std::endl;
    std::cout << std::bitset<8>(bit) << " OR " << std::bitset<8> (bit2) << " : " << std::bitset<8>(bit | bit2) << std::endl;

    // bit に6番目のフラグを立てる
    std::cout << "Befoer: " << std::bitset<8>(bit) << std::endl;
    bit |= BIT_FLAG_6;
    std::cout << "After:  " << std::bitset<8>(bit) << std::endl;

    // bit2 から3番目のフラグを消す
    std::cout << "Before: " << std::bitset<8>(bit2) << std::endl;
    bit2 &= ~BIT_FLAG_3;
    std::cout << "After : " << std::bitset<8>(bit2) << std::endl;

    return 0;
}
