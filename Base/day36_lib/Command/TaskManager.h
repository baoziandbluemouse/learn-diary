//
// Created by secon on 2025/3/14.
//

#ifndef COMMAND_TASKMANAGER_H
#define COMMAND_TASKMANAGER_H


#include "Task.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

class TaskManager
{
public:
    TaskManager();
    void addTask(const std::string& description, int priority,
                 const std::string& date);
    void deleteTask(int id);
    void updateTask(int id, const std::string& description, int priority,
                    const std::string& date);
    void listTasks(int sortOption) const; // 0: 按ID, 1:按优先级升序，2：按日期升序
    void loadTasks();
    void saveTasks() const;

private:
    std::vector<Task> tasks;
    int nextId;
    static bool compareByPriority(const Task& a, const Task& b);
    static bool compareByDueDate(const Task& a, const Task& b);
};


#endif //COMMAND_TASKMANAGER_H
