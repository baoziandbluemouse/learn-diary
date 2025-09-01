//
// Created by baozi on 2025/8/27.
//

#include "Logger.h"

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::log(const std::string& message)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (logFile.is_open())
    {
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
                 std::localtime(&now_time));
        logFile << "[" << buffer << "] " << message << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

Logger::Logger()
{
    logFile.open("log.txt", std::ofstream::app);
    if (!logFile.is_open())
    {
        throw std::runtime_error("Unable to open log file");
    }
}
