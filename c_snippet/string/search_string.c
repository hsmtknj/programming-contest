#include <stdio.h>
#include <string.h>

/* データ格納構造体 */
typedef struct
{
    char  *data;
} record;

/* 関数: 文字列探索 */
int search_string(record *array, int n, char *key)
{
    // 探索配列の長さが0なら終了
    if (n == 0) return -1;

    // 探索
    for (int i = 0; i < n; i++)
    {
        // 一致していたらインデックスを返す
        if (strcmp(array[i].data, key) == 0) return i;
    }
    return -1;
}

int main (void)
{
    // データ初期化
    record d[5] = {{"Alice"},
                   {"Bob"},
                   {"Cindy"},
                   {"Emily"},
                   {"David"}};
    int len = sizeof(d) / sizeof(d[0]);

    // 探索
    char *key = "Cindy";
    int ans = search_string(d, len, key);
    printf("answer: %d\n", ans);

    printf("END");
    return 0;
}