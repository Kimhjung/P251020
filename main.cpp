//define 제일 먼저 선언해주기
#define SDL_ENABLE_OLD_NAMES

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#pragma comment(lib, "SDL3")

//c++ console entry -> iOS, Window, Linux
//int main(int argc, char* argv[])
//{
//	
//}


int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Event MyEvent;

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	bool bIsRunning = true;

	while(bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			//창 닫기
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
		}
		else
		{
			//command queue
			//화면에 그릴 명령어 쌓아놓기
			
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			SDL_RenderClear(MyRenderer);

			//SDL_rand;

			

			//화면 업뎃, 사각형 100개 랜덤으로 그리기
			//SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 0);
			//SDL_FRect Rect = { SDL_rand(640), SDL_rand(480), SDL_rand(640), SDL_rand(480)};
			//SDL_RenderFillRect(MyRenderer, &Rect);
			//SDL_RenderDrawRect(MyRenderer, &Rect);

			//원그리기(320,240,100개)
			//삼각함수
			for(int i = 0; i < 100; ++i)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), 0);

				int Radius = 100;
				int CenterX = 320;
				int CenterY = 240;

				//중심 (0,0) / 반지름 1
				for (float Degree = 10; Degree <= 360; Degree += 10)
				{
					int OldX = SDL_cos((Degree - 10) * SDL_PI_F / 180.0f) * Radius + CenterX;
					int OldY = SDL_sin((Degree - 10) * SDL_PI_F / 180.0f) * Radius + CenterY;

					int X = SDL_cos(Degree * SDL_PI_F / 180.0f) * Radius + CenterX;
					int Y = SDL_sin(Degree * SDL_PI_F / 180.0f) * Radius + CenterY;

					SDL_RenderLine(MyRenderer, OldX, OldY, X, Y);
				}
			}
			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}