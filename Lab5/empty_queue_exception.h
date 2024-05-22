#pragma once
#include <stdexcept>

class empty_queue_exception : public std::runtime_error
{
public:
    empty_queue_exception(const std::string& message): message(message) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};
