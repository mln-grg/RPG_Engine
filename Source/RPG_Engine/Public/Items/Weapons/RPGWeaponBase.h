// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPGWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class RPG_ENGINE_API ARPGWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARPGWeaponBase();

protected:

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category= "Weapons")
	UBoxComponent* WeaponCollisionBox;

public:

	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const {return WeaponCollisionBox;}

};
