#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class AItems;
class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class UAnimMontage;
class AWepaon;

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
	/*
	 Callbacks for inputs
	*/
	void MoveForward(float Value);
	void LookUp(float Value);
	void Turn(float Value);
	void MoveRight(float Value);
	void EKeyPressed();
	void AttackPressed();

	/*
	* Play montage functions
	*/
	void PlayAttackMontage(); //plays the attack montage when the attack button is pressed.
	void PlayEquipMontage(FName SectionName); //plays the equip montage when the character equips an item.
private:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped; //character default state.
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess= "true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;
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

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	AWepaon* EquippedWeapon; //the weapon that the character has equipped.

	/*
	 Animation Montage variables
	*/

	UPROPERTY(EditAnywhere, Category = "Montages")
	UAnimMontage* AttackMontage; //attack montage to be played when the attack button is pressed.

	UPROPERTY(EditAnywhere, Category = "Montages")
	UAnimMontage* EquipMontage;


public:
	//getters and setter should be sperated like this for good practice.
	FORCEINLINE void SetOverlappingItem(AItems* Item) { OverlappingItem = Item; }
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }

	UFUNCTION(BlueprintCallable)
	void Disarm();
	UFUNCTION(BlueprintCallable)
	void Arm();
};
