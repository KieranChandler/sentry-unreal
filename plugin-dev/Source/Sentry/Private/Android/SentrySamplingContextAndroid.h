﻿// Copyright (c) 2024 Sentry. All Rights Reserved.

#pragma once

#include "Interface/SentrySamplingContextInterface.h"

#include "Infrastructure/SentryJavaObjectWrapper.h"

class SentrySamplingContextAndroid : public ISentrySamplingContext, public FSentryJavaObjectWrapper
{
public:
	SentrySamplingContextAndroid(jobject samplingContext);

	void SetupClassMethods();

	virtual TMap<FString, FString> GetCustomSamplingContext() const override;

private:
	FSentryJavaMethod GetCustomSamplingContextMethod;
};