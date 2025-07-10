// Milan George All Rights Reserved


#include "AnimInstances/RPGCharacterAnimInstance.h"

#include "Characters/RPGBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void URPGCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<ARPGBaseCharacter>(TryGetPawnOwner());
	if(OwningCharacter)
	{
		OwningMovementComp = OwningCharacter->GetCharacterMovement();
	}
}

void URPGCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!OwningCharacter || !OwningMovementComp)
	{
		return;
	}

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComp->GetCurrentAcceleration().SizeSquared2D() >0.f;
}
