/**
 * [NOTE]
 * abs() の使い方でハマった
 *  - std::abs() を使え
 *      - std:: 空間だと std_abs.h 内の abs() が呼ばれ，"型" に対応できる
 *      - abs() を使うと stdlib.h 内の abs() が呼ばれ，"型が int" になるので注意
 * 
 * ※ using namespace std; としている場合は，abs() の記述で
 *   std::abs() が使用されるので，abs() の記述で問題なし
 */

#include <iostream>

int main()
{
    long long a = 999999482938498888;
    long double b = -1.23;

    // オーバーフロー
    std::cout << std::abs(a) << std::endl;
    std::cout << abs(a) << std::endl;

    // 小数点以下が切られる
    std::cout << std::abs(b) << std::endl;
    std::cout << abs(b) << std::endl;

    return 0;
}