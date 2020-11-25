#include <map>
#include <algorithm>
#include "ControllerCommandsHolder.hpp"

ControllerType ControllerCommandsHolder::Get(const std::string &command)
{
    if (!Has(command))
    {
        throw std::logic_error("Getting controller type for unknown command");
    }

    return m_commandControllerMap.find(command)->second;
}

bool ControllerCommandsHolder::Has(const std::string &command)
{
    return m_commandControllerMap.find(command) != m_commandControllerMap.end();
}

std::string ControllerCommandsHolder::GetCommandByControllerType(ControllerType controllerType)
{
    auto it = std::find_if(m_commandControllerMap.begin(), m_commandControllerMap.end(), [controllerType](auto & pair){
        return pair.second == controllerType;
    });

    if (it == m_commandControllerMap.end())
    {
        throw std::runtime_error("No command for this ControllerType found");
    }

    return it->first;
}
