// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterBase.h"
#include "UnrealNetwork.h"

// Sets default values
AMonsterBase::AMonsterBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bReplicates = true;
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_hp = _maxHp;
}
void AMonsterBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMonsterBase, _maxHp);
	DOREPLIFETIME(AMonsterBase, _hp);
}

void AMonsterBase::OnRep_Flag() {
	if (_hp <= 0.0f) Die();
}

// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AMonsterBase::GetDamage(float damage)
{
	_hp -= damage;
	if (_hp < 0.0f) Die();
	return _hp;
}


void AMonsterBase::Die()
{
	DieFunc();
	BPDie();
}

float AMonsterBase::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	return GetDamage(DamageAmount);
}
