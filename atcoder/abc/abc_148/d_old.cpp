#include <bits/stdc++.h>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];

    std::sort(a.begin(), a.end());
    for (int i = 0; i < N; i++) std::cout << a[i] << " ";
    std::cout << std::endl;

    int cnt = 0;
    int keep_num = 0;
    for (int i = 0; i < N; i++)
    {
        int tgt_num = i+1;

        // 最初から1でなければ終了
        if (i == 0 && a[i] != 1)
        {
            cnt = -1;
            break;
        }
        // 最初が1のとき
        else if (i == 0 && a[i] == 1)
        {
            keep_num = 1;
        }
        // 重複を無視する
        else if (keep_num == a[i]) 
        {
            cnt++;
            continue;
        }
        // インクリメントされたら
        else if (keep_num + 1 == a[i])
        {
            keep_num = a[i];
            continue;
        }
        // 値が飛んだらそれ以降すべて落とす
        else if (keep_num + 1 < a[i])
        {
            cnt += (N - i);
            std::cout << N - i << std::endl;
            std::cout << N << std::endl;
            std::cout << i << std::endl;
            break;
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}