// Fill out your copyright notice in the Description page of Project Settings.


#include "APIWeerGM.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

AAPIWeerGM::AAPIWeerGM()
{
	//API call om JSON data op te vragen via blueprints
	//mHttp = &FHttpModule::Get();

	//Blueprint widget opvragen
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFound(TEXT("/Game/UI/UI_API"));

	//Toewijzen aan de widget pointer
	if (IsValid(WidgetClassFound.Class))
		WeerUI = CreateWidget<UUserWidget>(GetWorld(), WidgetClassFound.Class);
}

void AAPIWeerGM::BeginPlay()
{
	//UI toevoegen aan het scherm
	if(IsValid(WeerUI)) 
		WeerUI->AddToViewport();

	//Player controller opvragen en manipuleren (muis voor UI en enkel camera input toelaten)
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (IsValid(PC))
	{
		PC->bShowMouseCursor = true;
		PC->SetIgnoreMoveInput(true);
	}
}

//API call om JSON data op te vragen via blueprints
/*void AAPIWeerGM::SendHttpGet()
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> request = mHttp->CreateRequest();

	request->OnProcessRequestComplete().BindUObject(this, &AAPIWeerGM::OnGetTimeResponse);
	request->SetURL("");
	request->SetVerb("GET");
}
*/

//API call om JSON data op te vragen via blueprints
/*
void AAPIWeerGM::OnGetTimeResponse(FHttpRequestPtr request, FHttpResponsePtr response, bool bConnectionSucces)
{


}
*/
