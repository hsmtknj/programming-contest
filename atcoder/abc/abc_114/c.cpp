#include <iostream>
#include <vector>

void dfs753(std::vector<int> &list, int N, std::string s);

int main()
{
    int N;
    int cnt = 0;
    std::cin >> N;

    // find number including only 7, 5, 3
    std::vector<int> list;
    dfs753(list, N, "");

    // find answer
    for (int i = 0; i < list.size(); i++)
    {
        int cnt3 = 0;
        int cnt5 = 0;
        int cnt7 = 0;
        int cnt_others = 0;
        std::string s;
        s = std::to_string(list[i]);

        for (int j = 0; j < s.length(); j++)
        {
            int n_target_digit = (s[j] - '0');

            if (n_target_digit == 3)
            {
                cnt3++;
            }
            else if (n_target_digit == 5)
            {
                cnt5++;
            }
            else if (n_target_digit == 7)
            {
                cnt7++;
            }
            else
            {
                cnt_others++;
            }
        }

        if (cnt3 > 0 && cnt5 > 0 && cnt7 > 0 && cnt_others == 0)
        {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}

void dfs753(std::vector<int> &list, int N, std::string s)
{
    std::string s_tmp;
    int n_tmp;

    if (s.length() <= 8)
    {
        s_tmp = s + '3';
        n_tmp = std::stoi(s_tmp);
        if (n_tmp <= N)
        {
            list.push_back(n_tmp);
            dfs753(list, N, s_tmp);
        }

        s_tmp = s + '5';
        n_tmp = std::stoi(s_tmp);
        if (n_tmp <= N)
        {
            list.push_back(n_tmp);
            dfs753(list, N, s_tmp);
        }

        s_tmp = s + '7';
        n_tmp = std::stoi(s_tmp);
        if (n_tmp <= N)
        {
            list.push_back(n_tmp);
            dfs753(list, N, s_tmp);
        }
    }
};
