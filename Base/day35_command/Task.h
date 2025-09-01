//
// Created by baozi on 2025/8/27.
//

#ifndef TASK_H
#define TASK_H
#include <string>
#include <sstream>
#include <iomanip>


class Task
{
public:
    int id; //任务ID
    std::string description; //具体描述
    int priority; //优先级
    std::string dueDate; //截止日期
    std::string toString() const
    {
        std::stringstream ss;
        ss << "Task ID: " << id
            << ", Description: " << description
            << ", Priority: " << priority
            << ", Due Date: " << dueDate;
        return ss.str();
    }
};


#endif //TASK_H
