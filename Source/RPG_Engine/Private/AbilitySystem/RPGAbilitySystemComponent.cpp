// Milan George All Rights Reserved


#include "AbilitySystem/RPGAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/RPGHeroGameplayAbility.h"

void URPGAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if(!InInputTag.IsValid())
	{
		return;
	}

	for (auto AbilitySpec : GetActivatableAbilities())
	{
		if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void URPGAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void URPGAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FRPGHeroAbilitySet>& InDefaultWeaponAbilities,
	int32 ApplyLevel,TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpecHandles)
{
	if(InDefaultWeaponAbilities.IsEmpty())
	{
		return;
	}

	for(const FRPGHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if(!AbilitySet.IsValid()) continue;
		
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		
		OutGrantedAbilitySpecHandles.AddUnique(GiveAbility(AbilitySpec));
	}
}

void URPGAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(
	TArray<FGameplayAbilitySpecHandle>& InSpecHandlesToRemove)
{
	if(InSpecHandlesToRemove.IsEmpty())
		return;

	for (const FGameplayAbilitySpecHandle& SpecHandle : InSpecHandlesToRemove)
	{
		if(SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}
	}

	InSpecHandlesToRemove.Empty();
}
