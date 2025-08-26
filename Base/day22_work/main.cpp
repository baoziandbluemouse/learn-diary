#include <iostream>
#include "ResourceManager.h"
#include "GraphNode.h"

std::vector<std::shared_ptr<GraphNode>> createGraph()
{
    auto spNode1 = std::make_shared<GraphNode>(1);
    auto spNode2 = std::make_shared<GraphNode>(2);
    auto spNode3 = std::make_shared<GraphNode>(3);

    spNode1->addEdge(spNode2);
    spNode1->addEdge(spNode3);
    spNode2->addEdge(spNode3);
    spNode3->addEdge(spNode1);

    return {spNode1, spNode2, spNode3};
}


int main()
{
    {
        // ResourceManager res1; // 默认构造函数
        // res1.setValue(10);
        // std::cout << "res1 value: " << res1.getValue() << std::endl;
        // ResourceManager res2(20); // 带参数的构造函数
        // std::cout << "res2 value: " << res2.getValue() << std::endl;
        // res1 = std::move(res2); // 移动赋值
        // std::cout << "After move, res1 value: " << res1.getValue() << std::endl;
        // ResourceManager res3(std::move(res1)); // 移动构造
        // std::cout << "res3 value after move: " << res3.getValue() << std::endl;
    }
    {
        // 用容器存储的时候使用weak，防止循环引用
        // 当要取出来的时候，使用lock()来获取shared_ptr，防止悬垂指针
        auto Graph = createGraph();
        for (auto node : Graph)
        {
            node->print();
        }
    }
    return 0;
}
