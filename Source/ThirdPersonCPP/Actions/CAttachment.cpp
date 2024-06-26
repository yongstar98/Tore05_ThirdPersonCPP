#include "CAttachment.h"
#include "Global.h"
#include "GameFramework/Character.h"

ACAttachment::ACAttachment()
{
	CHelpers::CreateSceneComponent(this, &RootComp, "RootComp");

}

void ACAttachment::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	
}

void ACAttachment::AttachTo(FName InSocketName)
{
	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		InSocketName
	);
}