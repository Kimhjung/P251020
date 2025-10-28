#pragma once

#include <SDL3/SDL.h>
#include "Input.h"

#pragma comment(lib, "SDL3")

class UWorld;

class FEngine
{
protected:
	FEngine();
	
public:
	
	virtual ~FEngine();

	//virtual: 니 엔진 만들 때 가져다 쓰셈
	virtual void Init();	//초기화
	virtual void Run();		//실행
	virtual void Term();	//종료

	void OpenLevel();

	//__forceinline: 헤더파일에서만 사용
	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return UInput::KeyCode;
	}

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool bIsRunning = true;

	//int KeyCode = 0;

public:
	static FEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new FEngine();
		}
		return Instance;
	}

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	double GetWorldDeltaSeconds() const;

protected:
	static FEngine* Instance;
	SDL_Time DeltaSeconds;

	class UTimer* Timer = nullptr;
	class UInput* InputDevice = nullptr;
};

//extern FEngine* GEngine;

#define GEngine FEngine::GetInstance()