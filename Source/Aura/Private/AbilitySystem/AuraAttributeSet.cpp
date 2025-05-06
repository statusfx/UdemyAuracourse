// StatusFXGaming

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	// Optional: Initialize attribute values here if needed
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAuraAttributeSet::OnRep_Health()
{
	FGameplayAttributeData OldHealth;
	OldHealth.SetBaseValue(PreviousHealth);
	OldHealth.SetCurrentValue(PreviousHealth);

	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);

	// Update stored previous value
	PreviousHealth = Health.GetCurrentValue();
}

void UAuraAttributeSet::OnRep_MaxHealth()
{
	FGameplayAttributeData OldMaxHealth;
	OldMaxHealth.SetBaseValue(PreviousMaxHealth);
	OldMaxHealth.SetCurrentValue(PreviousMaxHealth);

	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);

	// Update stored previous value
	PreviousMaxHealth = MaxHealth.GetCurrentValue();
}

void UAuraAttributeSet::OnRep_Mana()
{
	FGameplayAttributeData OldMana;
	OldMana.SetBaseValue(PreviousMana);
	OldMana.SetCurrentValue(PreviousMana);

	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);

	// Update stored previous value
	PreviousMana = Mana.GetCurrentValue();
}

void UAuraAttributeSet::OnRep_MaxMana()
{
	FGameplayAttributeData OldMaxMana;
	OldMaxMana.SetBaseValue(PreviousMaxMana);
	OldMaxMana.SetCurrentValue(PreviousMaxMana);

	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);

	// Update stored previous value
	PreviousMaxMana = MaxMana.GetCurrentValue();
}
