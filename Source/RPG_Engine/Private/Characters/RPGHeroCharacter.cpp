// Milan George All Rights Reserved

#include "RPG_Engine/Public/Characters/RPGHeroCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RPGGameplayTags.h"
#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "Components/Input/RPGInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

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

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
	
}

void ARPGHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(!CharacterStartUpData.IsNull())
	{
		if(UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(RPGAbilitySystemComponent);
		}
	}
}

void ARPGHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("DataAsset is invalid"))
	
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem)

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext,0);

	URPGInputComponent* RPGInputComponent = CastChecked<URPGInputComponent>(PlayerInputComponent);
	RPGInputComponent->BindNativeInputAction(InputConfigDataAsset,RPGGameplayTags::InputTag_Move,ETriggerEvent::Triggered,this,&ThisClass::Input_Move);
	RPGInputComponent->BindNativeInputAction(InputConfigDataAsset,RPGGameplayTags::InputTag_Look,ETriggerEvent::Triggered,this,&ThisClass::Input_Look);

	RPGInputComponent->BindAbilityInputAction(InputConfigDataAsset,this,&ThisClass::Input_AbilityInputPressed,&ThisClass::Input_AbilityInputReleased);
}

void ARPGHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARPGHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0,Controller->GetControlRotation().Yaw,0);

	if(MovementVector.Y!=0)
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection,MovementVector.Y);
	}

	if(MovementVector.X!=0)
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection,MovementVector.X);
	}
}

void ARPGHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxixVector = InputActionValue.Get<FVector2D>();

	if(LookAxixVector.X!=0)
	{
		AddControllerYawInput(LookAxixVector.X);
	}

	if(LookAxixVector.Y !=0)
	{
		AddControllerPitchInput(LookAxixVector.Y);
	}
}

void ARPGHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	RPGAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ARPGHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	RPGAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
