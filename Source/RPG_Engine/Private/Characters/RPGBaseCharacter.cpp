// Milan George All Rights Reserved

#include "RPG_Engine/Public/Characters/RPGBaseCharacter.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/RPGAttributeSet.h"

ARPGBaseCharacter::ARPGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	RPGAbilitySystemComponent = CreateDefaultSubobject<URPGAbilitySystemComponent>(TEXT("RPGAbilitySystemComponent"));
	RPGAttributeSet = CreateDefaultSubobject<URPGAttributeSet>(TEXT("RPGAttributeSet"));
}

UAbilitySystemComponent* ARPGBaseCharacter::GetAbilitySystemComponent() const
{
	return GetRPGAbilitySystemComponent();
}

void ARPGBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(RPGAbilitySystemComponent)
	{
		RPGAbilitySystemComponent->InitAbilityActorInfo(this,this);
		ensureMsgf(!CharacterStartUpData.IsNull(),TEXT("Forgot to assign Startup data to %s"),*GetName());
	}
}
