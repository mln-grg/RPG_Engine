// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RPGBaseAnimInstance.h"
#include "RPGHeroLinkedAnimLayer.generated.h"

class URPGHeroAnimInstance;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGHeroLinkedAnimLayer : public URPGBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure,meta=(BlueprintThreadSafe))
	URPGHeroAnimInstance* GetHeroAnimInstance() const;
};
