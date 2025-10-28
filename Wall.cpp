#include "Wall.h"
#include "PaperFilpbookComponent.h"

AWall::AWall()
{
	bIsCollision = true;
	bIsOverlap = false;

	UPaperFilpbookComponent* Paper = new UPaperFilpbookComponent();

	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = { 128, 128, 128, 0 };
	AddComponent(Paper);
}

AWall::~AWall()
{

}
