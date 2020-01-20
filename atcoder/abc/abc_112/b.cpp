#include <iostream>
#include <vector>

int main()
{
    // input
    int N, T;
    std::vector<int> c, t;

    std::cin >> N >> T;

    for (int i = 0; i < N; i++)
    {
        int c_tmp, t_tmp;
        std::cin >> c_tmp >> t_tmp;

        c.push_back(c_tmp);
        t.push_back(t_tmp);
    }


    // ans
    int ans = 1000000000;

    for (int i = 0; i < N; i++)
    {
        if (t[i] <= T)
        {
            ans = std::min(ans, c[i]);
        }
    }

    if (ans == 1000000000)
    {
        std::cout << "TLE" << std::endl;
    }
    else
    {
        std::cout << ans << std::endl;
    }
    
    return 0;
}
