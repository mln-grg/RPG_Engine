// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "RPG_Engine/Public/Characters/RPGBaseCharacter.h"
#include "RPGHeroCharacter.generated.h"

class UHeroCombatComponent;
struct FInputActionValue;
class UDataAsset_InputConfig;
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

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;

#pragma region Components

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",meta=(AllowPrivateAccess))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera",meta=(AllowPrivateAccess))
	UCameraComponent* FollowCam;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Combat", meta = (AllowPrivateAccess = "true"))
	UHeroCombatComponent* HeroCombatComponent;

#pragma endregion
#pragma region Inputs
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="CharacterData",meta=(AllowPrivateAccess))
	UDataAsset_InputConfig* InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
#pragma endregion 

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return  HeroCombatComponent;}
};
