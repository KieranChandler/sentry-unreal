// Copyright (c) 2024 Sentry. All Rights Reserved.

#include "SentryTransactionContextApple.h"

SentryTransactionContextApple::SentryTransactionContextApple(const FString& name, const FString& operation)
{
	TransactionContext = [[SENTRY_APPLE_CLASS(SentryTransactionContext) alloc] initWithName:name.GetNSString() operation:operation.GetNSString()];
}

SentryTransactionContextApple::SentryTransactionContextApple(SentryTransactionContext* context)
{
	TransactionContext = context;
}

SentryTransactionContextApple::~SentryTransactionContextApple()
{
	// Put custom destructor logic here if needed
}

FString SentryTransactionContextApple::GetName() const
{
	return FString(TransactionContext.name);
}

FString SentryTransactionContextApple::GetOperation() const
{
	return FString(TransactionContext.operation);
}

void SentryTransactionContextApple::SetOrigin(const FString& Origin)
{
	TransactionContext.origin = Origin.GetNSString();
}

FString SentryTransactionContextApple::GetOrigin() const
{
	return FString(TransactionContext.origin);
}

SentryTransactionContext* SentryTransactionContextApple::GetNativeObject()
{
	return TransactionContext;
}
