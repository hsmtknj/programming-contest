#include <bits/stdc++.h>

int N;
std::vector<int> A;
std::vector<std::vector<int>> x;
std::vector<std::vector<int>> y;
int ans = 0;

void rec(std::vector<bool> v, int ind)
{
    // ベースケース
    // 最後まで行ったら判定
    if (ind == N)
    {
        // std::cout << std::endl;
        // std::cout << "======" << std::endl;
        // for (int i = 0; i < N; i++) std::cout << v[i] << " ";
        // std::cout << std::endl;

        // 成り立つか判定
        bool flag = true;
        int cnt = 0;
        // 正直者の証言が合っているか見たいので全員チェック
        for (int i = 0; i < N; i++)
        {
            // 証言が合わない場合は終了
            if (flag == false) break;

            // std::cout << i << "人目" << std::endl;
            // 正直者がいればそいつの証言をすべてチェック
            if (v[i] == true)
            {
                // std::cout << "in" << std::endl;
                // 正直者の数をカウント
                cnt++;

                // 正直者の証言をチェック
                for (int j = 0; j < A[i]; j++)
                {
                    // std::cout << v[ x[i][j]-1 ] << ", " << y[i][j] << std::endl;
                    if (v[ x[i][j]-1 ] != y[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        // 成立すれば格納
        if (flag == true)
        {
            if (ans < cnt) ans = cnt;
        }
    }
    else
    {
        std::vector<bool> v_t = v;
        v_t.push_back(true);
        std::vector<bool> v_f = v;
        v_f.push_back(false);

        rec(v_t, ind+1);
        rec(v_f, ind+1);
    }
}

int main ()
{
    // 入力
    std::cin >> N;
    A = std::vector<int>(N);
    x = std::vector<std::vector<int>>(N);
    y = std::vector<std::vector<int>>(N);

    for(int i = 0; i < N; i++)
    {
        int tgt_x;
        int tgt_y;
        std::cin >> A[i];

        for (int j = 0; j < A[i]; j++)
        {
            std::cin >> tgt_x >> tgt_y;
            x[i].push_back(tgt_x);
            y[i].push_back(tgt_y);
        }
    }

    // 問題を解く
    std::vector<bool> v;
    rec(v, 0);

    std::cout << ans << std::endl;

    return 0;
}