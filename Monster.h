#pragma once
#include "Actor.h"
#include "Engine.h"

class AMonster : public AActor
{
public:
	AMonster();
	virtual ~AMonster();

	virtual void Tick() override;
};

