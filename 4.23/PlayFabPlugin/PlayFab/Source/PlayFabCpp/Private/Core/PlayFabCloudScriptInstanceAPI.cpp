//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#include "Core/PlayFabCloudScriptInstanceAPI.h"
#include "Core/PlayFabSettings.h"
#include "Core/PlayFabResultHandler.h"
#include "PlayFab.h"

using namespace PlayFab;
using namespace PlayFab::CloudScriptModels;

UPlayFabCloudScriptInstanceAPI::UPlayFabCloudScriptInstanceAPI()
{
}

UPlayFabCloudScriptInstanceAPI::UPlayFabCloudScriptInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

UPlayFabCloudScriptInstanceAPI::UPlayFabCloudScriptInstanceAPI(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabCloudScriptInstanceAPI::UPlayFabCloudScriptInstanceAPI(TSharedPtr<UPlayFabAPISettings> apiSettings, TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->settings = MoveTemp(apiSettings);
    this->authContext = MoveTemp(authenticationContext);
}

UPlayFabCloudScriptInstanceAPI::~UPlayFabCloudScriptInstanceAPI()
{
}

TSharedPtr<UPlayFabAPISettings> UPlayFabCloudScriptInstanceAPI::GetSettings() const
{
    return this->settings;
}

int UPlayFabCloudScriptInstanceAPI::GetPendingCalls() const
{
    return PlayFabRequestHandler::GetPendingCalls();
}

void UPlayFabCloudScriptInstanceAPI::SetSettings(TSharedPtr<UPlayFabAPISettings> apiSettings)
{
    this->settings = MoveTemp(apiSettings);
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabCloudScriptInstanceAPI::GetAuthenticationContext() const
{
    return this->authContext;
}

void UPlayFabCloudScriptInstanceAPI::SetAuthenticationContext(TSharedPtr<UPlayFabAuthenticationContext> authenticationContext)
{
    this->authContext = MoveTemp(authenticationContext);
}

void UPlayFabCloudScriptInstanceAPI::ForgetAllCredentials()
{
    if (!this->authContext.IsValid())
        return;

    this->authContext->ForgetAllCredentials();
}

TSharedPtr<UPlayFabAuthenticationContext> UPlayFabCloudScriptInstanceAPI::GetOrCreateAuthenticationContext()
{
    if (!this->authContext.IsValid())
        this->authContext = MakeSharedUObject<UPlayFabAuthenticationContext>();

    return this->authContext;
}

bool UPlayFabCloudScriptInstanceAPI::ExecuteEntityCloudScript(
    CloudScriptModels::FExecuteEntityCloudScriptRequest& request,
    const FExecuteEntityCloudScriptDelegate& SuccessDelegate,
    const FPlayFabErrorDelegate& ErrorDelegate)
{
    if ((request.AuthenticationContext.IsValid() && request.AuthenticationContext->GetEntityToken().Len() == 0)
        || (!request.AuthenticationContext.IsValid() && this->GetOrCreateAuthenticationContext()->GetEntityToken().Len() == 0)) {
        UE_LOG(LogPlayFabCpp, Error, TEXT("You must call GetEntityToken API Method before calling this function."));
    }


    auto HttpRequest = PlayFabRequestHandler::SendRequest(!this->settings.IsValid() ? PlayFabSettings::GetUrl(TEXT("/CloudScript/ExecuteEntityCloudScript")) : this->settings->GetUrl(TEXT("/CloudScript/ExecuteEntityCloudScript")), request.toJSONString(), TEXT("X-EntityToken"), !request.AuthenticationContext.IsValid() ? this->GetOrCreateAuthenticationContext()->GetEntityToken() : request.AuthenticationContext->GetEntityToken());
    HttpRequest->OnProcessRequestComplete().BindRaw(this, &UPlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult, SuccessDelegate, ErrorDelegate);
    return HttpRequest->ProcessRequest();
}

void UPlayFabCloudScriptInstanceAPI::OnExecuteEntityCloudScriptResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FExecuteEntityCloudScriptDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate)
{
    CloudScriptModels::FExecuteCloudScriptResult outResult;
    FPlayFabCppError errorResult;
    if (PlayFabRequestHandler::DecodeRequest(HttpRequest, HttpResponse, bSucceeded, outResult, errorResult))
    {
        SuccessDelegate.ExecuteIfBound(outResult);
    }
    else
    {
        ErrorDelegate.ExecuteIfBound(errorResult);
    }
}
