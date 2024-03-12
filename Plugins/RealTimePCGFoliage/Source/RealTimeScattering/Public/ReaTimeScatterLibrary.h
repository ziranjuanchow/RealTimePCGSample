// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReaTimeScatterLibrary.generated.h"
/**
 * 
 */
struct FScatterPoint
{
	float LocationX;
	float LocationY;
	float LocationZ;
	float Scale;
	uint32 RandomID;
	FVector GetLocation()const
	{
		return FVector(LocationX, LocationY, LocationZ);
	}
};
USTRUCT(BlueprintType)
struct FScatterPattern
{
	GENERATED_BODY()	
	TArray<FVector2f> PointCloud;
	FVector2f Size;
};

USTRUCT(BlueprintType)
struct FScatterPointCloud
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadOnly)
	TArray<FVector2f> Points;
	TArray<FScatterPoint> ScatterPoints;
};
struct FPointCloudReadBackBuffer
{
	TResourceArray<uint32> InstanceCountBufferData;
	FBufferRHIRef  InstanceCountBuffer;

	TResourceArray<FScatterPoint>OutputBufferData;
	FBufferRHIRef  OutputBuffer;
	int32 MaxNum;
	void InitBuffer(int32 InMaxNum);
	
	void ReadBackToArray(TArray<FScatterPoint>& OutputData);
};
struct REALTIMESCATTERING_API FBiomePipelineContext
{
	FScatterPattern Pattern;
	TArray<FSpeciesProxy> SpeciesProxys;
	TArray<FScatterPointCloud> ScatterPointCloud;
	FVector4f TotalRect;
	FVector4f DirtyRect;
	UTextureRenderTarget2D* DepthMap;
	float BasicHeight;
	UTextureRenderTarget2D* PlacementMap;
	TArray<UTextureRenderTarget2D*> DensityMaps;
	UTextureRenderTarget2D* OutputDistanceField;
	bool FlipY;
	//Render Thread Resource
	FTextureRenderTargetResource* DepthMapResource;
	FTextureRenderTargetResource* PlacementMapResource;
	TArray<FTextureRenderTargetResource*> DensityResources;
	FTextureRenderTargetResource* OutputDistanceFieldResource;
	TArray<FPointCloudReadBackBuffer> ReadBackBuffers;
	void InitRenderThreadResource();
};
USTRUCT(BlueprintType)
struct REALTIMESCATTERING_API FSpeciesProxy
{
	GENERATED_BODY()
	float Radius;
	float MaxRandomScale;
	float MinRandomScale;
	float Ratio;
};

UCLASS()
class REALTIMESCATTERING_API UReaTimeScatterLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public :
	UFUNCTION(BlueprintCallable)
		static FScatterPattern GetDefaultPattern()
	{
		FScatterPattern Result;
		Result.PointCloud.Add(FVector2f(299.100372314, 94.2850341797));
		Result.PointCloud.Add(FVector2f(563.941162109, 426.259460449));
		Result.PointCloud.Add(FVector2f(250.259140015, 731.499572754));
		Result.PointCloud.Add(FVector2f(768.820617676, 433.105560303));
		Result.PointCloud.Add(FVector2f(123.064186096, 124.732849121));
		Result.PointCloud.Add(FVector2f(788.588500977, 321.672210693));
		Result.PointCloud.Add(FVector2f(539.369995117, 320.49029541));
		Result.PointCloud.Add(FVector2f(162.273880005, 242.290039062));
		Result.PointCloud.Add(FVector2f(63.9281768799, 222.246261597));
		Result.PointCloud.Add(FVector2f(349.455413818, 718.702026367));
		Result.PointCloud.Add(FVector2f(576.486877441, 111.798477173));
		Result.PointCloud.Add(FVector2f(182.860565186, 444.683685303));
		Result.PointCloud.Add(FVector2f(48.6409683228, 16.2424316406));
		Result.PointCloud.Add(FVector2f(20.8261966705, 114.433456421));
		Result.PointCloud.Add(FVector2f(615.319335938, 16.3578987122));
		Result.PointCloud.Add(FVector2f(107.576797485, 630.393310547));
		Result.PointCloud.Add(FVector2f(87.520149231, 532.360961914));
		Result.PointCloud.Add(FVector2f(501.581756592, 178.759414673));
		Result.PointCloud.Add(FVector2f(652.06060791, 691.998962402));
		Result.PointCloud.Add(FVector2f(191.668197632, 25.4294624329));
		Result.PointCloud.Add(FVector2f(262.537139893, 251.08694458));
		Result.PointCloud.Add(FVector2f(150.034927368, 721.16394043));
		Result.PointCloud.Add(FVector2f(73.7247467041, 433.296722412));
		Result.PointCloud.Add(FVector2f(344.359741211, 185.548538208));
		Result.PointCloud.Add(FVector2f(220.077850342, 160.084533691));
		Result.PointCloud.Add(FVector2f(291.227172852, 361.178405762));
		Result.PointCloud.Add(FVector2f(208.991210938, 640.332336426));
		Result.PointCloud.Add(FVector2f(454.791259766, 267.137420654));
		Result.PointCloud.Add(FVector2f(467.73248291, 453.533691406));
		Result.PointCloud.Add(FVector2f(433.826873779, 772.419189453));
		Result.PointCloud.Add(FVector2f(94.1911010742, 335.411437988));
		Result.PointCloud.Add(FVector2f(282.824645996, 460.824768066));
		Result.PointCloud.Add(FVector2f(354.798950195, 530.633850098));
		Result.PointCloud.Add(FVector2f(29.2692661285, 692.633605957));
		Result.PointCloud.Add(FVector2f(194.177505493, 337.065185547));
		Result.PointCloud.Add(FVector2f(452.550689697, 552.374694824));
		Result.PointCloud.Add(FVector2f(684.537902832, 285.854034424));
		Result.PointCloud.Add(FVector2f(373.783935547, 419.274719238));
		Result.PointCloud.Add(FVector2f(420.446716309, 120.303367615));
		Result.PointCloud.Add(FVector2f(513.510314941, 33.8121051788));
		Result.PointCloud.Add(FVector2f(549.304199219, 578.881469727));
		Result.PointCloud.Add(FVector2f(734.299804688, 748.891113281));
		Result.PointCloud.Add(FVector2f(740.079589844, 173.802597046));
		Result.PointCloud.Add(FVector2f(658.208618164, 592.188171387));
		Result.PointCloud.Add(FVector2f(356.469970703, 285.391174316));
		Result.PointCloud.Add(FVector2f(637.091552734, 494.443237305));
		Result.PointCloud.Add(FVector2f(310.234527588, 620.283996582));
		Result.PointCloud.Add(FVector2f(223.607940674, 541.40637207));
		Result.PointCloud.Add(FVector2f(552.208312988, 686.471008301));
		Result.PointCloud.Add(FVector2f(594.380371094, 216.021011353));
		Result.PointCloud.Add(FVector2f(418.842926025, 646.616943359));
		Result.PointCloud.Add(FVector2f(766.980102539, 567.164489746));


		Result.Size.X = Result.Size.Y = 800;
		return Result;
	}
	static FRenderCommandFence BiomeGeneratePipeline(UObject* WorldContextObject,TArray<FBiomePipelineContext>& BiomePipelineContext);
};
