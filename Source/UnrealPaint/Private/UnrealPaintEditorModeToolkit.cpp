// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealPaintEditorModeToolkit.h"
#include "UnrealPaintEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "UnrealPaintEditorModeToolkit"

FUnrealPaintEditorModeToolkit::FUnrealPaintEditorModeToolkit()
{
}

void FUnrealPaintEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FUnrealPaintEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FUnrealPaintEditorModeToolkit::GetToolkitFName() const
{
	return FName("UnrealPaintEditorMode");
}

FText FUnrealPaintEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "UnrealPaintEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
