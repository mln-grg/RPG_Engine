// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class URPGAbilitySystemComponent;
class URPGGameplayAbility;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(URPGAbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly,Category= "StartUpData")
	TArray<TSubclassOf<URPGGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly,Category= "StartUpData")
	TArray<TSubclassOf<URPGGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<URPGGameplayAbility>>& InAbilitiesToGive,URPGAbilitySystemComponent* InASCToGive,int32 ApplyLevel =1);
	
};
