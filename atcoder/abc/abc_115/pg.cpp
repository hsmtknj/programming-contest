#include <iostream>
#include <vector>
#include <numeric>
#include <typeinfo>
#include <math.h>

unsigned int factorial(int num);

int main() 
{
    int N = 6;
    int K = 3;
    // std::vector<int> v = {1, 2, 5, 9, 10, 11};
    std::vector<int> v = {5, 11, 1, 9, 10, 2};

    // sort
    std::sort(v.begin(), v.end());

    // make diff vector
    std::vector<int> v_headless, v_diff;
    v_headless = v;
    v_headless.erase(v_headless.begin());

    for (int i = 0; i < v.size() - 1; i++)
    {
        v_diff.push_back(v_headless[i] - v[i]);
    }

    // find answer
    std::cout << "find answer" << std::endl;
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

