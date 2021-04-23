// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ForTestTP/ForTestTPGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeForTestTPGameMode() {}
// Cross Module References
	FORTESTTP_API UClass* Z_Construct_UClass_AForTestTPGameMode_NoRegister();
	FORTESTTP_API UClass* Z_Construct_UClass_AForTestTPGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ForTestTP();
// End Cross Module References
	void AForTestTPGameMode::StaticRegisterNativesAForTestTPGameMode()
	{
	}
	UClass* Z_Construct_UClass_AForTestTPGameMode_NoRegister()
	{
		return AForTestTPGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AForTestTPGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AForTestTPGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ForTestTP,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AForTestTPGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ForTestTPGameMode.h" },
		{ "ModuleRelativePath", "ForTestTPGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AForTestTPGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AForTestTPGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AForTestTPGameMode_Statics::ClassParams = {
		&AForTestTPGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AForTestTPGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AForTestTPGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AForTestTPGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AForTestTPGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AForTestTPGameMode, 1595842424);
	template<> FORTESTTP_API UClass* StaticClass<AForTestTPGameMode>()
	{
		return AForTestTPGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AForTestTPGameMode(Z_Construct_UClass_AForTestTPGameMode, &AForTestTPGameMode::StaticClass, TEXT("/Script/ForTestTP"), TEXT("AForTestTPGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AForTestTPGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
