// Milan George All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "RPGInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class RPG_ENGINE_API URPGInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,const FGameplayTag& InInputTag,ETriggerEvent TriggerEvent,UserObject* ContextObject,CallbackFunc Func);

	template<class UserObject,typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig,UserObject* ContextObject,CallbackFunc InputPressedFunc,CallbackFunc InputReleasedFunc);
};

template <class UserObject, typename CallbackFunc>
void URPGInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig,TEXT("Input Config Data Asset is null!"));

	if(UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}

template <class UserObject, typename CallbackFunc>
void URPGInputComponent::BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject,
	CallbackFunc InputPressedFunc, CallbackFunc InputReleasedFunc)
{
	checkf(InInputConfig,TEXT("Input Config Data Asset is null!"));
	for(const FRPGInputActionConfig& AbilityInputActionConfig: InInputConfig->AbilityInputActions)
	{
		if(!AbilityInputActionConfig.IsValid()) continue;

		BindAction(AbilityInputActionConfig.InputAction,ETriggerEvent::Started,ContextObject,InputPressedFunc,AbilityInputActionConfig.InputTag);
		BindAction(AbilityInputActionConfig.InputAction,ETriggerEvent::Completed,ContextObject,InputReleasedFunc,AbilityInputActionConfig.InputTag);
	}
}
