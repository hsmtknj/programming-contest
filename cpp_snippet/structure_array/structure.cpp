#include <iostream>
#include <cstdio>
#include <string.h>

typedef struct
{
    char *name;
    int age;
} student;


// 構造体 単体, 値渡し
void func_simple1(student simple)
{
    std::cout << "Call by Value: " << simple.name << std::endl;
    simple.name = "Alice_changed";  // 値渡しなので変更は反映されない
}

// 構造体 単体, アドレス渡し
void func_simple2(student *simple)
{
    std::cout << "Call by Address: " << simple->name << std::endl;
    simple->name = "Alice_changed";  // アドレス渡しなので変更は反映される
}

// 構造体 単体, 参照渡し
void func_simple3(student &simple)
{
    std::cout << "Call by Reference: " << simple.name << std::endl;
    simple.name = "Alice_changed";  // 参照渡しなので変更は反映される
}

// 構造体 配列, 値渡し
void func_array1(student array[])
{
    std::cout << "Call by Value: " << array[0].name << std::endl;
    array[0].name = "Bob_changed";  // これは実はポインタが渡されており，書き換わる
}

// 構造体 配列, アドレス渡し
void func_array2(student *array)
{
    std::cout << "Call by Address: " << array[0].name << std::endl;
    array[0].name = "Bob_changed";  // アドレス渡しなので書き換わる
}

// 配列, 値渡し
void func_array_int1(int array[])
{
    std::cout << "Call by Value: " << array[0] << std::endl;
    array[0] = 100;  // これは実はポインタが渡されており，書き換わる
}

// 配列, アドレス渡し
void func_array_int2(int *array)
{
    std::cout << "Call by Address: " << array[0] << std::endl;
    array[0] = 100;  // アドレス渡しなので書き換わる
}


int main()
{
    /* 構造体を関数に渡す */
    // 単体を渡す
    std::cout << "=== 構造体（単体）を関数に渡す ===" << std::endl;
    student a1 = {"Alice", 28};
    func_simple1(a1);
    std::cout << "Call by Value: " << a1.name << std::endl;

    student a2 = {"Alice", 28};
    func_simple2(&a2);
    std::cout << "Call by Address: " << a2.name << std::endl;

    student a3 = {"Alice", 28};
    func_simple3(a3);
    std::cout << "Call by Reference: " << a3.name << std::endl;

    // 配列を渡す
    std::cout << "=== 構造体（配列）を関数に渡す ===" << std::endl;
    student b1[2] = {{"Bob", 25}, {"Cindy", 29}};
    func_array1(b1);
    std::cout << "Call by Value: " << b1[0].name << std::endl;

    student b2[2] = {{"Bob", 25}, {"Cindy", 29}};
    func_array2(b2);
    std::cout << "Call by Address: " << b2[0].name << std::endl;


    /* 配列を関数に渡す */
    std::cout << "=== int型 配列を関数に渡す ===" << std::endl;
    int c1[] = {10, 20};
    func_array_int1(c1);
    std::cout << "Call by Value: " << c1[0] << std::endl;

    int c2[] = {10, 20};
    func_array_int2(c2);
    std::cout << "Call by Address: " << c2[0] << std::endl;

    //std::cout << pa->name << std::endl;
    //std::cout << (*pa).name << std::endl;
    printf("END\n");
    return 0;
}
