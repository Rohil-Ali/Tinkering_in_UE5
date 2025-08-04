

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class AItems;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;

UCLASS()
class SLASH_NEW_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;
	void MoveForward(float Value);
	void LookUp(float Value);
	void Turn(float Value);
	void MoveRight(float Value);
	void EKeyPressed();

private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped; //character default state.
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> ViewCamera;
	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> Hair;
	UPROPERTY(VisibleAnywhere, Category = "Hair")
	TObjectPtr<UGroomComponent> EyeBrows;

	//stores the item that the character is currently overlapping with and is set in the item class.
	UPROPERTY(VisibleInstanceOnly)
	TObjectPtr<AItems> OverlappingItem;

public:
	//getters and setter should be sperated like this for good practice.
	FORCEINLINE void SetOverlappingItem(AItems* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }

};
