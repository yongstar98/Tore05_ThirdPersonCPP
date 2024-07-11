#include "CPlayerController.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "CPlayer.h"

void ACPlayerController::BeginPlay()
{
    Super::BeginPlay();

    bIsSlowMotionActive = false;

    if (ActionWidgetClass)
    {
        ActionWidget = CreateWidget<UUserWidget>(this, ActionWidgetClass);
        if (ActionWidget)
        {
            ActionWidget->AddToViewport();
            ActionWidget->SetVisibility(ESlateVisibility::Hidden); 
        }

       
    }
   
}

void ACPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

  
    InputComponent->BindAction("ToggleSlowMotion", IE_Pressed, this, &ACPlayerController::ToggleSlowMotion);


}



void ACPlayerController::ToggleSlowMotion()
{
    bIsSlowMotionActive = !bIsSlowMotionActive;

    if (bIsSlowMotionActive)
    {
        SetTimeDilation(0.25f); 
        bShowMouseCursor = true;
        ShowActionWidget();
    }
    else
    {
        SetTimeDilation(1.0f); 
        bShowMouseCursor = false;
        HideActionWidget();
    }
}

void ACPlayerController::ShowActionWidget()
{
    if (ActionWidget)
    {
        ActionWidget->SetVisibility(ESlateVisibility::Visible);
    }
   
}

void ACPlayerController::HideActionWidget()
{
    if (ActionWidget)
    {
        ActionWidget->SetVisibility(ESlateVisibility::Hidden);
    }
  
}

void ACPlayerController::OnActionButtonClicked(int32 ActionIndex)
{
    APawn* ControlledPawn = GetPawn();
    if (ControlledPawn)
    {
        ACPlayer* PlayerCharacter = Cast<ACPlayer>(ControlledPawn);
        if (PlayerCharacter)
        {
            switch (ActionIndex)
            {
            case 0:
                PlayerCharacter->OnFist();
                break;
            case 1:
                PlayerCharacter->OnOneHand();
                break;
            case 2:
                PlayerCharacter->OnTwoHand();
                break;
            case 3:
                PlayerCharacter->OnMagicBall();
                break;
            case 4:
                PlayerCharacter->OnWarp();
                break;
            case 5:
                PlayerCharacter->OnWhirlWind();
                break;
            default:
                break;
            }
        }
     
    }
   
    HideActionWidget();
    ToggleSlowMotion();
}

void ACPlayerController::SetTimeDilation(float TimeDilation)
{
    UWorld* World = GetWorld();
    if (World)
    {
        World->GetWorldSettings()->SetTimeDilation(TimeDilation);
    }
  
}
