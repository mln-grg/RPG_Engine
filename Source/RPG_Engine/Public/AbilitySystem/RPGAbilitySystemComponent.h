// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "RPGTypes/RPGStructTypes.h"
#include "RPGAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

	UFUNCTION(BlueprintCallable, Category= "RPG|Ability",meta = (ApplyLevel = "1"))
	void GrantHeroWeaponAbilities(const TArray<FRPGHeroAbilitySet>& InDefaultWeaponAbilities,int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles);

	UFUNCTION(BlueprintCallable, Category= "RPG|Ability")
	void RemoveGrantedHeroWeaponAbilities(UPARAM(ref) TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove);
	
};
