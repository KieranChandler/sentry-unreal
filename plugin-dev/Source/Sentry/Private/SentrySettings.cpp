// Copyright (c) 2022 Sentry. All Rights Reserved.

#include "SentrySettings.h"

#include "Misc/Paths.h"
#include "Misc/ConfigCacheIni.h"

USentrySettings::USentrySettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, InitAutomatically(false)
	, EnableVerboseLogging(true)
	, UploadSymbolsAutomatically(false)
{
	DsnUrl = TEXT("");
	Release = TEXT("");
	CrashReporterUrl = TEXT("");

	LoadDebugSymbolsProperties();
}

void USentrySettings::LoadDebugSymbolsProperties()
{
	const FString PropertiesFilePath = FPaths::Combine(FPaths::ProjectDir(), TEXT("sentry.properties"));

	if (FPaths::FileExists(PropertiesFilePath))
	{
		FConfigFile PropertiesFile;
		PropertiesFile.Read(PropertiesFilePath);

		PropertiesFile.GetString(TEXT("Sentry"), TEXT("defaults.project"), ProjectName);
		PropertiesFile.GetString(TEXT("Sentry"), TEXT("defaults.org"), OrgName);
		PropertiesFile.GetString(TEXT("Sentry"), TEXT("auth.token"), AuthToken);
	}
}
