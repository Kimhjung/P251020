#pragma once

// F~: Struct, new ����
// C++: Class = Struct
// C#: Class - heap(���� ����) / sturct - stack(�� ����)
// Vector: Data �����
struct FVector2D
{
	//���� ������
	FVector2D(const FVector2D& RHS)
	{

		this->X = RHS.X;
		this->Y = RHS.Y;
	}

	FVector2D(int InX = 0, int InY = 0) :
		X(InX), Y(InY)
	{

	}

	virtual ~FVector2D()
	{

	}

	FVector2D& operator=(const FVector2D& RHS)
	{
		this->X = RHS.X;
		this->Y = RHS.Y;

		return *this;
	}

	FVector2D operator+(const FVector2D& RHS)
	{
		return FVector2D(this->X + RHS.X, this->Y + RHS.Y);
	}

	FVector2D operator-(const FVector2D& RHS)
	{
		return FVector2D(this->X - RHS.X, this->Y - RHS.Y);
	}

	//GameMode.cpp ���Ͽ��� if�� �� �� ����������
	//bool type���� �ٲ���
	bool operator==(const FVector2D& RHS)
	{
		return (this->X == RHS.X && this->Y == RHS.Y);
	}

	int X;
	int Y;
};
