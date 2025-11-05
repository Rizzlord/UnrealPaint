// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealPaintEditorMode.h"
#include "UnrealPaintEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "UnrealPaintEditorModeCommands.h"
#include "Modules/ModuleManager.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/UnrealPaintSimpleTool.h"
#include "Tools/UnrealPaintInteractiveTool.h"

// step 2: register a ToolBuilder in FUnrealPaintEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "UnrealPaintEditorMode"

const FEditorModeID UUnrealPaintEditorMode::EM_UnrealPaintEditorModeId = TEXT("EM_UnrealPaintEditorMode");

FString UUnrealPaintEditorMode::SimpleToolName = TEXT("UnrealPaint_ActorInfoTool");
FString UUnrealPaintEditorMode::InteractiveToolName = TEXT("UnrealPaint_MeasureDistanceTool");


UUnrealPaintEditorMode::UUnrealPaintEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UUnrealPaintEditorMode::EM_UnrealPaintEditorModeId,
		LOCTEXT("ModeName", "UnrealPaint"),
		FSlateIcon(),
		true);
}


UUnrealPaintEditorMode::~UUnrealPaintEditorMode()
{
}


void UUnrealPaintEditorMode::ActorSelectionChangeNotify()
{
}

void UUnrealPaintEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FUnrealPaintEditorModeCommands& SampleToolCommands = FUnrealPaintEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UUnrealPaintSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UUnrealPaintInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UUnrealPaintEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FUnrealPaintEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UUnrealPaintEditorMode::GetModeCommands() const
{
	return FUnrealPaintEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
