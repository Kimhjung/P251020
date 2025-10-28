#pragma once

class AActor;

////추상 클래스
//class IInterface
//{
//public:
//	//순수 가상 함수 (interface)
//	//컴포넌트를 상속받은 애들은 Tick()을 무조건 재정의해야 함
//	virtual void Tick() = 0;
//};

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수 가상 함수
	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

