//
// Created by baozi on 2025/8/8.
//

#include "GraphNode.h"


GraphNode::GraphNode(int value) : _id(value)
{
}

void GraphNode::addEdge(const std::shared_ptr<GraphNode>& node)
{
    std::weak_ptr<GraphNode> weakNode = node;
    _vec.emplace_back(weakNode);
}

void GraphNode::print() const
{
    std::cout << "Node " << _id << " is connected to: ";
    for (const auto& weakNode : _vec)
    {
        std::shared_ptr<GraphNode> strongNode = weakNode.lock();
        if (strongNode == nullptr)
        {
            continue;
        }
        std::cout << strongNode->_id << " ";
    }
    std::cout << std::endl;
}
