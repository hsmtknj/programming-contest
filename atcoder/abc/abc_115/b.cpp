#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> p;

    for (int i = 0; i < N; i++)
    {
        int p_tmp;
        std::cin >> p_tmp;

        p.push_back(p_tmp);
    }

    int total = std::accumulate(p.begin(), p.end(), 0);
    int max_price = *std::max_element(p.begin(), p.end());

    int ans = total - max_price / 2;

    std::cout << ans << std::endl;

    return 0;
}
