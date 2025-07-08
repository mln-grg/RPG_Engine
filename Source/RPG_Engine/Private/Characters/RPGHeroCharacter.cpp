// Milan George All Rights Reserved

#include "RPG_Engine/Public/Characters/RPGHeroCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "RPG_Engine/Public/RPGDebugHelper.h"


ARPGHeroCharacter::ARPGHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42,96);
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationRoll = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 200;
	SpringArm->SocketOffset = FVector(0,55,65);
	SpringArm->bUsePawnControlRotation = true;

	FollowCam = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCam->SetupAttachment(SpringArm,USpringArmComponent::SocketName);
	FollowCam->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0,500,0);
	GetCharacterMovement()->MaxWalkSpeed = 400;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000;
	
}

void ARPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Working"));
}
