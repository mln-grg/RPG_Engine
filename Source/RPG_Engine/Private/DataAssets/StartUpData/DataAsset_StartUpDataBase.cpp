// Milan George All Rights Reserved


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(URPGAbilitySystemComponent* InASCToGive,
                                                              int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities,InASCToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities,InASCToGive,ApplyLevel);
	
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<URPGGameplayAbility>>& InAbilitiesToGive,
	URPGAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if(InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for(const TSubclassOf<URPGGameplayAbility>& Ability: InAbilitiesToGive)
	{
		if(!Ability) continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
