#include "Application.hpp"

#include <iostream>

void Game::Application::Run(std::function<void(const Application::Ptr)> func)
{
	_isRunning = true;
	Print("App running...");
	func(this);
	Print("App finished.");
	_isRunning = false;
}

void Game::Application::Print(const std::string& message) const
{
	if (!_isRunning) {
		return;
	}
	std::cout << message << std::endl;
}

void Game::Application::PrintMatrix(utils::Array2DT matrix) const
{
	for (size_t y = 0; y < matrix.size(); ++y) {
		for (size_t x = 0; x < matrix[y].size(); ++x) {
			std::cout << matrix[y][x] << '\t';
		}
		std::cout << std::endl;
	}
}

std::string Game::Application::InputString(const std::string& message, const std::string& defaultValue/* = std::string()*/) const
{
	if (!_isRunning) {
		return std::string();
	}
	if (!message.empty()) {
		std::cout << message << ' ';
	}
	std::string output;
	std::cin >> output;
	if (output.empty()) {
		return defaultValue;
	}
	return output;
}

int Game::Application::InputNumber(const std::string& message) const
{
	if (!_isRunning) {
		return int();
	}
	int result;
	try {
		if (!message.empty()) {
			std::cout << message << ' ';
		}
		std::cin >> result;
		if (result < 0) {
			return 0;
		}
	} catch (const std::exception& e) {
		return 0;
	}
	return result;
}