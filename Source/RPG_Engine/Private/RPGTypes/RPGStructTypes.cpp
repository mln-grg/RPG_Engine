// Milan George All Rights Reserved

#include "RPGTypes/RPGStructTypes.h"
#include "AbilitySystem/Abilities/RPGGameplayAbility.h"

bool FRPGHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
