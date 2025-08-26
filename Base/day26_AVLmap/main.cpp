#include <iostream>
#include "Map.h"
using test = std::vector<std::pair<int, std::string>>;

int main()
{
    Map<int, std::string> myMap;
    myMap.put(10, "Ten");
    myMap.put(20, "Twenty");
    myMap.put(5, "Five");
    myMap.put(6, "Six");
    myMap.put(15, "Fifteen");
    myMap.put(30, "Thirty");
    //中序遍历
    test res = myMap.inorder();
    for (const auto& [k, v] : res)
    {
        std::cout << k << ": " << v << std::endl;
    }
    //查找键
    std::string* val = myMap.get(20);
    if (val)
    {
        std::cout << *val << std::endl;
    }
    else
    {
        std::cout << "val of 20 not found." << std::endl;
    }
    //删除键
    myMap.remove(20);
    res = myMap.inorder();
    for (const auto& [k, v] : res)
    {
        std::cout << k << ": " << v << std::endl;
    }

    return 0;
}
