//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


#pragma once

#include "TestFramework/PlayFabTestCase.h"
#include "TestFramework/PlayFabTestContext.h"

#include "PlayFab.h"

#include "PlayFabCppTests.generated.h"

namespace PlayFab
{
    namespace AuthenticationModels
    {
        struct FGetEntityTokenResponse;
    }

    namespace DataModels
    {
        struct FGetObjectsResponse;
    }

    namespace ServerModels
    {
        struct FGetLeaderboardResult;
    }

    namespace ClientModels
    {
        struct FGetAccountInfoResult;
        struct FExecuteCloudScriptResult;
        struct FWriteEventResponse;
        struct FGetLeaderboardResult;
        struct FUpdatePlayerStatisticsResult;
        struct FGetPlayerStatisticsResult;
        struct FUpdateUserDataResult;
        struct FLoginResult;
        struct FGetUserDataResult;
    }

    struct FPlayFabCppError;
}

UCLASS()
class PLAYFABTESTS_API UPlayFabCppTests : public UPlayFabTestCase
{
    GENERATED_BODY()

    // Used to end tests.
    class UPlayFabTestContext* CurrentTestContext = nullptr;

public:

    virtual void GetTests(TArray<UPlayFabTestContext*>& InOutTests) override
    {

        InOutTests.ADD_TEST(Invalid Login (CPP), InvalidLogin);
        InOutTests.ADD_TEST(Login Or Register (CPP), LoginOrRegister);
        InOutTests.ADD_TEST(Login With Advertising ID (CPP), LoginWithAdvertisingID);
        InOutTests.ADD_TEST(User Data API (CPP), UserDataAPI);
        InOutTests.ADD_TEST(Player Statistics API (CPP), PlayerStatisticsAPI);
        InOutTests.ADD_TEST(LeaderBoard API Client (CPP), LeaderBoardAPIClient);
        InOutTests.ADD_TEST(LeaderBoard API Server (CPP), LeaderBoardAPIServer);
        InOutTests.ADD_TEST(Account Info (CPP), AccountInfo);
        InOutTests.ADD_TEST(Cloud Script (CPP), CloudScript);
        InOutTests.ADD_TEST(Cloud Script Error (CPP), CloudScriptError);
        InOutTests.ADD_TEST(Write Event (CPP), WriteEvent);

        InOutTests.ADD_TEST(Get Entity Token (CPP), GetEntityToken);
        InOutTests.ADD_TEST(Object API (CPP), ObjectAPI);
    }
    
    PlayFabClientPtr ClientAPI;
    PlayFabServerPtr ServerAPI;
    PlayFabAuthenticationPtr AuthenticationAPI;
    PlayFabDataPtr DataAPI;

    virtual void ClassSetUp() override;
    virtual void SetUp(UPlayFabTestContext* testContext) override;

    /**
     * Shared Error callback.
     * @param InError The PlayFab Error.
     * @param InCustomData Additional data about this Error.
     */
    void OnSharedError(const PlayFab::FPlayFabCppError& InError) const;
    

    UFUNCTION()
    void InvalidLogin();
    void InvalidLogin_Success(const PlayFab::ClientModels::FLoginResult& result);
    void InvalidLogin_Error(const PlayFab::FPlayFabCppError& InErrorResult); // Expected Result

    UFUNCTION()
    void LoginOrRegister();
    void LoginOrRegister_Success(const PlayFab::ClientModels::FLoginResult& result);

    UFUNCTION()
    void LoginWithAdvertisingID();
    void LoginWithAdvertisingID_Success(const PlayFab::ClientModels::FLoginResult& result);

    void CheckIfLoggedIn();

    int UserDataAPI_ExpectedValue = -1;

    UFUNCTION()
    void UserDataAPI();
    void GetUserDataAPI_Success(const PlayFab::ClientModels::FGetUserDataResult& result);
    void UpdateUserDataAPI_Success(const PlayFab::ClientModels::FUpdateUserDataResult& result);

    int PlayerStatistics_ExpectedValue = -1;

    UFUNCTION()
    void PlayerStatisticsAPI();
    void GetPlayerStatisticsAPI_Success(const PlayFab::ClientModels::FGetPlayerStatisticsResult& result);
    void UpdatePlayerStatisticsAPI_Success(const PlayFab::ClientModels::FUpdatePlayerStatisticsResult& result);

    UFUNCTION()
    void LeaderBoardAPIClient();
    void LeaderBoardAPIClient_Success(const PlayFab::ClientModels::FGetLeaderboardResult& result);

    UFUNCTION()
    void LeaderBoardAPIServer();
    void LeaderBoardAPIServer_Success(const PlayFab::ServerModels::FGetLeaderboardResult& result);

    UFUNCTION()
    void AccountInfo();
    void AccountInfo_Success(const PlayFab::ClientModels::FGetAccountInfoResult& result);

    FString CLOUD_FUNCTION_HELLO_WORLD = TEXT("helloWorld");

    UFUNCTION()
    void CloudScript();
    void CloudScript_Success(const PlayFab::ClientModels::FExecuteCloudScriptResult& result);

    FString CLOUD_FUNCTION_THROW_ERROR = TEXT("throwError");

    UFUNCTION()
    void CloudScriptError();
    void CloudScriptError_Success(const PlayFab::ClientModels::FExecuteCloudScriptResult& result);

    UFUNCTION()
    void WriteEvent();
    void WriteEvent_Success(const PlayFab::ClientModels::FWriteEventResponse& result);    


    UFUNCTION()
    void GetEntityToken();
    void GetEntityToken_Success(const PlayFab::AuthenticationModels::FGetEntityTokenResponse& result);

    UFUNCTION()
    void ObjectAPI();
    void ObjectAPI_Success(const PlayFab::DataModels::FGetObjectsResponse& result);
};
