#include <game/Application.hpp>

int main(int argc, char* argv[])
{
	Game::Application app;
	app.Run([](Game::Application::Ptr instance) {
		instance->Print("Hello World!");
	});
	return 0;
}
