#pragma once
#include "EngineModule.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "DataDrivenShaderPlatformInfo.h"

#define LOCTEXT_NAMESPACE "GraphicToolsPlugin"

#define NUM_THREADS_PER_GROUP_DIMENSION 64

/// <summary>
/// Internal class thet holds the parameters and connects the HLSL Shader to the engine
/// </summary>
///

class FGPUScatteringCS : public FGlobalShader
{
public:

	//Declare this class as a global shader
	DECLARE_GLOBAL_SHADER(FGPUScatteringCS);
	//Tells the engine that this shader uses a structure for its parameters
	SHADER_USE_PARAMETER_STRUCT(FGPUScatteringCS, FGlobalShader);
	/// <summary>
	/// DECLARATION OF THE PARAMETER STRUCTURE
	/// The parameters must match the parameters in the HLSL code
	/// For each parameter, provide the C++ type, and the name (Same name used in HLSL code)
	/// </summary>
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_UAV(RWStructuredBuffer<uint>, InstanceCountBuffer)
		SHADER_PARAMETER_SCALAR_ARRAY(float, InputPattern, [128])
		SHADER_PARAMETER(FVector2f, PatternSize)
		SHADER_PARAMETER(uint32, PatternPointNum)
		SHADER_PARAMETER_TEXTURE(Texture2D, InputTexture)
		SHADER_PARAMETER_TEXTURE(Texture2D, DepthTexture)
		SHADER_PARAMETER_TEXTURE(Texture2D, PlacementSDF)
		SHADER_PARAMETER_TEXTURE(Texture2D, InputSDF)
		SHADER_PARAMETER_UAV(RWTexture2D<float>, OutputSDF)
		SHADER_PARAMETER_SAMPLER(SamplerState, LinearSampler)
		SHADER_PARAMETER(float,BasicHeight)
		SHADER_PARAMETER(FIntPoint,CenterOffset)
		SHADER_PARAMETER(FVector4f, TotalRect)
		SHADER_PARAMETER(FVector4f, ClipRect)
		SHADER_PARAMETER(float, Ratio)
		SHADER_PARAMETER(float, MaxRandomScale)
		SHADER_PARAMETER(float, MinRandomScale)
		SHADER_PARAMETER(float, RadiusScale)
		SHADER_PARAMETER(uint32, FlipY)
		SHADER_PARAMETER_UAV(RWStructuredBuffer<FScatterPoint>, OutputPointCloud)


		END_SHADER_PARAMETER_STRUCT()

public:
	//Called by the engine to determine which permutations to compile for this shader
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{

		return IsFeatureLevelSupported(Parameters.Platform, ERHIFeatureLevel::SM5);
	}

	//Modifies the compilations environment of the shader
	static inline void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		FGlobalShader::ModifyCompilationEnvironment(Parameters, OutEnvironment);

		//We're using it here to add some preprocessor defines. That way we don't have to change both C++ and HLSL code when we change the value for NUM_THREADS_PER_GROUP_DIMENSION
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_X"), NUM_THREADS_PER_GROUP_DIMENSION);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Y"), 1);
		OutEnvironment.SetDefine(TEXT("THREADGROUPSIZE_Z"), 1);
	}

};

#undef NUM_THREADS_PER_GROUP_DIMENSION

#undef LOCTEXT_NAMESPACE
