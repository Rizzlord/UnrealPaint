// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealPaintModule.h"
#include "UnrealPaintEditorModeCommands.h"

#define LOCTEXT_NAMESPACE "UnrealPaintModule"

void FUnrealPaintModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FUnrealPaintEditorModeCommands::Register();
}

void FUnrealPaintModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FUnrealPaintEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealPaintModule, UnrealPaint)