// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FPSPROJECT_Enemy_Controller_generated_h
#error "Enemy_Controller.generated.h already included, missing '#pragma once' in Enemy_Controller.h"
#endif
#define FPSPROJECT_Enemy_Controller_generated_h

#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_SPARSE_DATA
#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_RPC_WRAPPERS
#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemy_Controller(); \
	friend struct Z_Construct_UClass_AEnemy_Controller_Statics; \
public: \
	DECLARE_CLASS(AEnemy_Controller, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemy_Controller)


#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAEnemy_Controller(); \
	friend struct Z_Construct_UClass_AEnemy_Controller_Statics; \
public: \
	DECLARE_CLASS(AEnemy_Controller, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FPSProject"), NO_API) \
	DECLARE_SERIALIZER(AEnemy_Controller)


#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy_Controller(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy_Controller) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy_Controller); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy_Controller); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy_Controller(AEnemy_Controller&&); \
	NO_API AEnemy_Controller(const AEnemy_Controller&); \
public:


#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AEnemy_Controller(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AEnemy_Controller(AEnemy_Controller&&); \
	NO_API AEnemy_Controller(const AEnemy_Controller&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemy_Controller); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemy_Controller); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AEnemy_Controller)


#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_PRIVATE_PROPERTY_OFFSET
#define FPSProject_Source_FPSProject_Enemy_Controller_h_12_PROLOG
#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_SPARSE_DATA \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_RPC_WRAPPERS \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_INCLASS \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FPSProject_Source_FPSProject_Enemy_Controller_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_PRIVATE_PROPERTY_OFFSET \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_SPARSE_DATA \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_INCLASS_NO_PURE_DECLS \
	FPSProject_Source_FPSProject_Enemy_Controller_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FPSPROJECT_API UClass* StaticClass<class AEnemy_Controller>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FPSProject_Source_FPSProject_Enemy_Controller_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
