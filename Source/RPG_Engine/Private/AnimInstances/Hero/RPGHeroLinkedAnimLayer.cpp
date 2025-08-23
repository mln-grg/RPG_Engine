// Milan George All Rights Reserved


#include "AnimInstances/Hero/RPGHeroLinkedAnimLayer.h"

#include "AnimInstances/Hero/RPGHeroAnimInstance.h"

URPGHeroAnimInstance* URPGHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<URPGHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
