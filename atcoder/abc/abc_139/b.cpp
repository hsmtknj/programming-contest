#include <iostream>

int main(void) {
    int outlet_total = 0;
    int cnt = 0;
    int A;
    int B;

    std::cin >> A >> B;

    while(1) {  
        outlet_total = (A - 1) * cnt + 1;
        if (outlet_total >= B) {
            break;
        }
        cnt++;
    }

    std::cout << cnt << std::endl;
}
