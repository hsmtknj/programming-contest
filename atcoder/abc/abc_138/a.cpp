#include <iostream>
#include <string>

int main() {
    int a;
    std::string s;

    std::cin >> a;
    std::cin >> s;

    if (a >= 3200) {
        std::cout << s << std::endl;
    }
    else if (a < 3200) {
        std::cout << "red" << std::endl;
    }
}
