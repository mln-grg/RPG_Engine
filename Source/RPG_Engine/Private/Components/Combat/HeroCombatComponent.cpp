// Milan George All Rights Reserved


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/RPGHeroWeapon.h"

ARPGHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<ARPGHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));;
}
