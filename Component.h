#pragma once

class AActor;

////�߻� Ŭ����
//class IInterface
//{
//public:
//	//���� ���� �Լ� (interface)
//	//������Ʈ�� ��ӹ��� �ֵ��� Tick()�� ������ �������ؾ� ��
//	virtual void Tick() = 0;
//};

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//���� ���� �Լ�
	virtual void Tick() = 0;

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

