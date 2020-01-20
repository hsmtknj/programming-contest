#include <iostream>
#include <string.h>

/* データの構造体 */
typedef struct
{
    const char *data;
} record_t;


/* データ配列からkeyがあるかどうかを探索する関数
    keyと一致するインデックスを返す
    なければ，-1を返す
*/
int string_search(record_t *d, int array_len, const char *key)
{
    // 線形探索
    for (int i = 0; i < array_len; i++)
    {
        if (strcmp(d[i].data, key) == 0) return i;
    }

    // なければ -1 を返す
    return -1;
}


int main()
{
    // データ配列を定義
    record_t d[5] = {{"Alice"},
                     {"Bob"},
                     {"Cindy"},
                     {"David"},
                     {"Emily"}};
    int array_len = sizeof(d) / sizeof(d[0]);
    const char *key = "Cindy";

    // key を探索
    int ind = string_search(d, array_len, key);
    std::cout << "index: " << ind << std::endl;

    return 0;
}