#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>

int main()
{
    int N;
    std::cin >> N;

    std::vector<double> x(N);
    std::vector<double> y(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> x[i] >> y[i];
    }
    // for (int i = 0; i < N; i++)
    // {
    //     std::cout << x[i] << ", " << y[i] << std::endl;
    // }

    // solve
    // std::cout << "SOLVE" << std::endl;
    int fact_num = 1;
    for (int i = 2; i <= N; i++)
    {
        fact_num *= i;
    }
    int fact_num2 = 1;
    for (int i = 2; i <= N-1; i++)
    {
        fact_num2 *= i;
    }
    // std::cout << fact_num << ", " << fact_num2 << std::endl;

    double dist_sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            // std::cout << i << ", " << j << std::endl;
            // dist = sqrt( pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2) );
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double dist = pow(dx * dx + dy * dy, 0.5);
            // std::cout << dist << std::endl;
            dist_sum += dist;

        }
    }

    // double ans = dist_sum * (double)fact_num2 * 2 / (double)fact_num;
    double ans = dist_sum * 2 / (double)N;
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;

    return 0;
}
