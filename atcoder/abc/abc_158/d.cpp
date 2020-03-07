#include <bits/stdc++.h>

int main()
{
    std::string S;
    int Q;
    std::cin >> S;
    std::cin >> Q;

    std::vector<std::string> v;
    int direct = 0;  // 0:先頭が先頭, 1:末尾が先頭

    for (int i = 0; i < Q; i++)
    {
        int tgt;
        std::cin >> tgt;
    
        if (tgt == 1)
        {
            if (direct == 0)
                direct = 1;
            else if (direct == 1)
                direct = 0;
        }
        else if (tgt == 2)
        {
            int tgt2;
            std::string c;
            std::cin >> tgt2 >> c;

            // 先頭が先頭の場合
            if (direct == 0)
            {
                if (tgt2 == 1)
                    S = c + S;
                else if (tgt2 == 2)
                    S = S + c;
            }
            // 末尾が先頭の場合
            else if (direct == 1)
            {
                if (tgt2 == 1)
                    S = S + c;
                else if (tgt2 == 2)
                    S = c + S;
            }
        }
    }
    if (direct == 0)
        std::cout << S << std::endl;
    else
    {
        // std::string tmp = "";
        // for (int i = S.size()-1; i >= 0; i--)
        //     tmp = tmp + S[i];
        int left = 0;
        int right = S.size()-1;

        while (right - left > 0)
        {
            std::swap(S[left], S[right]);
            left++;
            right--;
        }
        std::cout << S << std::endl;
    }
    
    return 0;
}