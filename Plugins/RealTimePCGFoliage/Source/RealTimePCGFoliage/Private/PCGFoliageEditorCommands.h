// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorStyleSet.h"
#include "Framework/Commands/Commands.h"

/**
 * Unreal Foliage Edit mode actions
 */
class FPCGFoliageEditorCommands : public TCommands<FPCGFoliageEditorCommands>
{

public:
	FPCGFoliageEditorCommands() : TCommands<FPCGFoliageEditorCommands>
	(
		"RealTimePCGFoliageEdMode", // Context name for fast lookup
		NSLOCTEXT("Contexts", "RealTimePCGFoliageEdMode", "Real Time ProcedualFoliage"), // Localized context name for displaying
		NAME_None, // Parent
		FAppStyle::GetAppStyleSetName() // Icon Style Set
	)
	{
	}
	
	/**
	 * Foliage Edit Commands
	 */
	
	/** Commands for the foliage brush settings. */
	TSharedPtr< FUICommandInfo > IncreaseBrushSize;
	TSharedPtr< FUICommandInfo > DecreaseBrushSize;

	TSharedPtr< FUICommandInfo > IncreasePaintDensity;
	TSharedPtr< FUICommandInfo > DecreasePaintDensity;

	TSharedPtr< FUICommandInfo > IncreaseUnpaintDensity;
	TSharedPtr< FUICommandInfo > DecreaseUnpaintDensity;

	/** Commands for the tools toolbar. */
	TSharedPtr< FUICommandInfo > SetPaint;
	TSharedPtr< FUICommandInfo > SetErase;
	/** Commands for the foliage item toolbar. */
	TSharedPtr< FUICommandInfo > SetNoSettings;
	TSharedPtr< FUICommandInfo > SetPaintSettings;
	TSharedPtr< FUICommandInfo > SetClusterSettings;

	/** FoliageType commands */
	TSharedPtr< FUICommandInfo > RemoveFoliageType;
	TSharedPtr< FUICommandInfo > ShowFoliageTypeInCB;
	TSharedPtr< FUICommandInfo > SelectAllInstances;
	TSharedPtr< FUICommandInfo > DeselectAllInstances;
	TSharedPtr< FUICommandInfo > SelectInvalidInstances;
	/**
	 * Initialize commands
	 */
	TSharedPtr< FUICommandInfo > SetPaintSpecies;
	TSharedPtr< FUICommandInfo > SetPaintBiome;
	virtual void RegisterCommands() override;

public:
};
