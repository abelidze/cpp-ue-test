#include "Application.hpp"

#include <iostream>

void Game::Application::Print(const std::string& message) const
{
    if (!_isRunning) {
        return;
    }
    std::cout << message << std::endl;
}

void Game::Application::Run(std::function<void(Application::Ptr)> func)
{
    _isRunning = true;
    Print("Starting...");
    func(this);
    Print("Finished.");
    _isRunning = false;
}
