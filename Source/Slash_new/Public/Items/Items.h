// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};

class USphereComponent;
UCLASS()
class SLASH_NEW_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	AItems();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RunningTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) //exposese to editor
	float Amplitude = 0.25f;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	EItemState ItemState = EItemState::EIS_Hovering;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UStaticMeshComponent> ItemMesh;
public:	
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere)
	float TimeConstant = 5.f;


	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> Sphere;

};
