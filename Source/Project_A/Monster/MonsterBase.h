// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MonsterBase.generated.h"

UCLASS()
class PROJECT_A_API AMonsterBase : public ACharacter
{
	GENERATED_BODY()

// Fields
public:
protected:
	UPROPERTY()
	float _maxHp = 100;
	UPROPERTY()
	float _hp;
private:

// Methods
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Die();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

public:
	// Sets default values for this character's properties
	AMonsterBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Apply Damage. Return val is remain hp.
	UFUNCTION(BlueprintCallable)
	float GetDamage(float damage);
	UFUNCTION(BlueprintCallable)
	float GetHp() { return _hp; }
	UFUNCTION(BlueprintCallable)
	float GetHpRate() { return _hp / _maxHp;}
};
