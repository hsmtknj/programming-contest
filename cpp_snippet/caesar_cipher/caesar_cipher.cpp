/*
    シーザー暗号: Caesar Cipher
    大文字のみ対応
*/

#include <bits/stdc++.h>

int main()
{
    // 文字列 s を key 分だけずらす
    std::string s = "ABC";
    int key = 3;

    // 符号化した文字列格納用
    std::string encoded = "";
    for (int i = 0; i < s.size(); i++)
    {
        // ずらす分を計算
        // ASCIIコードで 'A': 65, 'a':97 となる
        int step = (s[i] - 'A' + key) % 26;
        encoded += ('A' + step);
    }

    for (int i = 0; i < encoded.size(); i++) std::cout << encoded[i];
    std::cout << std::endl;


    // おまけ
    std::string t = "ABC";
    t[0] = 97;  // 97は ASCIIコードで 'a' を指す
    for (int i = 0; i < t.size(); i++) std::cout << t[i];
    std::cout << std::endl;

    return 0;
}