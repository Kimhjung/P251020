#include "Engine.h"

#include <SDL3/SDL_main.h>
#include "Component.h"

int main(int argc, char* argv[])
{
	SDL_Time Timer = SDL_GetTicks64();

	GEngine->Init();
	GEngine->Run();
	GEngine->Term();

	Timer = SDL_GetTicks64() - Timer;

	return 0;
}