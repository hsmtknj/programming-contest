#include <bits/stdc++.h>

int main()
{
    /* INPUT */
    long long N, K;
    std::cin >> N >> K;
    std::vector<double> p(N);

    for (int i = 0; i < N; i++)
        std::cin >> p[i];

    /* SOLVE */
    int max_ind = -1;
    int accm_max = -1;
    int accm = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        cnt++;
        if (cnt < K)
            accm += p[i];
        else if (cnt == K)
        {
            accm += p[i];
            if (accm > accm_max)
            {
                accm_max = accm;
                max_ind = i;
            }
        }
        else if (cnt > K)
        {
            accm -= p[i-K];
            accm += p[i];
            if (accm > accm_max)
            {
                accm_max = accm;
                max_ind = i;
            }
        }
    }
    //std::cout << "max ind: " << max_ind << std::endl;

    double ans = 0;
    double exp_num = 0;
    for (int i = max_ind; i > max_ind - K; i--)
    {
        exp_num = (p[i] * (p[i]+1)) / 2 / p[i];
        ans += exp_num;      
    }
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;

    return 0;
}