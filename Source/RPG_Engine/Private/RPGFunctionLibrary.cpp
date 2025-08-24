// Milan George All Rights Reserved

#include "RPGFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystem/RPGAbilitySystemComponent.h"

URPGAbilitySystemComponent* URPGFunctionLibrary::NativeGetRPGASCFromActor(AActor* InActor)
{
	check(InActor)

	return CastChecked<URPGAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

void URPGFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	URPGAbilitySystemComponent* ASC = NativeGetRPGASCFromActor(InActor);

	if(!ASC->HasMatchingGameplayTag(TagToAdd))
		ASC->AddLooseGameplayTag(TagToAdd);
}

void URPGFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToAdd)
{
	URPGAbilitySystemComponent* ASC = NativeGetRPGASCFromActor(InActor);

	if(ASC->HasMatchingGameplayTag(TagToAdd))
		ASC->RemoveLooseGameplayTag(TagToAdd);
}

bool URPGFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	URPGAbilitySystemComponent* ASC = NativeGetRPGASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void URPGFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, ERPGConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor,TagToCheck)? ERPGConfirmType::Yes : ERPGConfirmType::No;
}
