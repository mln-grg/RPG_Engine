// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPG_Engine/Public/Characters/RPGBaseCharacter.h"
#include "RPGHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class RPG_ENGINE_API ARPGHeroCharacter : public ARPGBaseCharacter
{
	GENERATED_BODY()

	ARPGHeroCharacter();
	
protected:
	virtual void BeginPlay() override;

#pragma region Components

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",meta=(AllowPrivateAccess))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",meta=(AllowPrivateAccess))
	UCameraComponent* FollowCam;
	
};
