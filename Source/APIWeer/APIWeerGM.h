// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Http.h"
#include "APIWeerGM.generated.h"

/**
 * 
 */
UCLASS()
class APIWEER_API AAPIWeerGM : public AGameModeBase
{
	GENERATED_BODY()

public:

	AAPIWeerGM();

protected:

	virtual void BeginPlay() override;

	//API call om JSON data op te vragen via blueprints
	/*UFUNCTION(BlueprintCallable)
	void SendHttpGet();

	void OnGetTimeResponse(FHttpRequestPtr request, FHttpResponsePtr response, bool bConnectionSucces);*/

	//User widget met garbage collection
	UPROPERTY()
	class UUserWidget* WeerUI;

private:
	
	//API call om JSON data op te vragen via blueprints
	//FHttpModule* mHttp;
	
};
