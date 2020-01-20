#include <stdio.h>

/* 構造体1 */
// typedef していないので，宣言時に struct をつける
struct record1
{
    char data[65];
};

/* 構造体2 */
// typedef しているので，宣言時に struct は不要
typedef struct {
    char data[65];
} record2;

/* 生徒 */
struct student
{
    char name[65];
    int age;
};


int main()
{
    // 宣言方法の違い
    struct record1 r1;
    record2 r2;   // struct record2 r2; <- これはダメ

    // 構造体単体を初期化
    struct record1 r_simple = {"hoge"};
    printf("%s\n", r_simple.data);

    struct student st1 = {"Alice", 28};
    printf("%s, %d\n", st1.name, st1.age);

    // 構造体の配列を初期化
    struct student st_array[3] = {{"hoge", 20},
                                  {"fuga", 23},
                                  {"piyo", 25}};
                                  
    for (int i = 0; i < sizeof(st_array)/sizeof(st_array[0]); i++)
    {
        printf("%s, %d\n", st_array[i].name, st_array[i].age);
    }

    printf("END");
    return 0;
}