// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealPaintEditorModeCommands.h"
#include "UnrealPaintEditorMode.h"
#include "EditorStyleSet.h"

#define LOCTEXT_NAMESPACE "UnrealPaintEditorModeCommands"

FUnrealPaintEditorModeCommands::FUnrealPaintEditorModeCommands()
	: TCommands<FUnrealPaintEditorModeCommands>("UnrealPaintEditorMode",
		NSLOCTEXT("UnrealPaintEditorMode", "UnrealPaintEditorModeCommands", "UnrealPaint Editor Mode"),
		NAME_None,
		FAppStyle::GetAppStyleSetName())
{
}

void FUnrealPaintEditorModeCommands::RegisterCommands()
{
	TArray <TSharedPtr<FUICommandInfo>>& ToolCommands = Commands.FindOrAdd(NAME_Default);

	UI_COMMAND(SimpleTool, "Show Actor Info", "Opens message box with info about a clicked actor", EUserInterfaceActionType::Button, FInputChord());
	ToolCommands.Add(SimpleTool);

	UI_COMMAND(InteractiveTool, "Measure Distance", "Measures distance between 2 points (click to set origin, shift-click to set end point)", EUserInterfaceActionType::ToggleButton, FInputChord());
	ToolCommands.Add(InteractiveTool);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> FUnrealPaintEditorModeCommands::GetCommands()
{
	return FUnrealPaintEditorModeCommands::Get().Commands;
}

#undef LOCTEXT_NAMESPACE
