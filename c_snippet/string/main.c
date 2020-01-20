#include <stdio.h>
#include <string.h>

int main (void)
{
    /* char は1文字を格納するデータ型 */
    char one_char = 'a';
    printf("one character: %c\n", one_char);  // 1文字のときは %c を使う

    /* char で文字列の宣言 */
    char str[] = "hoge";  // 文字列なので "配列" で宣言
    printf("string: %s\n", str);

    /* charのポインタでの宣言の方が使うかも */
    char *pstr = "hogehoge";
    printf("string: %s\n", pstr);

    /* char の文字コード */
    printf("character map of 'a': %d\n", one_char);  // 実態は数字

    /* char で1文字ずつで文字列を宣言 */
    char str2[] = "abcde";
    printf("%s\n", str2);
    for (int i = 0; i < strlen(str2); i++)
    {
        printf("%c ", str2[i]);
    }
    printf("\n");

    /* 文字列を扱うにあたっての関数 */

    // strlen: 長さ
    char a[] = "Hello";
    int len = strlen(a);
    printf("string length: %d\n", len);

    // strcpy: 文字列のコピー
    char b[256];
    strcpy(b, a);
    printf("b: %s\n", b);

    // strncpy: 指定数分の文字列をコピー
    char c[256];
    strncpy(c, a, 3);
    printf("c: %s\n", c);

    // strcat: 文字列の結合
    char d[256];
    strcpy(d, a);
    char e[] = "World";
    strcat(d, e);
    printf("%s\n", d);

    // strcmp: 文字列の比較
    int ans = strcmp("Hello", "Hello");
    printf("%d\n", ans);

    return 0;
}