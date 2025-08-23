// Milan George All Rights Reserved


#include "AbilitySystem/RPGAbilitySystemComponent.h"

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
