#ifndef COMMAND_COMMAND_H
#define COMMAND_COMMAND_H
#include <string>
#include <memory>
#ifdef _WIN32
#ifdef COMMAND_BUILDING_DLL
#define COMMAND_API __declspec(dllexport)
#else
#define COMMAND_API __declspec(dllimport)
#endif
#else
#define COMMAND_API
#endif
class COMMAND_API Command
{
public:
    virtual void execute(const std::string& args) = 0;
};

COMMAND_API std::shared_ptr<Command> GetCommand(const std::string& command);

#endif //COMMAND_COMMAND_H
