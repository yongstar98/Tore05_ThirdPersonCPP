#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "CPlayerController.generated.h"

UCLASS()
class THIRDPERSONCPP_API ACPlayerController : public APlayerController
{
	GENERATED_BODY()
	

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;



protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> ActionWidgetClass;

	UPROPERTY()
	UUserWidget* ActionWidget;

protected:
	bool bIsSlowMotionActive;
	

protected:
	void ToggleSlowMotion();
	void ShowActionWidget();
	void HideActionWidget();

	UFUNCTION(BlueprintCallable, Category = "Actions")
	void OnActionButtonClicked(int32 ActionIndex);

private:
	void SetTimeDilation(float TimeDilation);
};
