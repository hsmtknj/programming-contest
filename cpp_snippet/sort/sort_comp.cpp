/*
    比較関数を使えば「50に近い順」とかもできる
*/

#include <bits/stdc++.h>

struct Student
{
    std::string name;
    int id;
};

bool comp_student(const Student& a, const Student& b)
{
    if (a.id < b.id) return true;
    else return false;
}

bool comp(int a, int b)
{
    int N = 50;
    if (abs(a - N) < abs(b - N)) return true;
    else return false;
}

int main()
{
    std::vector<int> v = {30, 17, 88, 12, 20, 25};

    // ascending order
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // descending order
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // order (near 50)
    std::sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    // order (student)
    Student a, b, c;
    a.name = "Alice";
    a.id = 2;
    b.name = "Bob";
    b.id = 1;
    c.name = "Cindy";
    c.id = 3;
    std::vector<Student> vec = {a, b, c};

    for (int i = 0; i < vec.size(); i++) std::cout << vec[i].name << ":" << vec[i].id << " ";
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end(), comp_student);
    for (int i = 0; i < vec.size(); i++) std::cout << vec[i].name << ":" << vec[i].id << " ";
    std::cout << std::endl;
    

    return 0;
}
