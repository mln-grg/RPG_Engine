// Milan George All Rights Reserved

#include "RPG_Engine/Public/Characters/RPGBaseCharacter.h"

ARPGBaseCharacter::ARPGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;
}