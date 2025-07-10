// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RPGBaseAnimInstance.h"
#include "RPGCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class ARPGBaseCharacter;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGCharacterAnimInstance : public URPGBaseAnimInstance
{
	GENERATED_BODY()

public:
	
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:

	UPROPERTY()
	ARPGBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComp;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category= "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category= "AnimData|LocomotionData")
	bool bHasAcceleration;
};
 