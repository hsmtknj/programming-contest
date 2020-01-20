#include <iostream>
#include <string>

int main(void) {
    int cnt = 0;
    std::string S;
    std::string T;

    std::cin >> S;
    std::cin >> T;

    for (int i = 0; i < 3; i++) {
        if (S[i] == T[i]) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}
