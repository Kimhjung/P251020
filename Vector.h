#pragma once

// F~: Struct, new ����
// C++: Class = Struct
// C#: Class - heap(���� ����) / sturct - stack(�� ����)
// Vector: Data �����
struct FVector2D
{
	FVector2D() :
		X(0), Y(0)
	{

	}

	virtual ~FVector2D()
	{

	}

	int X;
	int Y;
};
