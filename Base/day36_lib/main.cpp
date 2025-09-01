#include <iostream>
#include "Command.h"
#include "Logger.h"
#include "unordered_map"

int main()
{
    system("chcp 65001 > nul");
    std::unordered_map<std::string, std::shared_ptr<Command>> commands;
    commands.emplace("add", GetCommand("add"));
    commands.emplace("delete", GetCommand("delete"));
    commands.emplace("list", GetCommand("list"));
    commands.emplace("update", GetCommand("update"));

    std::cout << "欢迎使用任务管理系统！" << std::endl;
    std::cout << "可用命令: add, delete, list, update, exit" << std::endl;

    std::string input;
    while (true)
    {
        std::cout << "\n> ";
        std::getline(std::cin, input);
        if (input.empty()) continue;

        // 分离命令和参数
        size_t spacePos = input.find(' ');
        std::string cmd = input.substr(0, spacePos);
        std::string args;
        if (spacePos != std::string::npos)
        {
            args = input.substr(spacePos + 1);
        }

        if (cmd == "exit")
        {
            std::cout << "退出程序。" << std::endl;
            break;
        }

        auto it = commands.find(cmd);
        if (it != commands.end())
        {
            it->second->execute(args);
        }
        else
        {
            std::cout << "未知命令：" << cmd << std::endl;
        }
    }
    return 0;
}
