// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyClient.h" 
#include "MyPawn.generated.h"

UCLASS()
class UNREALCARPOLE_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void ResetEpisode();
	void StartActing();
	void Acting(int dir);
	void ActingHandling();

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Root")
	class USkeletalMeshComponent* Root;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Cart")
	class UStaticMeshComponent* Cart;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Sphere")
	class UStaticMeshComponent* Sphere;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Weight")
	class UStaticMeshComponent* Weight;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Pole")
	class UStaticMeshComponent* Pole;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "CartPolePhysics")
	class UPhysicsConstraintComponent* CartPolePhysics;

	UPROPERTY(BlueprintReadOnly, VisibleAnyWhere, Category = "Movement")
	class UFloatingPawnMovement* Movement;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "InputValue")
	float moveSpeed;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "InputValue")
	float failAngle;

	UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "InputValue")
	float maxCnt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "View Target")
	ACameraActor* ViewTarget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player Controller")
	APlayerController* PlayerController;

	float oldAngle;

	int cntStep;

	bool isStarted;
	bool isTrigActing;
	bool isTrigReset;

	struct Struct_Cartpole CartpoleInfo;

	FVector rootOrignPos;
	FVector poleOrignPos;

	AMyClient* myClient;
	

};

