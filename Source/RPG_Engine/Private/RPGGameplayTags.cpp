// Milan George All Rights Reserved


#include "RPGGameplayTags.h"

namespace RPGGameplayTags
{
	/** Input Tags **/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move,"InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look,"InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipWeapon,"InputTag.EquipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipWeapon,"InputTag.UnequipWeapon");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack,"InputTag.LightAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HeavyAttack,"InputTag.HeavyAttack");
	

	/** Player Tags **/
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Weapon,"Player.Ability.Equip.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Weapon,"Player.Ability.Unequip.Weapon");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light,"Player.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy,"Player.Ability.Attack.Heavy");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,"Player.Weapon.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_Equip_Weapon,"Player.Event.Equip.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_Unequip_Weapon,"Player.Event.Unequip.Weapon");
}
