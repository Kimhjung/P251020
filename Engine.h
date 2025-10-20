#pragma once

class FEngine
{
public:
	FEngine();
	virtual ~FEngine();

	//virtual: �� ���� ���� �� ������ ����
	virtual void Init();	//�ʱ�ȭ
	virtual void Run();		//����
	virtual void Term();	//����

protected:
	void Input();
	void Tick();
	void Render();

	bool bIsRunning = true;
};

