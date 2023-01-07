// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Nakayubi_Copy : ModuleRules
{
	public Nakayubi_Copy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG"});
	}
}
