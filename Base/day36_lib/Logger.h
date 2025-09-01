#ifndef LOGGER_LOGGER_H
#define LOGGER_LOGGER_H
#include <fstream>
#include <mutex>

//在windows平台，动态链接库在导入导出时需要一个__declspec关键字来标识
//但在linux就不用了
#ifdef _WIN32  //如果是windows平台
#ifdef LOGGER_BUILDING_DLL  //如果正在编译DLL
#define LOGGER_API __declspec(dllexport)  //那么就导出
#else
#define LOGGER_API __declspec(dllimport)  //否则就导入
#endif
#else  //如果不是windows平台
#define LOGGER_API  //什么都不做
#endif

class LOGGER_API Logger
{
public:
    //获取单例
    static Logger& getInstance();
    //禁止拷贝和赋值
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    //记录日志
    void log(const std::string& message);
    ~Logger();

private:
    Logger();
    std::ofstream logFile;
    std::mutex mutex;
};

#endif //LOGGER_LOGGER_H
