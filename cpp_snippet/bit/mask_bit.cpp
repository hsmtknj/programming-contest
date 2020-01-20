#include <iostream>
#include <bitset>

const unsigned int BIT_FLAG_DAMAGE = (1 << 0);     // HPが満タンでないか（ダメージをくらっているか）
const unsigned int BIT_FLAG_DOKU = (1 << 1);       // 毒状態になっているか
const unsigned int BIT_FLAG_MAHI = (1 << 2);       // 麻痺状態になっているか
const unsigned int BIT_FLAG_SENTOFUNO = (1 << 3);  // 戦闘不能状態になっているか

// atack して，単にダメージを受ける
const unsigned int MASK_ATTACK = BIT_FLAG_DAMAGE;

// punch して，ダメージも受けて，麻痺もする
const unsigned int MASK_PUNCH = BIT_FLAG_DAMAGE | BIT_FLAG_MAHI;

// defeat して，相手のHPを 0 にする
const unsigned int MASK_DEFEAT = BIT_FLAG_DAMAGE | BIT_FLAG_SENTOFUNO;

// 「毒」と「麻痺」を回復させる: ~MASK_DOKU_MAHI をかけることで回復
const unsigned int MASK_DOKU_MAHI = BIT_FLAG_DOKU | BIT_FLAG_MAHI;

int main()
{
    // start: 0000, 初期状態
    unsigned int status = 0;
    std::cout << "start: " << std::bitset<4>(status) << std::endl;

    // attacked: 0001 になる
    status |= MASK_ATTACK;
    std::cout << "attacked: " << std::bitset<4>(status) << std::endl;

    // punched: 0101 になる，HPはすでに満タンではないので，BIT_FLAG_DAMAGE の部分は変化なし
    status |= MASK_PUNCH;
    std::cout << "punched: " << std::bitset<4>(status) << std::endl;

    // kaifuku: 0001 にする，HPは回復しない，麻痺は回復する
    status &= ~MASK_DOKU_MAHI;
    std::cout << "kaifuku: " << std::bitset<4>(status) << std::endl;

    // defeat: 1001 にする，戦闘不能にする
    status |= MASK_DEFEAT;
    std::cout << "defeat: " << std::bitset<4>(status) << std::endl;

    // kaifuku: 1001 のまま，戦闘不能状態は回復しない
    status &= ~MASK_DOKU_MAHI;
    std::cout << "sentofuno no mama: " << std::bitset<4>(status) << std::endl;
    
    if (status & BIT_FLAG_SENTOFUNO)
    {
        std::cout << "sentofuno" << std::endl;
    }

    if (!(status & BIT_FLAG_MAHI))
    {
        std::cout << "not mahi" << std::endl;
    }

    return 0;
}