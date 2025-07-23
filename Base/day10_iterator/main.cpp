#include <iostream>
#include <vector>
#include <string>

int main()
{
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        auto iter = v.begin();
    }
    {
        std::string s = "another string";
        for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {}
    }
    //解引用迭代器可获得迭代器所指的对象
    //如果该对象的类型恰好是类，就有可能希望进一步访问它的成员。
    {
        std::vector<std::string> vs = {"hello", "world"};
        for (auto it = vs.begin(); it != vs.end(); ++it)
        {
            //(*it)解引用获取string对象，再次调用empty()方法判断为空
            if ((*it).empty())
            {
                std::cout << "empty string" << std::endl;
            }
            if (it->empty())
            {
                std::cout << "empty string" << std::endl;
            }
        }
        //it->mem和(*it).mem表达的意思相同。
    }
    //迭代器失效
    //比如，vector可以动态增长，在遍历同时加元素，就会导致迭代器失效。
    //任何可能改变vector容量的操作，都有可能导致迭代器失效。
    //执行删除操作也要注意，我们可以通过vector的erase操作删除迭代器指向的元素
    //计算相邻和
    {
        std::vector<int> v{1, 2, 3, 4, 5, 8, 9, 5, 10, 13, 555};
        for (auto it = v.begin(); it != v.end() - 1; ++it)
        {
            std::cout << (*it) + (*(it + 1)) << std::endl;
        }
    }
    return 0;
}