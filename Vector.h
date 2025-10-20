#pragma once

// F~: Struct, new 붙음
// C++: Class = Struct
// C#: Class - heap(참조 형식) / sturct - stack(값 형식)
// Vector: Data 저장용
struct FVector2D
{
	FVector2D(int InX = 0, int InY = 0) :
		X(InX), Y(InY)
	{

	}

	virtual ~FVector2D()
	{

	}

	int X;
	int Y;
};
