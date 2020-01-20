#include <iostream>
#include <list>

int main()
{
    std::list<int> lst;

    // 末尾に追加, O(1)
    for (int i = 0; i < 10; i++)
    {
        lst.push_back(i);
    }

    // 先頭に追加, O(1)
    lst.push_front(5);

    // iteratorで巡回
    //  lst[i] <- こういうアクセスは連結リストなのでできない
    //  iterator は大小比較できないので it < lst.end() 的な書き方はできない
    std::cout << "<iterator>" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    std::cout << "</iterator>" << std::endl;

    // リストのソート
    lst.sort();

    // 重複を削除
    lst.unique();

    // 末尾を削除
    lst.pop_back();

    // 先頭を削除
    lst.pop_front();

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
    {
        std::cout << *it << std::endl;
    }

}
