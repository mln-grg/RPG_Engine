// Milan George All Rights Reserved


#include "Items/Weapons/RPGWeaponBase.h"

#include "Components/BoxComponent.h"

// Sets default values
ARPGWeaponBase::ARPGWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);

	WeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBox"));
	WeaponCollisionBox->SetupAttachment(GetRootComponent());
	WeaponCollisionBox->SetBoxExtent(FVector(20));
	WeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}