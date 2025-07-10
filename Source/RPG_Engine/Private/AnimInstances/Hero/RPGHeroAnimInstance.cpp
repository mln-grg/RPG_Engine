// Milan George All Rights Reserved


#include "AnimInstances/Hero/RPGHeroAnimInstance.h"

#include "Characters/RPGHeroCharacter.h"

void URPGHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if(OwningCharacter)
	{
		OwningHeroCharacter = Cast<ARPGHeroCharacter>(OwningCharacter);
	}
}

void URPGHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if(bHasAcceleration)
	{
		IdleElapsedTime=0;
		bShouldEnterRelaxedState = false;
	}
	else
	{
		IdleElapsedTime+=DeltaSeconds;
		bShouldEnterRelaxedState = IdleElapsedTime>=EnterRelaxStateThreshold;
	}
}
