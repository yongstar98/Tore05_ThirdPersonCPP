#include "CMotagesComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UCMotagesComponent::UCMotagesComponent()
{

}


void UCMotagesComponent::BeginPlay()
{
	Super::BeginPlay();

	if (DataTable == nullptr)
	{
		CLog::Log("DataTable is not set");
		return;
	}

	TArray<FMontageData*> FromDataTableAsset;
	DataTable->GetAllRows<FMontageData>("", FromDataTableAsset);

	for (int32 i = 0; i < (int32)EStateType::Max; i++)
	{
		for (const auto& Data : FromDataTableAsset)
		{
			if ((EStateType)i == Data->Type)
			{
				Datas[i] = Data;
				break;
			}
		}
	}

	
}

void UCMotagesComponent::PlayRoll()
{
	PlayAnimMontage(EStateType::Roll);
}

void UCMotagesComponent::PlayBackstep()
{
	PlayAnimMontage(EStateType::Backstep);
}

void UCMotagesComponent::PlayAnimMontage(EStateType InStateType)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	CheckNull(Character);

	const FMontageData* Data = Datas[(int32)InStateType];
	if (Data && Data->AnimMontage)
	{
		if (Data->AnimMontage)
		Character->PlayAnimMontage(Data->AnimMontage, Data->PlayRate, Data->StartSection);
	}
}




