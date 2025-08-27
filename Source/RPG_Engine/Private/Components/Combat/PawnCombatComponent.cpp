// Milan George All Rights Reserved


#include "Components/Combat/PawnCombatComponent.h"

#include "RPGDebugHelper.h"
#include "Items/Weapons/RPGWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, ARPGWeaponBase* InWeaponToRegister,
                                                 bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("A named %s has already been added as carried weapon"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);

	if(bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}
}

ARPGWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if(CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if(ARPGWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	
	return nullptr;
}

ARPGWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if(!CurrentEquippedWeaponTag.IsValid())
		return nullptr;

	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
	
}
