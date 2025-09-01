//
// Created by secon on 2025/3/14.
//

#ifndef COMMAND_COMMANDIMPL_H
#define COMMAND_COMMANDIMPL_H
#include "Command.h"
#include "TaskManager.h"
#include "Logger.h"

class AddCommand : public Command
{
public:
    AddCommand(TaskManager& manager): taskManager(manager)
    {
    }

    void execute(const std::string& args)
    {
        //解析参数
        size_t pos1 = args.find(',');
        size_t pos2 = args.find(',', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos)
        {
            //            Logger::getInstance().log("参数格式错误");
            std::cout << "参数格式错误。请使用: add <描述>,<优先级>,<截止日期>" << std::endl;
            return;
        }

        std::string description = args.substr(0, pos1);
        int priority = std::stoi(args.substr(pos1 + 1, pos2 - pos1 - 1));
        std::string dueDate = args.substr(pos2 + 1);
        taskManager.addTask(description, priority, dueDate);
        std::cout << "任务添加成功." << std::endl;
    }

private:
    TaskManager& taskManager;
};

class DeleteCommand : public Command
{
public:
    DeleteCommand(TaskManager& manager): taskManager(manager)
    {
    }

    void execute(const std::string& args)
    {
        try
        {
            size_t pos;
            int id = std::stoi(args, &pos);
            if (pos != args.length())
            {
                std::cout << "参数格式错误。请使用: delete <ID>" << std::endl;
                return;
            }
            taskManager.deleteTask(id);

            std::cout << "任务删除成功." << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }catch (const std::out_of_range& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }
    }

private:
    TaskManager& taskManager;
};

class ListCommand : public Command
{
public:
    ListCommand(TaskManager& manager): taskManager(manager)
    {
    }

    void execute(const std::string& args)
    {
        try
        {
            int sortOption = 0;
            if (!args.empty())
            {
                sortOption = std::stoi(args);
            }

            std::cout << "当前任务列表:" << std::endl;
            taskManager.listTasks(sortOption);
        }
        catch (const std::invalid_argument& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }catch (const std::out_of_range& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }
    }

private:
    TaskManager& taskManager;
};


class UpdateCommand : public Command
{
public:
    UpdateCommand(TaskManager& manager): taskManager(manager)
    {
    }

    void execute(const std::string& args)
    {
        try
        {
            size_t pos1 = args.find(',');
            size_t pos2 = args.find(',', pos1 + 1);
            size_t pos3 = args.find(',', pos2 + 1);
            if (pos1 == std::string::npos || pos2 == std::string::npos || pos3
                == std::string::npos)
            {
                std::cout << "参数格式错误。请使用: update <ID>,<描述>,<优先级>,<截止日期>" <<
                    std::endl;
                return;
            }
            int id = std::stoi(args.substr(0, pos1));
            std::string description = args.substr(pos1 + 1, pos2 - pos1 - 1);
            int priority = std::stoi(args.substr(pos2 + 1, pos3 - pos2 - 1));
            std::string dueDate = args.substr(pos3 + 1);
            taskManager.updateTask(id, description, priority, dueDate);
            std::cout << "任务更新成功." << std::endl;
        }
        catch (const std::invalid_argument& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }catch (const std::out_of_range& e)
        {
            Logger::getInstance().log("参数格式错误");
            return;
        }
    }

private:
    TaskManager& taskManager;
};

#endif //COMMAND_COMMANDIMPL_H
