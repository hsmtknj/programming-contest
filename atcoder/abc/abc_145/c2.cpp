#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>

double calc_dist(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    double dist = pow(dx * dx + dy * dy, 0.5);
    return dist;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> x(N);
    std::vector<int> y(N);
    std::vector<int> iter_array(N);
    double N_fact = 1;
    for (int i = 0; i < N; i++)
    {
        std::cin >> x[i] >> y[i];  // 入力
        iter_array[i] = i;         // 順列生成用配列
        N_fact *= i + 1;           // 階乗値
    }

    // solve
    double dist_sum = 0;
    do
    {
        for (int i = 0; i < iter_array.size() - 1; i++)
        {
            int ind = iter_array[i];
            int ind2 = iter_array[i + 1];
            double dist = calc_dist(x[ind], y[ind], x[ind2], y[ind2]);
            dist_sum += dist;
        }
    }
    while(next_permutation(iter_array.begin(), iter_array.end()));

    double ans = dist_sum / N_fact;
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;

    return 0;
}
