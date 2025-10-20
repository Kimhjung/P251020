#pragma once

class UWorld;

class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	//virtual: 니 엔진 만들 때 가져다 쓰셈
	virtual void Init();	//초기화
	virtual void Run();		//실행
	virtual void Term();	//종료

	//__forceinline: 헤더파일에서만 사용
	__forceinline UWorld* GetWorld() const
	{
		return World;
	}

	__forceinline int GetKeyCode() const
	{
		return KeyCode;
	}
	

protected:
	void Input();
	void Tick();
	void Render();

	class UWorld* World;

	bool bIsRunning = true;

	int KeyCode = 0;

};

extern FEngine* GEngine;