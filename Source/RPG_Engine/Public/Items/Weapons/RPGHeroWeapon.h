// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Items/Weapons/RPGWeaponBase.h"
#include "RPGTypes/RPGStructTypes.h"
#include "GameplayAbilitySpecHandle.h"
#include "RPGHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class RPG_ENGINE_API ARPGHeroWeapon : public ARPGWeaponBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="WeaponData")
	FRPGHeroWeaponData HeroWeaponData;

	UFUNCTION(BlueprintCallable)
	void AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpecHandles);

	UFUNCTION(BlueprintPure)
	TArray<FGameplayAbilitySpecHandle> GetGrantedAbilitySpecHandles() const;
	
private:
	TArray<FGameplayAbilitySpecHandle> GrantedAbilitySpecHandles;
};
