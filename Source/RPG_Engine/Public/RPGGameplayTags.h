// Milan George All Rights Reserved

#pragma once

#include "NativeGameplayTags.h"

namespace RPGGameplayTags
{
	/** Input Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipWeapon);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipWeapon);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack);
	
	/** Player Ability Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Weapon);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Weapon);

	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Weapon);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Weapon);
	
	/** Weapon Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	/** Event Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PlayerEvent_Equip_Weapon);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PlayerEvent_UnEquip_Weapon);
	
}
