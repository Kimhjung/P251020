#pragma once

class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	//virtual: 니 엔진 만들 때 가져다 쓰셈
	virtual void Init();	//초기화
	virtual void Run();		//실행
	virtual void Term();	//종료

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning = true;
};

