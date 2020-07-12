#include <bits/stdc++.h>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S.size() + 1 != T.size()) {
        std::cout << "No" << std::endl;
        return 0;
    }

    for (int i = 0; i < S.size(); i++) {
        if (S[i] != T[i]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }

    std::cout << "Yes" << std::endl;
    return 0;
}
