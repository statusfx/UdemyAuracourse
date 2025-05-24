// StatusFX Studios


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/**
	 * Primary Attributes
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Primary.Strength")), FString(
		"Increases physical damage");

	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Primary.Intelligence")), FString(
		"Increases MaxMana and Damage with arcane and elemental spell damage");

	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Primary.Dexterity")), FString(
		"Increases critical hit chance and damage as well as armor penetration");

	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Primary.Vigor")), FString(
		"Increases maximum health");

	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Primary.Resilience")), FString(
		"Increases defensive stats such as armor");

	/**
	 * Secondary Attributes
	 */
	
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "Attributes.Secondary.Armor")), FString(
			"Reduces damage taken, improves Block Chance");

	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName( "Attributes.Secondary.ArmorPenetration")), FString(
		"Allows damage to ignore an amount of armor on the target");

	GameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.BlockChance")), FString(
	"Increases the probability of a successful block");

	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.CriticalHitChance")), FString(
"Increases the probability of a Critical Hit");

	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.CriticalHitDamage")), FString(
"Increases the Damage from a critical hit");

	GameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.CriticalHitResistance")), FString(
"Decreases damage taken from critical hits");

	GameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.HealthRegeneration")), FString(
	"Health regenerated each second");

	GameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.ManaRegeneration")), FString(
"Mana regenerated each second");

	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.MaxHealth")), FString(
"Amount of damage that can be sustained before death");

	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
FName( "Attributes.Secondary.MaxMana")), FString(
"Capacity for casting spells");

	
/**
 *	Input Tags
 */
	
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.LMB")), FString(
			"Input Tag for Left Mouse Button");
	
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.RMB")), FString(
			"Input Tag for Right Mouse Button");
	
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.1")), FString(
			"Input Tag for 1 Key");
	
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.2")), FString(
			"Input Tag for 2 Key");
	
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.3")), FString(
			"Input Tag for 3 Key");
	
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "InputTag.4")), FString(
			"Input Tag for 4 Key");
}
