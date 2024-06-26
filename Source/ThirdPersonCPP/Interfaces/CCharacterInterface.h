#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CCharacterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

class THIRDPERSONCPP_API ICCharacterInterface
{
	GENERATED_BODY()

public:
	virtual void ChangeBodyColor(FLinearColor InColor) = 0;

};
