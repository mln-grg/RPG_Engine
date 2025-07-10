// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RPGCharacterAnimInstance.h"
#include "RPGHeroAnimInstance.generated.h"

class ARPGHeroCharacter;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGHeroAnimInstance : public URPGCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;
protected:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category= "AnimData|Refrences")
	ARPGHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category= "AnimData|LocomotionData")
	bool bShouldEnterRelaxedState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5;

	float IdleElapsedTime;
	
	
};
