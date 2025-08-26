#include <iostream>
#include <list>

#include "MyList.h"

int main()
{
    system("chcp 65001");
    {
        // std::list<int> nums;
        // //向list末尾添加元素
        // nums.push_back(100);
        // nums.push_back(200);
        // nums.push_back(300);
        //
        // //向list头部添加元素
        // nums.push_front(200);
        //
        // //遍历
        // std::cout << "all nums:"
        //     << std::endl;
        // for (auto& num : nums)
        // {
        //     std::cout << num << " ";
        // }
        // std::cout << std::endl;
        //
        // auto it = nums.begin();
        // ++it; //指向第二个元素
        // nums.insert(it, 3000); //在第二个位置插入3000
        //
        // nums.remove(200); //有多个200的话，这些都会被删除
        // std::cout << "all nums after insert and remove:"
        //     << std::endl;
        // for (auto& num : nums)
        // {
        //     std::cout << num << " ";
        // }
        // std::cout << std::endl;
    }
    {
        MyList<int> lst;

        // 插入元素
        lst.push_back(10); // 链表: 10
        lst.push_front(5); // 链表: 5, 10
        lst.push_back(15); // 链表: 5, 10, 15
        lst.insert(++lst.begin(), 7); // 链表: 5, 7, 10, 15

        // 打印链表
        std::cout << "链表内容: ";
        lst.print(); // 输出: 5 7 10 15

        // 删除元素
        lst.pop_front(); // 链表: 7, 10, 15
        lst.pop_back(); // 链表: 7, 10

        // 打印链表
        std::cout << "删除头尾后链表内容: ";
        lst.print(); // 输出: 7 10

        // 插入和删除
        auto it = lst.begin();
        lst.insert(it, 3); // 链表: 3, 7, 10
        lst.erase(it); // 链表: 3, 10

        // 打印链表
        std::cout << "插入和删除后链表内容: ";
        lst.print(); // 输出: 3 10

        // 清空链表
        lst.clear();
        std::cout << "清空后，链表是否为空: " << (lst.empty() ? "是" : "否") << std::endl;
    }
    return 0;
}
