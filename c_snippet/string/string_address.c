#include <stdio.h>

char *puts1()
{
    char *s = "Hello";
    return s;
}

// これだと関数を抜けるタイミングで 変数s が解放され未定義の動作をまねく
/*
char puts2()
{
    char s[] = "World";
    return s;
}
*/

int main ()
{
    /* 下記では同じように使える */
    char a[] = "Hello";
    char *b = "World";
    printf("%s\n", a);
    printf("%s\n", b);

    printf("%s\n", puts1());

    return 0;
}
