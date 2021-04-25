// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ForTestTP/Public/InteractableEntity.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractableEntity() {}
// Cross Module References
	FORTESTTP_API UClass* Z_Construct_UClass_AInteractableEntity_NoRegister();
	FORTESTTP_API UClass* Z_Construct_UClass_AInteractableEntity();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ForTestTP();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AInteractableEntity::execInteract)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Interact();
		P_NATIVE_END;
	}
	void AInteractableEntity::StaticRegisterNativesAInteractableEntity()
	{
		UClass* Class = AInteractableEntity::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Interact", &AInteractableEntity::execInteract },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractableEntity_Interact_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractableEntity_Interact_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/InteractableEntity.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractableEntity_Interact_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractableEntity, nullptr, "Interact", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AInteractableEntity_Interact_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractableEntity_Interact_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AInteractableEntity_Interact()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AInteractableEntity_Interact_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AInteractableEntity_NoRegister()
	{
		return AInteractableEntity::StaticClass();
	}
	struct Z_Construct_UClass_AInteractableEntity_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_center_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_center;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_shape_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_shape;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInteractableEntity_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ForTestTP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AInteractableEntity_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInteractableEntity_Interact, "Interact" }, // 1180491776
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractableEntity_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InteractableEntity.h" },
		{ "ModuleRelativePath", "Public/InteractableEntity.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractableEntity_Statics::NewProp_center_MetaData[] = {
		{ "Category", "InteractableEntity" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InteractableEntity.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInteractableEntity_Statics::NewProp_center = { "center", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AInteractableEntity, center), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInteractableEntity_Statics::NewProp_center_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractableEntity_Statics::NewProp_center_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractableEntity_Statics::NewProp_shape_MetaData[] = {
		{ "Category", "InteractableEntity" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/InteractableEntity.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInteractableEntity_Statics::NewProp_shape = { "shape", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AInteractableEntity, shape), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AInteractableEntity_Statics::NewProp_shape_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractableEntity_Statics::NewProp_shape_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInteractableEntity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractableEntity_Statics::NewProp_center,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractableEntity_Statics::NewProp_shape,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInteractableEntity_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractableEntity>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AInteractableEntity_Statics::ClassParams = {
		&AInteractableEntity::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AInteractableEntity_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AInteractableEntity_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AInteractableEntity_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AInteractableEntity_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AInteractableEntity()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AInteractableEntity_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AInteractableEntity, 3887396609);
	template<> FORTESTTP_API UClass* StaticClass<AInteractableEntity>()
	{
		return AInteractableEntity::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AInteractableEntity(Z_Construct_UClass_AInteractableEntity, &AInteractableEntity::StaticClass, TEXT("/Script/ForTestTP"), TEXT("AInteractableEntity"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractableEntity);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
