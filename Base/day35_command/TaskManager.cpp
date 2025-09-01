//
// Created by baozi on 2025/8/27.
//

#include "TaskManager.h"
#include "Logger.h"

TaskManager::TaskManager(): nextId(1)
{
    loadTasks();
}

void TaskManager::loadTasks()
{
    std::ifstream inFile("tasks.txt");
    if (!inFile.is_open())
    {
        throw std::runtime_error("Failed to open file.");
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        std::istringstream lineStream(line);
        Task task;
        char delimiter; // 用于读取分隔符
        lineStream >> task.id >> delimiter;
        std::getline(lineStream, task.description, ',');
        lineStream >> task.priority >> delimiter;
        lineStream >> task.dueDate;
        tasks.push_back(task);
        if (task.id >= nextId)
        {
            nextId = task.id + 1;
        }
    }
    inFile.close();
    Logger::getInstance().log("加载任务成功");
}

void TaskManager::addTask(const std::string& description, int priority,
                          const std::string& dueDate)
{
    Task task;
    task.id = nextId++;
    task.description = description;
    task.priority = priority;
    task.dueDate = dueDate;
    tasks.push_back(task);
    Logger::getInstance().log("添加任务成功: " + task.toString());
    saveTasks(); // 保存任务到文件中
}

void TaskManager::deleteTask(int id)
{
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task)
    {
        return task.id == id;
    });
    if (it != tasks.end())
    {
        Logger::getInstance().log("删除任务成功: " + it->toString());
        tasks.erase(it);
        saveTasks(); // 保存任务到文件中
    }
    else
    {
        std::cout << "Task Not Found." << std::endl;
    }
}


void TaskManager::updateTask(int id, const std::string& description,
                             int priority, const std::string& dueDate)
{
    auto it = std::find_if(tasks.begin(), tasks.end(), [id](const Task& task)
    {
        return task.id == id;
    });
    if (it != tasks.end())
    {
        it->description = description;
        it->priority = priority;
        it->dueDate = dueDate;
        Logger::getInstance().log("更新任务成功: " + it->toString());
        saveTasks(); // 保存任务到文件中
    }
    else
    {
        std::cout << "Task Not Found." << std::endl;
    }
}

void TaskManager::saveTasks() const
{
    std::ofstream outFile("tasks.txt");
    if (!outFile.is_open())
    {
        Logger::getInstance().log("无法打开任务文件进行保存。");
        return;
    }
    for (const auto& task : tasks)
    {
        outFile << task.id << "," << task.description << "," << task.priority <<
            "," << task.dueDate << "\n";
    }
    outFile.close();
    Logger::getInstance().log("保存任务成功。");
}

void TaskManager::listTasks(int operation) const
{
    std::vector<Task> sortedTasks = tasks; // 创建任务的副本以进行排序
    if (operation == 1)
    {
        // 按优先级排序
        std::sort(sortedTasks.begin(), sortedTasks.end(), compareByPriority);
    }
    else if (operation == 2)
    {
        // 按截止日期排序
        std::sort(sortedTasks.begin(), sortedTasks.end(), compareByDate);
    }
    //如果都不是，那么就按ID排序，直接默认输出即可
    for (const auto& task : sortedTasks)
    {
        std::cout << task.toString() << std::endl;
    }
}


bool TaskManager::compareByPriority(const Task& a, const Task& b)
{
    return a.priority < b.priority;
}

bool TaskManager::compareByDate(const Task& a, const Task& b)
{
    return a.dueDate < b.dueDate;
}
