// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "RPGTypes/RPGStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"

/**
 * 
 */
UCLASS()
class RPG_ENGINE_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(URPGAbilitySystemComponent* InASCToGive, int32 ApplyLevel) override;
private:
	UPROPERTY(EditDefaultsOnly, Category="StartUpData",meta = (TitleProperty = "InputTag"))
	TArray<FRPGHeroAbilitySet> HeroStartUpAbilitySets;
	
};
