#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CActionData.generated.h"

class UAnimMontage;
class ACEquipment;
class ACharacter;

USTRUCT(BlueprintType)
struct FEquipmentData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* AnimMontage;

	UPROPERTY(EditDefaultsOnly)
		float PlayRate = 1.f;

	UPROPERTY(EditDefaultsOnly)
		FName StartSection;

	UPROPERTY(EditDefaultsOnly)
		bool bCanMove = true;

	UPROPERTY(EditDefaultsOnly)
		bool bLookForward = true;
};

UCLASS()
class THIRDPERSONCPP_API UCActionData : public UDataAsset
{
	GENERATED_BODY()

public:
	void BeginPlay(ACharacter* InOwnerCharacter);

public:
	UPROPERTY(EditAnywhere, Category = "Eqipment")
		TSubclassOf<ACEquipment> EquipmentClass;

	UPROPERTY(EditAnywhere, Category = "Eqipment")
		FEquipmentData EquipmentData;

	UPROPERTY(EditAnywhere, Category = "Eqipment")
		FLinearColor EquipmentColor;

private:
	ACEquipment* Equipment;

};
