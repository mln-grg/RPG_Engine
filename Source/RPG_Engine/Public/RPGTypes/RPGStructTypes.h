// Milan George All Rights Reserved

#pragma once
#include "RPGStructTypes.generated.h"

class URPGHeroLinkedAnimLayer;

USTRUCT(BlueprintType)
struct FRPGHeroWeaponData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TSubclassOf<URPGHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	
};