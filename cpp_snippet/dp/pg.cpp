
/*
        parrot.c
        プログラムに渡された引数をそのまま出力するプログラム
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
        int i;

        /* 引数の個数分繰り返す */
        /* argv[0]はプログラム名なのでiは1から始める */
        for (i=1;i<argc;i++) {

                /* 引数を出力 */
                printf("%s", argv[i]);

                /* 最後の引数以外は区切りの半角スペースを出力 */
                if (i < argc - 1) {
                        printf(" ");
                }
        }
        printf("¥n");
}
