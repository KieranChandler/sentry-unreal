﻿// Copyright (c) 2024 Sentry. All Rights Reserved.

#pragma once

#include "Interface/SentrySamplingContextInterface.h"

@class SentrySamplingContext;

class SentrySamplingContextApple : public ISentrySamplingContext
{
public:
	SentrySamplingContextApple(SentrySamplingContext* context);
	virtual ~SentrySamplingContextApple() override;

	SentrySamplingContext* GetNativeObject();

private:
	SentrySamplingContext* SamplingContext;
};
