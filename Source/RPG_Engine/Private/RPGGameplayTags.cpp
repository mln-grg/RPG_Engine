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
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light_Weapon,"Player.Ability.Attack.Light.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Heavy_Weapon,"Player.Ability.Attack.Heavy.Weapon");
	
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_Axe,"Player.Weapon.Axe");
	
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_Equip_Weapon,"Player.Event.Equip.Weapon");
	UE_DEFINE_GAMEPLAY_TAG(PlayerEvent_Unequip_Weapon,"Player.Event.Unequip.Weapon");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_JumpToFinisher,"Player.Status.JumpToFinisher");
	
}
