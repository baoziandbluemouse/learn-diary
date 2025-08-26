//
// Created by baozi on 2025/8/26.
//

#include "LogSystem.h"


//加锁就是为了保证一个原子操作，防止多个线程同时操作队列


void LogQueue::push(const std::string& message)
{
    std::lock_guard<std::mutex> lock(mutex_);
    queue_.push(message);
    if (queue_.size() == 1)
    {
        cond_var_.notify_one();
    }
}

bool LogQueue::pop(std::string& message)
{
    std::unique_lock<std::mutex> lock(mutex_);
    //要防止虚假唤醒,使用while或这个lambda表达式来检查条件
    //现代C++一般使用条件变量的wait的重载版本,传入一个lambda表达式
    //当lambda表达式返回false后，子线程会挂起，然后解锁，其他线程可以获得锁
    //当主线程调用notify_one，子线程会被唤醒，重新获得锁，然后检查lambda表达式
    //如果返回true,则继续执行，继续持有锁,如果返回false,则重复上面的过程
    cond_var_.wait(lock, [this]()
    {
        return !queue_.empty() || is_shutdown_;
    });

    //如果主线程要求关闭,并且队列为空,则返回false
    //如果队列不为空，那么继续处理队列中的消息，然后再返回false
    if (is_shutdown_)
    {
        while (!queue_.empty())
        {
            message = queue_.front();
            queue_.pop();
        }
        return false;
    }
    //正常消费逻辑
    message = queue_.front();
    queue_.pop();
    return true;
}

void LogQueue::shutdown()
{
    std::lock_guard<std::mutex> lock(mutex_);
    is_shutdown_ = true;
    //通知所有消费者线程退出
    cond_var_.notify_all();
}

Logger::Logger(const std::string& file_name): log_file_(file_name,
                                                  std::ios::out |
                                                  std::ios::app),
                                              exit_flag_(false)
{
    //打开文件失败,抛出异常
    if (!log_file_.is_open())
    {
        throw std::runtime_error("Failed to open log file");
    }

    //启用线程
    worker_thread_ = std::thread([this]()
    {
        std::string msg;
        while (log_queue_.pop(msg))
        {
            log_file_ << msg << std::endl;
        }
    });
}

Logger::~Logger()
{
    exit_flag_ = true; //退出标志
    log_queue_.shutdown(); //关闭队列
    if (worker_thread_.joinable())
    {
        worker_thread_.join(); //等待线程退出
    }
    if (log_file_.is_open())
    {
        log_file_.close();
    }
}

std::string Logger::getCurrentTime()
{
    auto now = std::chrono::system_clock::now(); //获取系统当前时间

    std::time_t now_c = std::chrono::system_clock::to_time_t(now); //转换为c风格字符串
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S",
                  std::localtime(&now_c));
    return buffer;
}
