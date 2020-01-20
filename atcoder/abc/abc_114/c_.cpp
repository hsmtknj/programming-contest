// 全探索では間に合いません
// 10^8 を超える for では厳しい
// 先に "7", "5", "3" のみで構成される数字を列挙してから
// 7, 5, 3 を含む数字を探索するのが良い

#include <iostream>

int main()
{
    int N;
    int cnt = 0;
    int cnt7, cnt5, cnt3, cnt_others = 0;

    std::cin >> N;

    for (int n = 0; n < N; n++)
    {
        cnt7 = 0;
        cnt5 = 0;
        cnt3 = 0;
        cnt_others = 0;

        std::string s = std::to_string(n);
        for (int i = 0; i < s.length(); i++)
        {
            int num = (s[i] - '0');

            if (num == 7)
            {
                cnt7++;
            }
            else if (num == 5)
            {
                cnt5++;
            }
            else if (num == 3)
            {
                cnt3++;
            }
            else
            {
                cnt_others++;
                break;
            }
            
        }
        if (cnt7 > 0 && cnt5 > 0 && cnt3 > 0 && cnt_others == 0)
        {
            cnt++;
        }
    }
    
    std::cout << cnt << std::endl;

    return 0;
}
