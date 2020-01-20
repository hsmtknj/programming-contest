#include <iostream>
#include <vector>

int main()
{
    int N;
    int K;

    // input
    std::cin >> N >> K;
    std::vector<int> v(N);

    for (int i = 0; i < v.size(); i++)
    {
        int h;
        std::cin >> h;
        v[i] = h;
    }

    // solve
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] >= K)
        {
            cnt++;
        }
    }

    // answer
    std::cout << cnt << std::endl;
}
