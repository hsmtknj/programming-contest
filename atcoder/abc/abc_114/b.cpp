#include <iostream>

int main()
{
    const int REF_NUM = 753;
    int ans = 753;
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.length() - 2; i++)
    {
        int target_num = (s[i] - '0') * 100 + (s[i+1] - '0') * 10 + (s[i+2] - '0');
        ans = std::min(ans, std::abs(target_num - REF_NUM));
    }

    std::cout << ans << std::endl;

    return 0;
}
