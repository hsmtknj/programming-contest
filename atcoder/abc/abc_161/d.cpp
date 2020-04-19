#include <bits/stdc++.h>

int main()
{
    long long K;
    std::cin >> K;

    // キューに 1~9 までのルンルン数を入れる
    std::queue<long long> que;
    for (int i = 1; i <= 9; i++)
        que.push(i);

    // 下記をK回繰り返す
    // 1. キューからルンルン数を取り出す
    // 2. 取り出した値から新しいルンルン数を生成してキューに入れる
    long long x;
    for (int k = 1; k <= K; k++)
    {
        // ルンルン数をキューから取り出す
        x = que.front();
        que.pop();

        // 新しいルンルン数を追加する
        if (x%10 != 0) que.push(10*x + (x%10) - 1);
        que.push(10*x + (x%10));
        if (x%10 != 9) que.push(10*x + (x%10) + 1);
    }

    std::cout << x << std::endl;

    return 0;
}