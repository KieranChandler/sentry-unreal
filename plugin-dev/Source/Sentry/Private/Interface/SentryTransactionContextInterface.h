// Copyright (c) 2024 Sentry. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ISentryTransactionContext
{
public:
	virtual ~ISentryTransactionContext() = default;

	virtual void SetName(const FString& Name) = 0;
	virtual FString GetName() const = 0;
	virtual void SetOrigin(const FString& Name) = 0;
	virtual FString GetOrigin() const = 0;
	virtual void SetOperation(const FString& Name) = 0;
	virtual FString GetOperation() const = 0;
};