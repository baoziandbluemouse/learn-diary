#include "Command.h"
#include "CommandImpl.h"
#include <memory>

TaskManager mgsr;

std::shared_ptr<Command> GetCommand(const std::string& command)
{
    if (command == "add")
    {
        return std::make_shared<AddCommand>(mgsr);
    }

    if (command == "del")
    {
        return std::make_shared<DeleteCommand>(mgsr);
    }

    if (command == "list")
    {
        return std::make_shared<ListCommand>(mgsr);
    }

    if (command == "update")
    {
        return std::make_shared<UpdateCommand>(mgsr);
    }
    return nullptr;
}
