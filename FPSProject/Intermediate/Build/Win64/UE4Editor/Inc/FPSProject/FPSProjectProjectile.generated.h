// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef FPSPROJECT_FPSProjectProjectile_generated_h
#error "FPSProjectProjectile.generated.h already included, missing '#pragma once' in FPSProjectProjectile.h"
#endif
#define FPSPROJECT_FPSProjectProjectile_generated_h

#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_SPARSE_DATA
#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSProjectProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFPSProjectProjectile(); \
	friend struct Z_Construct_UClass_AFPSProjectProjectile_Statics; \
public: \
	DECLARE_CLASS(AFPSProjectProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AFPSProjectProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSProjectProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSProjectProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectProjectile(AFPSProjectProjectile&&); \
	NO_API AFPSProjectProjectile(const AFPSProjectProjectile&); \
public:


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSProjectProjectile(AFPSProjectProjectile&&); \
	NO_API AFPSProjectProjectile(const AFPSProjectProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSProjectProjectile); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSProjectProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFPSProjectProjectile)


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AFPSProjectProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AFPSProjectProjectile, ProjectileMovement); }


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_12_PROLOG
#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_SPARSE_DATA \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_RPC_WRAPPERS \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_INCLASS \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_SPARSE_DATA \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_FPSProjectProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSPROJECT_API UClass* StaticClass<class AFPSProjectProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSProject_Source_FPSProject_FPSProjectProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
