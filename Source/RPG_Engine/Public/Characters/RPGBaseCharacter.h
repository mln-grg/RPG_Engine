// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "RPGBaseCharacter.generated.h"

class UDataAsset_StartUpDataBase;
class URPGAttributeSet;
class URPGAbilitySystemComponent;

UCLASS()
class RPG_ENGINE_API ARPGBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGBaseCharacter();
	
	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AbilitySystem")
	URPGAbilitySystemComponent* RPGAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="AbilitySystem")
	URPGAttributeSet* RPGAttributeSet;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
	
public:
	FORCEINLINE URPGAbilitySystemComponent* GetRPGAbilitySystemComponent() const {return RPGAbilitySystemComponent;}

	FORCEINLINE URPGAttributeSet* GetRPGAttributeSet() const {return  RPGAttributeSet;}
	
	
};
