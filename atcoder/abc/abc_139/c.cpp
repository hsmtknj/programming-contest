// ============================================================================
// # Explanation:
//      隣接する配列との差分を確認し，正の区間が最も長く続くところを見つければ良い
//      e.g. 10, 4, 8, 7, 3
//           -> diff 6, -4, 1, 4
//           -> Answer 2 (1, 4の区間が最も長い)      
// # Note:
//      配列において，次の値と比較する系の問題
//      次の値が小さければ移動できるので，"i >= i+1" が成立し続ければ大きくなる
//      
//      ひとつひとつの値について何回移動できるか計算する全探索を実施すると，
//      解は得られるが，時間が足りないと思うので，計算を軽くする工夫が必要がある．
//
//      隣接する配列系はとりあえず "引いて" みてはどうか．
// ============================================================================

#include <iostream>
#include <vector>

int main()
{
    int N;
    std::vector<int> v;

    // input
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp_in;
        std::cin >> tmp_in;
        v.push_back(tmp_in);
    }

    // find answer
    int v_diff[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        v_diff[i] = v[i] - v[i + 1];
    }

    int cnt = 0;
    int cnt_max = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (v_diff[i] >= 0)
        {
            cnt++;
            if (cnt_max < cnt)
            {
                cnt_max = cnt;
            }
        }
        else
        {
            cnt = 0;
        }
    }

    std::cout << cnt_max << std::endl;
}
