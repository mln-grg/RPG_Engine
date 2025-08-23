// Milan George All Rights Reserved

#pragma once
#include "GameplayTagContainer.h"
#include "RPGStructTypes.generated.h"

class UInputMappingContext;
class URPGGameplayAbility;
class URPGHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FRPGHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<URPGGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FRPGHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<URPGHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UInputMappingContext* WeaponMappingContext;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FRPGHeroAbilitySet> DefaultWeaponAbilities;
};