#pragma once

// F~: Struct, new 붙음
// C++: Class = Struct
// C#: Class - heap(참조 형식) / sturct - stack(값 형식)
// Vector: Data 저장용
struct FVector2D
{
	//복사 생성자
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

	//GameMode.cpp 파일에서 if문 쓸 때 에러났었음
	//bool type으로 바꿔줌
	bool operator==(const FVector2D& RHS)
	{
		return (this->X == RHS.X && this->Y == RHS.Y);
	}

	int X;
	int Y;
};
