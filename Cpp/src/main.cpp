#include <game/Application.hpp>
#include <utils.hpp>

#include <string>
#include <format>
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
	Game::Application app;
	app.Run([](const Game::Application::Ptr instance) {
		// ParseInt
		std::string mode;
		do {
			mode = instance->InputString("Use strict mode for ParseInt? (y/n):");
		} while (mode != "y" && mode != "n");
		auto input = instance->InputString("Enter your number to parse (default -2024):", "-2024");
		int parsedInteger;
		try {
			parsedInteger = utils::ParseInt(input, mode == "y");
		}
		catch (const std::invalid_argument& e) {
			instance->Print(std::format("ERROR InvalidArgumentException: {}", e.what()));
		}
		catch (const std::overflow_error& e) {
			instance->Print(std::format("ERROR OverflowException: {}", e.what()));
		}
		instance->Print(std::format("ParseInt(\"{}\") = {}", input, parsedInteger));

		// SpiralPrint
		instance->Print("Enter NxM dimensions for the generation of 2D matrix.");
		instance->Print("It will be filled with incrementing numbers in row/column order.");
		auto width = instance->InputNumber("Enter width:");
		auto height = instance->InputNumber("Enter height:");
		int number = 0;
		utils::Array2DT matrix(height);
		for (auto&& row : matrix) {
			row.resize(width);
			for (size_t i = 0; i < width; ++i) {
				row[i] = ++number;
			}
		}
		instance->Print("Generated matrix:");
		instance->PrintMatrix(matrix);
		instance->Print("SpiralPrint(matrix):");
		utils::SpiralPrint(std::cout, matrix);
	});
	return EXIT_SUCCESS;
}
