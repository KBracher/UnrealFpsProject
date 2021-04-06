// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FPSProject/FPSProjectHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFPSProjectHUD() {}
// Cross Module References
	FPSPROJECT_API UClass* Z_Construct_UClass_AFPSProjectHUD_NoRegister();
	FPSPROJECT_API UClass* Z_Construct_UClass_AFPSProjectHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_FPSProject();
// End Cross Module References
	void AFPSProjectHUD::StaticRegisterNativesAFPSProjectHUD()
	{
	}
	UClass* Z_Construct_UClass_AFPSProjectHUD_NoRegister()
	{
		return AFPSProjectHUD::StaticClass();
	}
	struct Z_Construct_UClass_AFPSProjectHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFPSProjectHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_FPSProject,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFPSProjectHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "FPSProjectHUD.h" },
		{ "ModuleRelativePath", "FPSProjectHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFPSProjectHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFPSProjectHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFPSProjectHUD_Statics::ClassParams = {
		&AFPSProjectHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFPSProjectHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFPSProjectHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFPSProjectHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFPSProjectHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFPSProjectHUD, 3920806712);
	template<> FPSPROJECT_API UClass* StaticClass<AFPSProjectHUD>()
	{
		return AFPSProjectHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFPSProjectHUD(Z_Construct_UClass_AFPSProjectHUD, &AFPSProjectHUD::StaticClass, TEXT("/Script/FPSProject"), TEXT("AFPSProjectHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFPSProjectHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
