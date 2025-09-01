//
// Created by baozi on 2025/8/27.
//

#ifndef COMMAND_H
#define COMMAND_H
#include <memory>
#include <string>
#include <iostream>
#include "Logger.h"
#include "TaskManager.h"

// class CommandBase
// {
// public:
//     virtual void execute(const std::string& args) = 0;
// };


// CRTP 基类模板
template <typename Derived>
class Command
{
public:
    void execute(const std::string& args)
    {
        (static_cast<Derived*>(this))->executeImpl(args);
    }
};

class AddCommand : public Command<AddCommand>
{
public:
    AddCommand(TaskManager& manager): taskManager(manager)
    {
    }


    void executeImpl(const std::string& args)
    {
        //把传入的任务进行分割，然后添加到任务管理器中
        //解析参数,找出两个逗号的位置，然后就可以提取任务描述，优先级和截止日期
        size_t pos1 = args.find(',');
        size_t pos2 = args.find(',', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos)
        {
            std::cout << "参数格式错误，正确格式:add <任务描述>,<优先级>,<截止日期>" << std::endl;
            return;
        }
        std::string description = args.substr(0, pos1);
        int priority = std::stoi(args.substr(pos1 + 1, pos2 - pos1 - 1));
        //提取出优先级,stoi函数就是把字符串转化为整数
        std::string dueDate = args.substr(pos2 + 1);
        //提取出截止日期
        taskManager.addTask(description, priority, dueDate);
        std::cout << "添加任务成功" << std::endl;
    }

private:
    TaskManager& taskManager;
};

class DeleteCommand : public Command<DeleteCommand>
{
public:
    DeleteCommand(TaskManager& manager): taskManager(manager)
    {
    }

    void executeImpl(const std::string& args)
    {
        try
        {
            size_t pos;
            int id = std::stoi(args, &pos);
            if (pos != args.length())
            {
                std::cout << "参数格式错误，正确格式:delete <任务ID>" << std::endl;
                return;
            }
            taskManager.deleteTask(id);
            std::cout << "删除任务成功" << std::endl;
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "参数格式错误，正确格式:delete <任务ID>" << std::endl;
        }catch (std::out_of_range& e)
        {
            std::cout << "参数格式错误，正确格式:delete <任务ID>" << std::endl;
        }
    }

private:
    TaskManager& taskManager;
};

class ListCommand : public Command<ListCommand>
{
public:
    ListCommand(TaskManager& manager) : taskManager(manager)
    {
    }

    void executeImpl(const std::string& args)
    {
        try
        {
            int sortOption = 0;
            if (!args.empty())
            {
                sortOption = std::stoi(args);
            }
            taskManager.listTasks(sortOption);
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "参数格式错误，正确格式:list [排序方式](输入1优先级排序，输入2截止日期排序)" <<
                std::endl;
        }catch (std::out_of_range& e)
        {
            std::cout << "参数格式错误，正确格式:list [排序方式](输入1优先级排序，输入2截止日期排序)" <<
                std::endl;
        }
    }

private:
    TaskManager& taskManager;
};

class UpdateCommand : public Command<UpdateCommand>
{
public:
    UpdateCommand(TaskManager& manager) : taskManager(manager)
    {
    }

    void executeImpl(const std::string& args)
    {
        try
        {
            size_t pos1 = args.find(',');
            size_t pos2 = args.find(',', pos1 + 1);
            size_t pos3 = args.find(',', pos2 + 1);
            if (pos1 == std::string::npos || pos2 == std::string::npos || pos3
                == std::string::npos)
            {
                std::cout << "参数格式错误，正确格式:update <任务ID>,<任务描述>,<优先级>,<截止日期>" <<
                    std::endl;
                return;
            }
            int id = std::stoi(args.substr(0, pos1));
            std::string description = args.substr(pos1 + 1, pos2 - pos1 - 1);
            int priority = std::stoi(args.substr(pos2 + 1, pos3 - pos2 - 1));
            std::string dueDate = args.substr(pos3 + 1);
            taskManager.updateTask(id, description, priority, dueDate);
            std::cout << "更新任务成功" << std::endl;
        }
        catch (std::invalid_argument& e)
        {
            std::cout << "参数格式错误，正确格式:update <任务ID>,<任务描述>,<优先级>,<截止日期>" <<
                std::endl;
        }
        catch (std::out_of_range& e)
        {
            std::cout << "参数格式错误，正确格式:update <任务ID>,<任务描述>,<优先级>,<截止日期>" <<
                std::endl;
        }
    }

private:
    TaskManager& taskManager;
};

class CommandWrapper
{
    struct Concept
    {
        virtual void execute(const std::string& args) = 0;
        virtual ~Concept() = default;
    };

    template <typename T>
    struct Model : Concept
    {
        T command;

        Model(T&& cmd) : command(std::move(cmd))
        {
        }

        void execute(const std::string& args) override
        {
            command.execute(args);
        }

        ~Model() override = default;
    };

public:
    template <typename T>
    CommandWrapper(T cmd): impl(std::make_unique<Model<T>>(std::move(cmd)))
    {
    }

    void execute(const std::string& args)
    {
        impl->execute(args);
    }

private:
    std::unique_ptr<Concept> impl;
};


#endif //COMMAND_H
