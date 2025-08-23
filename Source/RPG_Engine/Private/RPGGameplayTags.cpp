// Milan George All Rights Reserved


#include "RPGGameplayTags.h"

namespace RPGGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move,"InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look,"InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAxe,"InputTag.EquipAxe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnEquipAxe,"InputTag.UnEquipAxe");
	

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,"Player.Weapon.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_Equip_Axe,"Player.Event.Equip.Axe");
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_UnEquip_Axe,"Player.Event.UnEquip.Axe");
}
