// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Widgets/SCompoundWidget.h"
#include "RealTimePCGFoliageEdMode.h"
#include "Slate/DeferredCleanupSlateBrush.h"
struct FSpeceiesModel
{
	TWeakObjectPtr<USpecies> Species;
	TWeakObjectPtr<UTexture2D> CleanMap;
	TWeakObjectPtr<UTextureRenderTarget2D> DensityMap;
	TSharedPtr<FDeferredCleanupSlateBrush> DensityMapSlateBrush;
	TSharedPtr<FDeferredCleanupSlateBrush> CleanMapSlateBrush;
	FSpeceiesModel(USpecies* InSpecies, UTexture2D* InCleanMap,UTextureRenderTarget2D* InDensityMap);
	TSharedRef<SWidget> CreateWidget()const;
	TSharedRef<SWidget> CreateCleanMapPreview()const;
	TSharedRef<SWidget> CreateDensityMapPreview()const;
};
struct FBiomeModel
{
	TWeakObjectPtr<UBiome> Biome;
	FLinearColor PreviewColor;
	FBiomeModel(UBiome* InBiome, FLinearColor InPreviewColor);
};
/** The palette of foliage types available for use by the foliage edit mode */
class SPCGFoliagePalette : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPCGFoliagePalette) {}
		SLATE_ARGUMENT(SPCGFoliagePalette*, FoliageEdMode)
	SLATE_END_ARGS()

		TSharedRef<ITableRow> GenerateRowForSpeciesList(TSharedPtr<FSpeceiesModel> Item, const TSharedRef<STableViewBase>& OwnerTable);
		TSharedRef<ITableRow> GenerateRowForBiomeList(TSharedPtr<FBiomeModel> Item, const TSharedRef<STableViewBase>& OwnerTable);
		void RefreshBiomeModels();
		void RefreshSpeceiesModels();
		void OnSelectedBiomeChange(TSharedPtr<FBiomeModel> BiomeModel,ESelectInfo::Type SelectType);
		TSharedPtr<FDeferredCleanupSlateBrush> BiomePreviewSlateBrush;
		TArray<TSharedPtr<FSpeceiesModel>> SpeceiesModels;
		TArray<TSharedPtr<FBiomeModel>> BiomeModels;
		TSharedPtr<SListView<TSharedPtr<FSpeceiesModel>>> SpeceiesListView;
		TSharedPtr<SListView<TSharedPtr<FBiomeModel>>> BiomeListView;
		TSharedPtr<class FAssetThumbnailPool> ThumbnailPool;
		FRealTimePCGFoliageEdMode* EdMode;
		void Construct(const FArguments& InArgs);

	
};
