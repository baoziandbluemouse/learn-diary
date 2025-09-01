//
// Created by baozi on 2025/8/27.
//

#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <string>
#include <mutex>
#include <fstream>

class Logger
{
public:
    //获取单例
    static Logger& getInstance();
    //禁止拷贝和赋值
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    //日志记录函数
    void log(const std::string& message);
    //析构函数
    ~Logger();

private:
    Logger();
    std::mutex mutex_;
    std::ofstream logFile;
};


#endif //LOGGER_H
