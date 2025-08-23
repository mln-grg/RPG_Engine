// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"


class ARPGHeroWeapon;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RPG_ENGINE_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable,Category="RPG|Combat")
	ARPGHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};
