#pragma once

#include <utils.hpp>

#include <string>
#include <functional>

namespace Game
{
	class Application final
	{
	public:
		using Ptr = Application*;

		Application() : _isRunning(false)
		{ }
		~Application() { }

		void Run(std::function<void(const Ptr)> func);
		void Print(const std::string& message) const;
		void PrintMatrix(utils::Array2DT matrix) const;
		std::string InputString(const std::string& message, const std::string& defaultValue = std::string()) const;
		int InputNumber(const std::string& message) const;

	private:
		bool _isRunning;
	};
} // namespace Game
