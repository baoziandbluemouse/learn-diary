//
// Created by baozi on 2025/8/26.
//

#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H
#include <iostream>
#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <fstream>
#include <atomic>
#include <sstream>
#include <vector>
#include <stdexcept>

enum class LogLevel
{
    INFO, DEBUG, WARN, ERROR
};


//辅助函数,将单个参数转化为字符串
template <typename T>
std::string to_string_helper(T&& value)
{
    std::stringstream ss;
    ss << std::forward<T>(value);
    return ss.str();
}

class LogQueue
{
public:
    void push(const std::string& message);
    bool pop(std::string& message);
    void shutdown();

private:
    std::queue<std::string> queue_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
    bool is_shutdown_ = false;
};

class Logger
{
public:
    Logger(const std::string& file_name);
    ~Logger();
    template <typename... Args>
    void log(LogLevel level, const std::string& format, Args&&... args);

private:
    template <typename... Args>
    std::string formatmessage(const std::string& format, Args&&... args);
    std::string getCurrentTime();
    LogQueue log_queue_;
    std::thread worker_thread_; //这里我们使用一个线程来消费日志，在企业级应用中，一般是用线程池
    std::ofstream log_file_;
    std::atomic<bool> exit_flag_;
};


template <typename... Args>
void Logger::log(LogLevel level, const std::string& format, Args&&... args)
{
    std::string level_string;
    switch (level)
    {
    case LogLevel::INFO:
        level_string = "[INFO] ";
        break;
    case LogLevel::DEBUG:
        level_string = "[DEBUG] ";
        break;
    case LogLevel::WARN:
        level_string = "[WARN] ";
        break;
    case LogLevel::ERROR:
        level_string = "[ERROR] ";
        break;
    default:
        level_string = "[UNKNOWN] ";
        break;
    }
    //使用forward使得外部传入的参数类型得以保持
    log_queue_.push(formatmessage(level_string + format,
                                  std::forward<Args>(args)...));
}

template <typename... Args>
std::string Logger::formatmessage(const std::string& format, Args&&... args)
{
    //将参数包展开，并将每个参数转化为字符串,存入vector中
    std::vector<std::string> arg_strings = {
        to_string_helper(std::forward<Args>(args))
        ...
    };
    //把参数替换到format字符串中
    std::stringstream ss;
    size_t arg_index = 0;
    size_t pos = 0;
    size_t placeholder = format.find("{}", pos);
    //这层while是寻找占位符，然后用参数替换占位符
    while (placeholder != std::string::npos)
    {
        ss << format.substr(pos, placeholder - pos);
        if (arg_index < arg_strings.size())
        {
            ss << arg_strings[arg_index++];
        }
        else
        {
            //如果参数不够，就原样输出占位符
            ss << "{}";
        }
        pos = placeholder + 2; //跳过占位符
        placeholder = format.find("{}", pos);
    }

    //极端情况下，没有任何占位符，那就把所有参数都拼接到字符串后面就好
    //否则就是把剩余的字符串部分拼接上，然后再把剩余的参数拼接上
    ss << format.substr(pos);
    while (arg_index < arg_strings.size())
    {
        ss << arg_strings[arg_index++];
    }
    return "[ " + getCurrentTime() + " ] " + ss.str();
}
#endif //LOGSYSTEM_H
