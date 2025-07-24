// Milan George All Rights Reserved


#include "AbilitySystem/Abilities/RPGHeroGameplayAbility.h"
#include "Characters/RPGHeroCharacter.h"
#include "Controllers/RPGHeroController.h"

ARPGHeroCharacter* URPGHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if(!CachedRPGHeroCharacter.IsValid())
	{
		CachedRPGHeroCharacter = Cast<ARPGHeroCharacter>(CurrentActorInfo->AvatarActor);
	}
	
	return CachedRPGHeroCharacter.IsValid()? CachedRPGHeroCharacter.Get(): nullptr;
}

ARPGHeroController* URPGHeroGameplayAbility::GetHeroControllerActorInfo()
{
	if(!CachedRPGHeroController.IsValid())
	{
		CachedRPGHeroController = Cast<ARPGHeroController>(CurrentActorInfo->PlayerController);
	}
	
	return CachedRPGHeroController.IsValid()? CachedRPGHeroController.Get(): nullptr;
}

UHeroCombatComponent* URPGHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
