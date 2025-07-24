// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPGGameplayAbility.h"
#include "RPGHeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class ARPGHeroController;
class ARPGHeroCharacter;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGHeroGameplayAbility : public URPGGameplayAbility
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure, Category="RPG|Ability")
	ARPGHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category="RPG|Ability")
	ARPGHeroController* GetHeroControllerActorInfo();

	UFUNCTION(BlueprintPure, Category="RPG|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<ARPGHeroCharacter> CachedRPGHeroCharacter;
	TWeakObjectPtr<ARPGHeroController> CachedRPGHeroController;
};
