#include <bits/stdc++.h>

std::vector<std::vector<long long>> comb(long long n, long long r) {
  std::vector<std::vector<long long>> v(n + 1,std::vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

long long Combination (long long n, long long r)
{
    std::vector<std::vector<long long>> v = comb(n ,r);
    return v[n][r];
}

long long Factorial(long long n)
{
    if (n == 0) return 1;
    else if (n == 1) return 1;
    else if ((n & 1) == 0) return std::pow(Factorial(n / 2), 2) * Combination(n, n / 2);
    else return std::pow(Factorial(n / 2), 2) * Combination(n, n / 2) * (n - n / 2);
}

void rec(long long &ans, long long x, long long n)
{
    if (n <= 0) return;
    else
    {
        // 1ビット目が1のときに掛け算する
        if ((n & 1) == 1) ans *= x; 

        // xは自乗していく
        x *= x;

        // nは1ビットずらす
        //  - 計算回数がわかる
        //  - 掛け算するタイミングが分かる
        n >>= 1;

        // 再帰関数
        rec(ans, x, n);
    }
}

// べき乗 x^n を求める
long long my_pow(long long x, long long n)
{
    long long ans = 1;
    rec(ans, x, n);
    return ans;
}

int permutationMethod(int n,int r){
    r = n - r;
    int sum = 1;
    int i;
    for (i=n;i>=r+1;i--)sum*=i;
    return sum;
}


int main()
{
    int N;
    std::cin >> N;

    // 偶数のとき
    long long num = 0;
    if (N % 2 == 0)
    {
        long long k = N / 2;
        num = my_pow(2, k) * Factorial(k);
    }
    // 奇数のとき
    else if (N % 2 == 1)
    {
        long long k = (N + 1) / 2;
        num = permutationMethod(2*k, k) / my_pow(2, k);
    }

    std::string s = std::to_string(num);
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '0') cnt++;
        else break;
      // std::cout << s[i] << std::endl;
    }
    std::cout << cnt << std::endl;

    return 0;
}
