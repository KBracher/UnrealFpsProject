// Copyright Epic Games, Inc. All Rights Reserved.

#include "UObject/ConstructorHelpers.h"
#include "FPSProjectHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "FPSProjectGameMode.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>


AFPSProjectHUD::AFPSProjectHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;
}


void AFPSProjectHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	const FVector2D Hd(Canvas->ClipX - 170 , 20);
	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X-8),
										   (Center.Y -8));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);

	AFPSProjectGameMode * MyMode = Cast< AFPSProjectGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	FString text = "Wave  : " + FString::FromInt(MyMode->nbWave);
	DrawText(text, FLinearColor::Black, Hd.X, Hd.Y, NULL, 2.0, false);

	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void AFPSProjectHUD::WaveUpdate()
{

}
