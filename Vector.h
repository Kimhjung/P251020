#pragma once

// F~: Struct, new ����
// C++: Class = Struct
// C#: Class - heap(���� ����) / sturct - stack(�� ����)
// Vector: Data �����
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
