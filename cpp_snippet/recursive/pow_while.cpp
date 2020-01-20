#include <bits/stdc++.h>

int cnt = 0;  // 計算回数をカウント

/*
    べき乗 (x^n) を計算する
    計算量: O(log(n))

    - n は2役ある
        - 1ビットずつずらすことで計算回数を表す(n > 0 なら計算)
        - ビット表示することで，計算反映タイミングが分かる
            2^7 = 2^4 * 2^2 * 2^1 と分解できる（理由は下記）
                -> 0d7 = 0b0111 となり，1が立っているタイミングで反映させる（掛け算する）

    # reference
    <http://keita-matsushita.hatenablog.com/entry/2016/12/05/175024>
*/
long pow(long x, int n)
{
	long ans = 1;

    // n が0より大きいとまだ計算する
	while (n > 0) {
        cnt++;
        std::cout << "=== cnt: " << cnt << " ===" << std::endl;
        std::cout << std::bitset<8>(n) << std::endl;;

        // 1ビット目が1だったら計算に反映させる
		if ((n & 1) == 1) {
            std::cout << "ans: " << ans << " -> ";
			ans = ans * x;
            std::cout << ans << std::endl;
		}

        // x は自分を掛けることで計算回数を半減させるのに役立つ
        std::cout << "x: " << x << " -> ";
		x = x * x;  //一周する度にx, x^2, x^4, x^8となる
        std::cout << x << std::endl;

        // 1ビットずらすのがミソ
        std::cout << "n: " << n << " -> ";
		n >>= 1;
        std::cout << n << std::endl;
        std::cout << std::endl;
	}
	return ans;
}

int main()
{
    std::cout << pow(2, 7) << std::endl;
    return 0;
}