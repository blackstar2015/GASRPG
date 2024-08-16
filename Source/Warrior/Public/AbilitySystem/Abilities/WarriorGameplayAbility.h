// Pradeep Pillai All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "WarriorGameplayAbility.generated.h"
class UPawnCombatComponent;
class UWarriorAbilitySystemComponent;

UENUM(BlueprintType)
enum class EWarriorAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class WARRIOR_API UWarriorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	//~Begin UGameplayAbility interface
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~End UGameplayAbility interface
	
	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	EWarriorAbilityActivationPolicy AbilityActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure,Category = "Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure,Category = "Warrior|Ability")
	UWarriorAbilitySystemComponent* GetWarriorAbilitySystemComponent() const;
};
