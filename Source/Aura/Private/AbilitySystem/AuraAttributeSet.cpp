// StatusFXGaming

#include "AbilitySystem/AuraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Animation/AnimNode_Inertialization.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"

class FGameplayEffectModCallbackData;

UAuraAttributeSet::UAuraAttributeSet()
{
	Health = 50.f;
	MaxHealth = 100.f;
	Mana = 15.f;
	MaxMana = 50.f;

	UE_LOG(LogTemp, Warning, TEXT("AuraAttributeSet constructor ran"));
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

/*void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealth.GetCurrentValue());
		UE_LOG(LogTemp,Warning, TEXT("Health: %f"), NewValue);
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxMana.GetCurrentValue());
		UE_LOG(LogTemp,Warning, TEXT("Mana: %f"), NewValue);
	}

}
*/
void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	const FGameplayEffectContextHandle EffectContextHandle = Data.EffectSpec.GetContext();
	const UAbilitySystemComponent* SourceASC = EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(SourceASC) && SourceASC->AbilityActorInfo.IsValid() && SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		AActor* SourceAvatarActor = SourceASC->AbilityActorInfo->AvatarActor.Get();
		const AController* SourceController = SourceASC->AbilityActorInfo->PlayerController.Get();
		if (SourceController == nullptr && SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(SourceAvatarActor))
			{
				SourceController = Pawn->GetController();
			}
		}
		if (SourceController)
		{
				ACharacter* SourceCharacter = Cast<ACharacter>(SourceController->GetPawn());
		}
	}

	AActor* TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
	AController* TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
	ACharacter* TargetCharacter = Cast<ACharacter>(TargetActor);
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
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
