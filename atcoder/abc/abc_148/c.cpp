#include <bits/stdc++.h>

int main(void)
{
 
  long long a, b, r, x, tmp;
  std::cin >> a >> b;
 
  x = a * b;
 
  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
 
  /* 最小公倍数を出力 */
  std::cout << x/b << std::endl;
//   printf("最小公倍数 = %d\n", x/b);
 
  return 0;
}
