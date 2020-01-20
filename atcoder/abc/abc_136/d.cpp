#include <bits/stdc++.h>

int main()
{
    std::string S;
    std::cin >> S;

    int cnt = 0;
    int cnt_even = 0;
    int cnt_odd = 0;
    int ind = 0;
    bool flag_l_even = false;
    std::vector<int> ans(S.size(), 0);

    S.push_back('E');
    for (int i = 0; i < S.size() - 1; i++)
    {
        // カウントアップ
        if (cnt % 2 == 0) cnt_even++;
        else cnt_odd++;
        cnt++;

        // (R, L) の境目にきたらインデックスを保持
        if (S[i] == 'R' && S[i+1] == 'L')
        {
            // インデックス保持
            ind = i;

            // L が偶数だったら L(i+1) に cnt_even を設定する
            if (cnt % 2 == 0) flag_l_even = true;
        }

        // (L, R) の境目にきた or 最後まできたら子供の人数を格納
        if ( (S[i] == 'L' && S[i+1] == 'R') | (S[i] == 'L' && S[i+1] == 'E') )
        {
            if (flag_l_even == false)
            {
                ans[ind] = cnt_even;
                ans[ind+1] = cnt_odd;
            }
            else if (flag_l_even == true)
            {
                ans[ind] = cnt_odd;
                ans[ind+1] = cnt_even;
            }
            cnt_even = 0;
            cnt_odd = 0;
            cnt = 0;
            flag_l_even = false;
        }
    }

    // 結果表示
    for (int i = 0; i < ans.size(); i++) std::cout << ans[i] << " ";
    std::cout << std::endl;


    return 0;
}