// StatusFXGaming


#include "AuraAssetManager.h"
#include "AuraGameplayTags.h"
#include "AbilitySystemGlobals.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* AuraAssetmanager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetmanager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();

	// Required to use Target Data (Being used to get Results under mouse [Check TargetDataUnderMouse.h])
	UAbilitySystemGlobals::Get().InitGlobalData();
}
