//
// Created by baozi on 2025/8/8.
//

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <iostream>
#include <memory>
#include <vector>

class GraphNode
{
public:
    GraphNode(int value);
    void addEdge(const std::shared_ptr<GraphNode>& node);
    void print() const;

private:
    int _id;
    std::vector<std::weak_ptr<GraphNode>> _vec;
};



#endif //GRAPHNODE_H
