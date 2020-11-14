#pragma once

#include <exception>
#include <string>

class ItemNotFoundInRegistryException : public std::exception
{
public:
    ItemNotFoundInRegistryException(const std::string &message) noexcept : m_message(message) { }

    ~ItemNotFoundInRegistryException() noexcept = default;

private:
    std::string m_message;
};
