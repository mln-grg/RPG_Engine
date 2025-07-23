// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"


class ARPGWeaponBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_ENGINE_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="RPG|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,ARPGWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category="RPG|Combat")
	ARPGWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const ;
	
	UFUNCTION(BlueprintCallable, Category="RPG|Combat")
	ARPGWeaponBase* GetCharacterCurrentEquippedWeapon() const;

	UPROPERTY(BlueprintReadWrite, Category="RPG|Combat")
	FGameplayTag CurrentEquippedWeaponTag;
private:
	TMap<FGameplayTag,ARPGWeaponBase*> CharacterCarriedWeaponMap;
};
