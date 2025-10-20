#pragma once

class UWorld;

class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	//virtual: �� ���� ���� �� ������ ����
	virtual void Init();	//�ʱ�ȭ
	virtual void Run();		//����
	virtual void Term();	//����

	//__forceinline: ������Ͽ����� ���
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