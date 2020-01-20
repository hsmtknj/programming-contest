#include <stdio.h>

int func1 (int *x)
{
    int ans = *x + *x;
    return ans;
}


int func2 (int *x)
{
    return 0;
}


int main (void)
{
    int num = 10;
    int ans = func1(&num);
    printf("%d\n", ans);
    return 0;
}