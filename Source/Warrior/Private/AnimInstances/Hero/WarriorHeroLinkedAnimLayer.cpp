// Pradeep Pillai All rights reserved


#include "AnimInstances/Hero/WarriorHeroLinkedAnimLayer.h"
#include "AnimInstances/Hero/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
