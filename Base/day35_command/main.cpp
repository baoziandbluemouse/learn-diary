#include <functional>
#include <iostream>
#include "Logger.h"
#include "TaskManager.h"
#include "Command.h"
#include <unordered_map>

int main()
{
    system("chcp 65001 > nul"); // 设置控制台为UTF-8编码，隐藏输出
    TaskManager taskManager;
    // 使用哈希表存储命令和对应的命令对象
    // 方式一：虚基类，这种的缺点是会有虚函数开销，破坏了CRTP
    // std::unordered_map<std::string, std::shared_ptr<CommandBase>> commands;
    // commands["add"] = std::make_shared<AddCommand>(taskManager);
    // commands["delete"] = std::make_shared<DeleteCommand>(taskManager);
    // commands["list"] = std::make_shared<ListCommand>(taskManager);
    // commands["update"] = std::make_shared<UpdateCommand>(taskManager);
    // 方式二，类型擦除,使用std::function来存储命令对象的execute方法
    //std::unordered_map<std::string, std::function<void(const std::string&)>>
    //    commands;
    // 使用智能指针是为了实现伪闭包，因为我们使用lambda表达式捕获了命令对象
    // 这时如果命令对象生命周期没有lambda长，那么就会有问题，而使用智能指针就可以解决这个问题
    // shared_ptr在被捕获时会增加引用计数，确保对象在lambda表达式的生命周期内不会被销毁
    // auto add_command = std::make_shared<AddCommand>(taskManager);
    // auto delete_command = std::make_shared<DeleteCommand>(taskManager);
    // auto list_command = std::make_shared<ListCommand>(taskManager);
    // auto update_command = std::make_shared<UpdateCommand>(taskManager);
    // //放入map
    // commands["add"] = [add_command](const std::string& args)
    // {
    //     add_command->execute(args);
    // };
    // commands["delete"] = [delete_command](const std::string& args)
    // {
    //     delete_command->execute(args);
    // };
    // commands["list"] = [list_command](const std::string& args)
    // {
    //     list_command->execute(args);
    // };
    // commands["update"] = [update_command](const std::string& args)
    // {
    //     update_command->execute(args);
    // };

    //方法三：使用装饰器思想，做一个CommandWrapper类，来包装命令对象,这是比较推荐的方法
    std::unordered_map<std::string, CommandWrapper> commands;
    commands.emplace("add", CommandWrapper(AddCommand(taskManager)));
    commands.emplace("delete", CommandWrapper(DeleteCommand(taskManager)));
    commands.emplace("list", CommandWrapper(ListCommand(taskManager)));
    commands.emplace("update", CommandWrapper(UpdateCommand(taskManager)));


    std::cout << "欢迎使用任务管理系统！" << std::endl;
    std::cout << "可用命令：add, delete, list, update, exit" << std::endl;
    std::string input;
    while (true)
    {
        std::cout << "\n>";
        std::getline(std::cin, input);
        if (input == "")
        {
            continue;
        }
        size_t spacePos = input.find(' ');
        std::string command = input.substr(0, spacePos);
        std::string arg;
        if (spacePos != std::string::npos)
        {
            arg = input.substr(spacePos + 1);
        }
        if (command == "exit")
        {
            std::cout << "退出任务管理系统。" << std::endl;
            break;
        }
        //方式三的调用方法,方式一同样，不过second后要用->号
        auto it = commands.find(command); //在哈希表中查找是否有该命令
        if (it != commands.end())
        {
            it->second.execute(arg);
        }
        else
        {
            std::cout << "未知命令，请重新输入。" << std::endl;
        }

        // 方式二的调用方法
        // auto it = commands.find(command);
        // if (it != commands.end())
        // {
        //     it->second(arg);
        // }
        // else
        // {
        //     std::cout << "未知命令：请重新输入" << std::endl;
        // }
    }
    return 0;
}
