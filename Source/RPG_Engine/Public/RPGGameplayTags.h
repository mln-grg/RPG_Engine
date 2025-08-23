// Milan George All Rights Reserved

#pragma once

#include "NativeGameplayTags.h"

namespace RPGGameplayTags
{
	/** Input Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnEquipAxe);
	
	/** Player Tags **/
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PlayerEvent_Equip_Axe);
	RPG_ENGINE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PlayerEvent_UnEquip_Axe);
	
}
