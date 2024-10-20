#pragma once

#include <string>
#include <functional>

namespace Game
{

class Application final
{
public:
    using Ptr = const Application*;

    Application() : _isRunning(false)
    { }
    ~Application() { }

    void Run(std::function<void(Ptr)> func);
    void Print(const std::string& message) const;

private:
    bool _isRunning;
};

} // namespace Game
