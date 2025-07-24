// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "RPGGameplayAbility.generated.h"

class URPGAbilitySystemComponent;
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class ERPGAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:

	//~Begin UGameplayAbilityInterface Interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~End UGameplayAbilityInterface Interface
	
	UPROPERTY(EditDefaultsOnly, Category= "RPGAbility")
	ERPGAbilityActivationPolicy AbilityActivationPolicy = ERPGAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category="RPG|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category="RPG|Ability")
	URPGAbilitySystemComponent* GetRPGAbilitySystemComponentFromActorInfo() const;
};
