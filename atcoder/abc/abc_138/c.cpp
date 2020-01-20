#include <iostream>
#include <vector>

int main () {
    int N;
    std::cin >> N;
    std::vector<double> v;
    double tmp_v;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp_v;
        v.push_back(tmp_v);
    }

    std::sort(v.begin(), v.end());
    // std::sort(v.begin(), v.end(), std::greater<double>());
    // for (int i = 0; i < N; i++)
    // {
    //     std::cout << v[i] << std::endl;
    // }

    double s = (v[0] + v[1]) / 2;
    for (int i = 2; i < N; i++)
    {
        s = (s + v[i]) / 2;
    }

    std::cout << s << std::endl;
}
