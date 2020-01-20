#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // input
    int N;
    std::vector<int> x, y, h;

    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x_input, y_input, h_input;
        std::cin >> x_input >> y_input >> h_input;

        x.push_back(x_input);
        y.push_back(y_input);
        h.push_back(h_input);
    }

    // answer
    // if (N == 1)
    // {
    //     std::cout << x[0] << " " << y[0] << " " << h[0] << std::endl;
    // }
    if (N >= 1)
    {
        int H_target, H_pre;
        int count = 0;

        for (int cx = 0; cx <= 100; cx++)
        {
            for (int cy = 0; cy <= 100; cy++)
            {
                // compute H for each n combinations
                // and if all H are same numbers, that is an answer
                for (int n = 0; n < N; n++)
                {
                    H_target = abs(x[n] - cx) + abs(y[n] - cy) + h[n];

                    if (n == 0)
                    {
                        H_pre = H_target;
                    }
                    else if (n > 0)
                    {
                        if (H_target == H_pre)
                        {
                            count++;
                            H_pre = H_target;
                        }
                        else
                        {
                            count = 0;
                            break;
                        }
                    }
                }

                if (count == N - 1)
                {
                    std::cout << cx << " " << cy << " " << std::max(H_target, 0) << std::endl;
                }
            }
        }
    }

    return 0;
}
