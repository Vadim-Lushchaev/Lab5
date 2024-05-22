#pragma once

class overflow_queue_exception
{
public:
    overflow_queue_exception(const std::string& message): message(message) {}
    const char* what() const noexcept override
    {
        return message.c_str();
    }
private:
    std::string message;
};
