#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // input
    int N, K;
    std::cin >> N >> K;

    std::vector<int> v;
    for (int i = 0; i < N; i++)
    {
        int input_v;
        std::cin >> input_v;
        v.push_back(input_v);
    }

    // sort
    sort(v.begin(), v.end());

    // make diff vector
    std::vector<int> v_headless, v_diff;
    v_headless = v;
    v_headless.erase(v_headless.begin());

    for (int i = 0; i < v.size() - 1; i++)
    {
        v_diff.push_back(v_headless[i] - v[i]);
    }

    // find answer
    int ans = 1000000000;
    int h_diff = 0;
    for (int i = 0; i < v_diff.size() - (K-2); i++)
    {
        h_diff = 0;
        for (int j = i; j < i + (K-1); j++)
        {
            h_diff += v_diff[j];
        }
        ans = std::min(ans, h_diff);
    }

    std::cout << ans << std::endl;

    return 0;
}