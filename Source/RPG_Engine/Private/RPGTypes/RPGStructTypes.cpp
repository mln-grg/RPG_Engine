// Milan George All Rights Reserved

#include "RPGTypes/RPGStructTypes.h"
#include "AbilitySystem/Abilities/RPGHeroGameplayAbility.h"

bool FRPGHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}
