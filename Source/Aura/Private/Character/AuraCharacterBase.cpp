// StatusFXGaming


#include "Character/AuraCharacterBase.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	if (GetMesh())
	{
		Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
		Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
		Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}