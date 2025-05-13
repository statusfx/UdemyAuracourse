// StatusFXGaming

#include "AbilitySystem/AuraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Animation/AnimNode_Inertialization.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"

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

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	//TODO: Move this at some point to the post Gameplay Effect section. Waiting for intstructor to show best practices. 
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxHealth.GetCurrentValue());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, MaxMana.GetCurrentValue());
	}

}

void UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const
{
	// Source = Causer of the effect, Target = target of the effect (Owner of this AS)
	
	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			ACharacter* SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter =  Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);

	
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


