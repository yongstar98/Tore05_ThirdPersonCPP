#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CAttachment.generated.h"

class ACharacter;

UCLASS()
class THIRDPERSONCPP_API ACAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	ACAttachment();

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintCallable)
	void ActorAttachTo(FName InSocketName);

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEquip();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnequip();

private:
	UPROPERTY(VisibleDefaultsOnly)
		USceneComponent* RootComp;

protected:
	UPROPERTY(BlueprintReadOnly)
		ACharacter* OwnerCharacter;



};
