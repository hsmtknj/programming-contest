#include <bits/stdc++.h>

int main() {
    long long A, B, C, K;
    std::cin >> A >> B >> C >> K;

    if (A >= K) {
        std::cout << K << std::endl;
        return 0;
    }
    else if (K > A && K <= (A + B)) {
        std::cout << A << std::endl;
        return 0;
    }
    else if (K > (A + B) && K <= (A + B + C)) {
        std::cout << A - (K - A - B) << std::endl;
        return 0;
    }

    return 0;
}