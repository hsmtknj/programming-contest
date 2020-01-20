#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<double> v;
    double tmp_v;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp_v;
        v.push_back(tmp_v);
    }

    double s = 0;
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        s += 1 / v[i];
    }
    ans = 1 / s;

    std::cout << ans << std::endl;

}