//
// Created by baozi on 2025/8/27.
//

#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include "Task.h"
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>


class TaskManager
{
public:
    TaskManager();
    void addTask(const std::string& description, int priority,
                 const std::string& dueDate);
    void deleteTask(int id);
    void updateTask(int id, const std::string& description, int priority,
                    const std::string& dueDate);
    void listTasks(int operation) const;
    //operation=1 按优先级排序，operation=2 按截止日期排序,默认为0，按ID排序
    void loadTasks(); //读取文件中的任务(通过一个文本文件存储logger记录的任务，实现一个中转)
    void saveTasks() const;

private:
    std::vector<Task> tasks;
    int nextId; //下一个任务ID，用于遍历
    static bool compareByPriority(const Task& a, const Task& b);
    static bool compareByDate(const Task& a, const Task& b);
};


#endif //TASKMANAGER_H
