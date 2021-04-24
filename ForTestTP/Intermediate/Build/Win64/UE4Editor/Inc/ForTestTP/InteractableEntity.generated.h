// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FORTESTTP_InteractableEntity_generated_h
#error "InteractableEntity.generated.h already included, missing '#pragma once' in InteractableEntity.h"
#endif
#define FORTESTTP_InteractableEntity_generated_h

#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_SPARSE_DATA
#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execShowText); \
	DECLARE_FUNCTION(execInteract);


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execShowText); \
	DECLARE_FUNCTION(execInteract);


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAInteractableEntity(); \
	friend struct Z_Construct_UClass_AInteractableEntity_Statics; \
public: \
	DECLARE_CLASS(AInteractableEntity, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ForTestTP"), NO_API) \
	DECLARE_SERIALIZER(AInteractableEntity)


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAInteractableEntity(); \
	friend struct Z_Construct_UClass_AInteractableEntity_Statics; \
public: \
	DECLARE_CLASS(AInteractableEntity, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ForTestTP"), NO_API) \
	DECLARE_SERIALIZER(AInteractableEntity)


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AInteractableEntity(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AInteractableEntity) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractableEntity); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractableEntity); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractableEntity(AInteractableEntity&&); \
	NO_API AInteractableEntity(const AInteractableEntity&); \
public:


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AInteractableEntity(AInteractableEntity&&); \
	NO_API AInteractableEntity(const AInteractableEntity&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AInteractableEntity); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AInteractableEntity); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AInteractableEntity)


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_PRIVATE_PROPERTY_OFFSET
#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_9_PROLOG
#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_PRIVATE_PROPERTY_OFFSET \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_SPARSE_DATA \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_RPC_WRAPPERS \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_INCLASS \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_PRIVATE_PROPERTY_OFFSET \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_SPARSE_DATA \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_INCLASS_NO_PURE_DECLS \
	ForTestTP_Source_ForTestTP_Public_InteractableEntity_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FORTESTTP_API UClass* StaticClass<class AInteractableEntity>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ForTestTP_Source_ForTestTP_Public_InteractableEntity_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
