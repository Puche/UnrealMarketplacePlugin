//////////////////////////////////////////////////////
// Copyright (C) Microsoft. 2018. All rights reserved.
//////////////////////////////////////////////////////


// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "Core/PlayFabError.h"
#include "Core/PlayFabMultiplayerDataModels.h"
#include "Core/PlayFabSettings.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

namespace PlayFab
{
    class PLAYFABCPP_API UPlayFabMultiplayerAPI
    {
    public:
        DECLARE_DELEGATE_OneParam(FCancelAllMatchmakingTicketsForPlayerDelegate, const MultiplayerModels::FCancelAllMatchmakingTicketsForPlayerResult&);
        DECLARE_DELEGATE_OneParam(FCancelMatchmakingTicketDelegate, const MultiplayerModels::FCancelMatchmakingTicketResult&);
        DECLARE_DELEGATE_OneParam(FCreateBuildWithCustomContainerDelegate, const MultiplayerModels::FCreateBuildWithCustomContainerResponse&);
        DECLARE_DELEGATE_OneParam(FCreateBuildWithManagedContainerDelegate, const MultiplayerModels::FCreateBuildWithManagedContainerResponse&);
        DECLARE_DELEGATE_OneParam(FCreateMatchmakingTicketDelegate, const MultiplayerModels::FCreateMatchmakingTicketResult&);
        DECLARE_DELEGATE_OneParam(FCreateRemoteUserDelegate, const MultiplayerModels::FCreateRemoteUserResponse&);
        DECLARE_DELEGATE_OneParam(FCreateServerMatchmakingTicketDelegate, const MultiplayerModels::FCreateMatchmakingTicketResult&);
        DECLARE_DELEGATE_OneParam(FDeleteAssetDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FDeleteBuildDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FDeleteCertificateDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FDeleteRemoteUserDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FEnableMultiplayerServersForTitleDelegate, const MultiplayerModels::FEnableMultiplayerServersForTitleResponse&);
        DECLARE_DELEGATE_OneParam(FGetAssetUploadUrlDelegate, const MultiplayerModels::FGetAssetUploadUrlResponse&);
        DECLARE_DELEGATE_OneParam(FGetBuildDelegate, const MultiplayerModels::FGetBuildResponse&);
        DECLARE_DELEGATE_OneParam(FGetContainerRegistryCredentialsDelegate, const MultiplayerModels::FGetContainerRegistryCredentialsResponse&);
        DECLARE_DELEGATE_OneParam(FGetMatchDelegate, const MultiplayerModels::FGetMatchResult&);
        DECLARE_DELEGATE_OneParam(FGetMatchmakingTicketDelegate, const MultiplayerModels::FGetMatchmakingTicketResult&);
        DECLARE_DELEGATE_OneParam(FGetMultiplayerServerDetailsDelegate, const MultiplayerModels::FGetMultiplayerServerDetailsResponse&);
        DECLARE_DELEGATE_OneParam(FGetQueueStatisticsDelegate, const MultiplayerModels::FGetQueueStatisticsResult&);
        DECLARE_DELEGATE_OneParam(FGetRemoteLoginEndpointDelegate, const MultiplayerModels::FGetRemoteLoginEndpointResponse&);
        DECLARE_DELEGATE_OneParam(FGetTitleEnabledForMultiplayerServersStatusDelegate, const MultiplayerModels::FGetTitleEnabledForMultiplayerServersStatusResponse&);
        DECLARE_DELEGATE_OneParam(FGetTitleMultiplayerServersQuotasDelegate, const MultiplayerModels::FGetTitleMultiplayerServersQuotasResponse&);
        DECLARE_DELEGATE_OneParam(FJoinMatchmakingTicketDelegate, const MultiplayerModels::FJoinMatchmakingTicketResult&);
        DECLARE_DELEGATE_OneParam(FListArchivedMultiplayerServersDelegate, const MultiplayerModels::FListMultiplayerServersResponse&);
        DECLARE_DELEGATE_OneParam(FListAssetSummariesDelegate, const MultiplayerModels::FListAssetSummariesResponse&);
        DECLARE_DELEGATE_OneParam(FListBuildSummariesDelegate, const MultiplayerModels::FListBuildSummariesResponse&);
        DECLARE_DELEGATE_OneParam(FListCertificateSummariesDelegate, const MultiplayerModels::FListCertificateSummariesResponse&);
        DECLARE_DELEGATE_OneParam(FListContainerImagesDelegate, const MultiplayerModels::FListContainerImagesResponse&);
        DECLARE_DELEGATE_OneParam(FListContainerImageTagsDelegate, const MultiplayerModels::FListContainerImageTagsResponse&);
        DECLARE_DELEGATE_OneParam(FListMatchmakingTicketsForPlayerDelegate, const MultiplayerModels::FListMatchmakingTicketsForPlayerResult&);
        DECLARE_DELEGATE_OneParam(FListMultiplayerServersDelegate, const MultiplayerModels::FListMultiplayerServersResponse&);
        DECLARE_DELEGATE_OneParam(FListPartyQosServersDelegate, const MultiplayerModels::FListPartyQosServersResponse&);
        DECLARE_DELEGATE_OneParam(FListQosServersDelegate, const MultiplayerModels::FListQosServersResponse&);
        DECLARE_DELEGATE_OneParam(FListQosServersForTitleDelegate, const MultiplayerModels::FListQosServersForTitleResponse&);
        DECLARE_DELEGATE_OneParam(FListVirtualMachineSummariesDelegate, const MultiplayerModels::FListVirtualMachineSummariesResponse&);
        DECLARE_DELEGATE_OneParam(FRequestMultiplayerServerDelegate, const MultiplayerModels::FRequestMultiplayerServerResponse&);
        DECLARE_DELEGATE_OneParam(FRolloverContainerRegistryCredentialsDelegate, const MultiplayerModels::FRolloverContainerRegistryCredentialsResponse&);
        DECLARE_DELEGATE_OneParam(FShutdownMultiplayerServerDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FUpdateBuildRegionsDelegate, const MultiplayerModels::FEmptyResponse&);
        DECLARE_DELEGATE_OneParam(FUploadCertificateDelegate, const MultiplayerModels::FEmptyResponse&);

        UPlayFabMultiplayerAPI();
        ~UPlayFabMultiplayerAPI();

        int GetPendingCalls() const;
        FString GetBuildIdentifier() const;
        void SetTitleId(const FString& titleId);
        void SetDevSecretKey(const FString& developerSecretKey);

        // ------------ Generated API calls
        /**
         * Cancel all active tickets the player is a member of in a given queue.
         * Cancels all tickets of which the player is a member in a given queue that are not cancelled or matched. This API is useful if you lose track of what tickets the player is a member of (if the title crashes for instance) and want to "reset". The Entity field is optional if the caller is a player and defaults to that player. Players may not cancel tickets for other people. The Entity field is required if the caller is a server (authenticated as the title).
         */
        bool CancelAllMatchmakingTicketsForPlayer(MultiplayerModels::FCancelAllMatchmakingTicketsForPlayerRequest& request, const FCancelAllMatchmakingTicketsForPlayerDelegate& SuccessDelegate = FCancelAllMatchmakingTicketsForPlayerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Cancel a matchmaking ticket.
         * Only servers and ticket members can cancel a ticket. The ticket can be in five different states when it is cancelled. 1: the ticket is waiting for members to join it, and it has not started matching. If the ticket is cancelled at this stage, it will never match. 2: the ticket is matching. If the ticket is cancelled, it will stop matching. 3: the ticket is matched. A matched ticket cannot be cancelled. 4: the ticket is already cancelled and nothing happens. 5: the ticket is waiting for a server. If the ticket is cancelled, server allocation will be stopped. A server may still be allocated due to a race condition, but that will not be reflected in the ticket. There may be race conditions between the ticket getting matched and the client making a cancellation request. The client must handle the possibility that the cancel request fails if a match is found before the cancellation request is processed. We do not allow resubmitting a cancelled ticket because players must consent to enter matchmaking again. Create a new ticket instead.
         */
        bool CancelMatchmakingTicket(MultiplayerModels::FCancelMatchmakingTicketRequest& request, const FCancelMatchmakingTicketDelegate& SuccessDelegate = FCancelMatchmakingTicketDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Creates a multiplayer server build with a custom container.
         * Creates a multiplayer server build with a custom container and returns information about the build creation request.
         */
        bool CreateBuildWithCustomContainer(MultiplayerModels::FCreateBuildWithCustomContainerRequest& request, const FCreateBuildWithCustomContainerDelegate& SuccessDelegate = FCreateBuildWithCustomContainerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Creates a multiplayer server build with a managed container.
         * Creates a multiplayer server build with a managed container and returns information about the build creation request.
         */
        bool CreateBuildWithManagedContainer(MultiplayerModels::FCreateBuildWithManagedContainerRequest& request, const FCreateBuildWithManagedContainerDelegate& SuccessDelegate = FCreateBuildWithManagedContainerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Create a matchmaking ticket as a client.
         * The client specifies the creator's attributes and optionally a list of other users to match with.
         */
        bool CreateMatchmakingTicket(MultiplayerModels::FCreateMatchmakingTicketRequest& request, const FCreateMatchmakingTicketDelegate& SuccessDelegate = FCreateMatchmakingTicketDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Creates a remote user to log on to a VM for a multiplayer server build.
         * Creates a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential information necessary to log on.
         */
        bool CreateRemoteUser(MultiplayerModels::FCreateRemoteUserRequest& request, const FCreateRemoteUserDelegate& SuccessDelegate = FCreateRemoteUserDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Create a matchmaking ticket as a server. The matchmaking service automatically starts matching the ticket against other
         * matchmaking tickets.
         * The server specifies all the members and their attributes.
         */
        bool CreateServerMatchmakingTicket(MultiplayerModels::FCreateServerMatchmakingTicketRequest& request, const FCreateServerMatchmakingTicketDelegate& SuccessDelegate = FCreateServerMatchmakingTicketDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Deletes a multiplayer server game asset for a title.
         * Deletes a multiplayer server game asset for a title.
         */
        bool DeleteAsset(MultiplayerModels::FDeleteAssetRequest& request, const FDeleteAssetDelegate& SuccessDelegate = FDeleteAssetDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Deletes a multiplayer server build.
         * Deletes a multiplayer server build.
         */
        bool DeleteBuild(MultiplayerModels::FDeleteBuildRequest& request, const FDeleteBuildDelegate& SuccessDelegate = FDeleteBuildDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Deletes a multiplayer server game certificate.
         * Deletes a multiplayer server game certificate.
         */
        bool DeleteCertificate(MultiplayerModels::FDeleteCertificateRequest& request, const FDeleteCertificateDelegate& SuccessDelegate = FDeleteCertificateDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Deletes a remote user to log on to a VM for a multiplayer server build.
         * Deletes a remote user to log on to a VM for a multiplayer server build in a specific region. Returns user credential information necessary to log on.
         */
        bool DeleteRemoteUser(MultiplayerModels::FDeleteRemoteUserRequest& request, const FDeleteRemoteUserDelegate& SuccessDelegate = FDeleteRemoteUserDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Enables the multiplayer server feature for a title.
         * Enables the multiplayer server feature for a title and returns the enabled status. The enabled status can be Initializing, Enabled, and Disabled. It can up to 20 minutes or more for the title to be enabled for the feature. On average, it can take up to 20 minutes for the title to be enabled for the feature.
         */

        bool EnableMultiplayerServersForTitle(const FEnableMultiplayerServersForTitleDelegate& SuccessDelegate = FEnableMultiplayerServersForTitleDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Enables the multiplayer server feature for a title.
         * Enables the multiplayer server feature for a title and returns the enabled status. The enabled status can be Initializing, Enabled, and Disabled. It can up to 20 minutes or more for the title to be enabled for the feature. On average, it can take up to 20 minutes for the title to be enabled for the feature.
         */
        bool EnableMultiplayerServersForTitle(MultiplayerModels::FEnableMultiplayerServersForTitleRequest& request, const FEnableMultiplayerServersForTitleDelegate& SuccessDelegate = FEnableMultiplayerServersForTitleDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the URL to upload assets to.
         * Gets the URL to upload assets to.
         */
        bool GetAssetUploadUrl(MultiplayerModels::FGetAssetUploadUrlRequest& request, const FGetAssetUploadUrlDelegate& SuccessDelegate = FGetAssetUploadUrlDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets a multiplayer server build.
         * Returns the details about a multiplayer server build.
         */
        bool GetBuild(MultiplayerModels::FGetBuildRequest& request, const FGetBuildDelegate& SuccessDelegate = FGetBuildDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the credentials to the container registry.
         * Gets credentials to the container registry where game developers can upload custom container images to before creating a new build.
         */

        bool GetContainerRegistryCredentials(const FGetContainerRegistryCredentialsDelegate& SuccessDelegate = FGetContainerRegistryCredentialsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the credentials to the container registry.
         * Gets credentials to the container registry where game developers can upload custom container images to before creating a new build.
         */
        bool GetContainerRegistryCredentials(MultiplayerModels::FGetContainerRegistryCredentialsRequest& request, const FGetContainerRegistryCredentialsDelegate& SuccessDelegate = FGetContainerRegistryCredentialsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Get a match.
         * When matchmaking has successfully matched together a collection of tickets, it produces a 'match' with an Id. The match contains all of the players that were matched together, and their team assigments. Only servers and ticket members can get the match.
         */
        bool GetMatch(MultiplayerModels::FGetMatchRequest& request, const FGetMatchDelegate& SuccessDelegate = FGetMatchDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Get a matchmaking ticket by ticket Id.
         * The ticket includes the invited players, their attributes if they have joined, the ticket status, the match Id when applicable, etc. Only servers, the ticket creator and the invited players can get the ticket.
         */
        bool GetMatchmakingTicket(MultiplayerModels::FGetMatchmakingTicketRequest& request, const FGetMatchmakingTicketDelegate& SuccessDelegate = FGetMatchmakingTicketDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets multiplayer server session details for a build.
         * Gets multiplayer server session details for a build in a specific region.
         */
        bool GetMultiplayerServerDetails(MultiplayerModels::FGetMultiplayerServerDetailsRequest& request, const FGetMultiplayerServerDetailsDelegate& SuccessDelegate = FGetMultiplayerServerDetailsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Get the statistics for a queue.
         * Returns the matchmaking statistics for a queue. These include the number of players matching and the statistics related to the time to match statistics in seconds (average and percentiles). Statistics are refreshed once every 5 minutes. Servers can access all statistics no matter what the ClientStatisticsVisibility is configured to. Clients can access statistics according to the ClientStatisticsVisibility. Client requests are forbidden if all visibility fields are false.
         */
        bool GetQueueStatistics(MultiplayerModels::FGetQueueStatisticsRequest& request, const FGetQueueStatisticsDelegate& SuccessDelegate = FGetQueueStatisticsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets a remote login endpoint to a VM that is hosting a multiplayer server build.
         * Gets a remote login endpoint to a VM that is hosting a multiplayer server build in a specific region.
         */
        bool GetRemoteLoginEndpoint(MultiplayerModels::FGetRemoteLoginEndpointRequest& request, const FGetRemoteLoginEndpointDelegate& SuccessDelegate = FGetRemoteLoginEndpointDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the status of whether a title is enabled for the multiplayer server feature.
         * Gets the status of whether a title is enabled for the multiplayer server feature. The enabled status can be Initializing, Enabled, and Disabled.
         */

        bool GetTitleEnabledForMultiplayerServersStatus(const FGetTitleEnabledForMultiplayerServersStatusDelegate& SuccessDelegate = FGetTitleEnabledForMultiplayerServersStatusDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the status of whether a title is enabled for the multiplayer server feature.
         * Gets the status of whether a title is enabled for the multiplayer server feature. The enabled status can be Initializing, Enabled, and Disabled.
         */
        bool GetTitleEnabledForMultiplayerServersStatus(MultiplayerModels::FGetTitleEnabledForMultiplayerServersStatusRequest& request, const FGetTitleEnabledForMultiplayerServersStatusDelegate& SuccessDelegate = FGetTitleEnabledForMultiplayerServersStatusDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the quotas for a title in relation to multiplayer servers.
         * Gets the quotas for a title in relation to multiplayer servers.
         */

        bool GetTitleMultiplayerServersQuotas(const FGetTitleMultiplayerServersQuotasDelegate& SuccessDelegate = FGetTitleMultiplayerServersQuotasDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Gets the quotas for a title in relation to multiplayer servers.
         * Gets the quotas for a title in relation to multiplayer servers.
         */
        bool GetTitleMultiplayerServersQuotas(MultiplayerModels::FGetTitleMultiplayerServersQuotasRequest& request, const FGetTitleMultiplayerServersQuotasDelegate& SuccessDelegate = FGetTitleMultiplayerServersQuotasDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Join a matchmaking ticket.
         * Add the player to a matchmaking ticket and specify all of its matchmaking attributes. Players can join a ticket if and only if their EntityKeys are already listed in the ticket's Members list. The matchmaking service automatically starts matching the ticket against other matchmaking tickets once all players have joined the ticket. It is not possible to join a ticket once it has started matching.
         */
        bool JoinMatchmakingTicket(MultiplayerModels::FJoinMatchmakingTicketRequest& request, const FJoinMatchmakingTicketDelegate& SuccessDelegate = FJoinMatchmakingTicketDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists archived multiplayer server sessions for a build.
         * Returns a list of archived multiplayer servers for a build in a specific region.
         */
        bool ListArchivedMultiplayerServers(MultiplayerModels::FListMultiplayerServersRequest& request, const FListArchivedMultiplayerServersDelegate& SuccessDelegate = FListArchivedMultiplayerServersDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists multiplayer server game assets for a title.
         * Returns a list of multiplayer server game asset summaries for a title.
         */
        bool ListAssetSummaries(MultiplayerModels::FListAssetSummariesRequest& request, const FListAssetSummariesDelegate& SuccessDelegate = FListAssetSummariesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists summarized details of all multiplayer server builds for a title.
         * Returns a list of summarized details of all multiplayer server builds for a title.
         */
        bool ListBuildSummaries(MultiplayerModels::FListBuildSummariesRequest& request, const FListBuildSummariesDelegate& SuccessDelegate = FListBuildSummariesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists multiplayer server game certificates for a title.
         * Returns a list of multiplayer server game certificates for a title.
         */
        bool ListCertificateSummaries(MultiplayerModels::FListCertificateSummariesRequest& request, const FListCertificateSummariesDelegate& SuccessDelegate = FListCertificateSummariesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists custom container images for a title.
         * Returns a list of the container images that have been uploaded to the container registry for a title.
         */
        bool ListContainerImages(MultiplayerModels::FListContainerImagesRequest& request, const FListContainerImagesDelegate& SuccessDelegate = FListContainerImagesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists the tags for a custom container image.
         * Returns a list of the tags for a particular container image that exists in the container registry for a title.
         */
        bool ListContainerImageTags(MultiplayerModels::FListContainerImageTagsRequest& request, const FListContainerImageTagsDelegate& SuccessDelegate = FListContainerImageTagsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * List all matchmaking ticket Ids the user is a member of.
         * If the caller is a title, the EntityKey in the request is required. If the caller is a player, then it is optional. If it is provided it must match the caller's entity.
         */
        bool ListMatchmakingTicketsForPlayer(MultiplayerModels::FListMatchmakingTicketsForPlayerRequest& request, const FListMatchmakingTicketsForPlayerDelegate& SuccessDelegate = FListMatchmakingTicketsForPlayerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists multiplayer server sessions for a build.
         * Returns a list of multiplayer servers for a build in a specific region.
         */
        bool ListMultiplayerServers(MultiplayerModels::FListMultiplayerServersRequest& request, const FListMultiplayerServersDelegate& SuccessDelegate = FListMultiplayerServersDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists quality of service servers for party.
         * Returns a list of quality of service servers for party.
         */
        bool ListPartyQosServers(MultiplayerModels::FListPartyQosServersRequest& request, const FListPartyQosServersDelegate& SuccessDelegate = FListPartyQosServersDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists quality of service servers.
         * Returns a list of quality of service servers.
         */

        bool ListQosServers(const FListQosServersDelegate& SuccessDelegate = FListQosServersDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists quality of service servers.
         * Returns a list of quality of service servers.
         */
        bool ListQosServers(MultiplayerModels::FListQosServersRequest& request, const FListQosServersDelegate& SuccessDelegate = FListQosServersDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists quality of service servers.
         * Returns a list of quality of service servers for a title.
         */

        bool ListQosServersForTitle(const FListQosServersForTitleDelegate& SuccessDelegate = FListQosServersForTitleDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists quality of service servers.
         * Returns a list of quality of service servers for a title.
         */
        bool ListQosServersForTitle(MultiplayerModels::FListQosServersForTitleRequest& request, const FListQosServersForTitleDelegate& SuccessDelegate = FListQosServersForTitleDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Lists virtual machines for a title.
         * Returns a list of virtual machines for a title.
         */
        bool ListVirtualMachineSummaries(MultiplayerModels::FListVirtualMachineSummariesRequest& request, const FListVirtualMachineSummariesDelegate& SuccessDelegate = FListVirtualMachineSummariesDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Request a multiplayer server session. Accepts tokens for title and if game client accesss is enabled, allows game client
         * to request a server with player entity token.
         * Requests a multiplayer server session from a particular build in any of the given preferred regions.
         */
        bool RequestMultiplayerServer(MultiplayerModels::FRequestMultiplayerServerRequest& request, const FRequestMultiplayerServerDelegate& SuccessDelegate = FRequestMultiplayerServerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Rolls over the credentials to the container registry.
         * Gets new credentials to the container registry where game developers can upload custom container images to before creating a new build.
         */

        bool RolloverContainerRegistryCredentials(const FRolloverContainerRegistryCredentialsDelegate& SuccessDelegate = FRolloverContainerRegistryCredentialsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Rolls over the credentials to the container registry.
         * Gets new credentials to the container registry where game developers can upload custom container images to before creating a new build.
         */
        bool RolloverContainerRegistryCredentials(MultiplayerModels::FRolloverContainerRegistryCredentialsRequest& request, const FRolloverContainerRegistryCredentialsDelegate& SuccessDelegate = FRolloverContainerRegistryCredentialsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Shuts down a multiplayer server session.
         * Executes the shutdown callback from the GSDK and terminates the multiplayer server session. The callback in the GSDK will allow for graceful shutdown with a 15 minute timeoutIf graceful shutdown has not been completed before 15 minutes have elapsed, the multiplayer server session will be forcefully terminated on it's own.
         */
        bool ShutdownMultiplayerServer(MultiplayerModels::FShutdownMultiplayerServerRequest& request, const FShutdownMultiplayerServerDelegate& SuccessDelegate = FShutdownMultiplayerServerDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Updates a multiplayer server build's regions.
         * Updates a multiplayer server build's regions.
         */
        bool UpdateBuildRegions(MultiplayerModels::FUpdateBuildRegionsRequest& request, const FUpdateBuildRegionsDelegate& SuccessDelegate = FUpdateBuildRegionsDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());
        /**
         * Uploads a multiplayer server game certificate.
         * Uploads a multiplayer server game certificate.
         */
        bool UploadCertificate(MultiplayerModels::FUploadCertificateRequest& request, const FUploadCertificateDelegate& SuccessDelegate = FUploadCertificateDelegate(), const FPlayFabErrorDelegate& ErrorDelegate = FPlayFabErrorDelegate());

    private:
        // ------------ Generated result handlers
        void OnCancelAllMatchmakingTicketsForPlayerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCancelAllMatchmakingTicketsForPlayerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCancelMatchmakingTicketResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCancelMatchmakingTicketDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCreateBuildWithCustomContainerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateBuildWithCustomContainerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCreateBuildWithManagedContainerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateBuildWithManagedContainerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCreateMatchmakingTicketResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateMatchmakingTicketDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCreateRemoteUserResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateRemoteUserDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnCreateServerMatchmakingTicketResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FCreateServerMatchmakingTicketDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnDeleteAssetResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteAssetDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnDeleteBuildResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteBuildDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnDeleteCertificateResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteCertificateDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnDeleteRemoteUserResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FDeleteRemoteUserDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnEnableMultiplayerServersForTitleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FEnableMultiplayerServersForTitleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetAssetUploadUrlResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetAssetUploadUrlDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetBuildResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetBuildDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetContainerRegistryCredentialsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetContainerRegistryCredentialsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetMatchResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetMatchDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetMatchmakingTicketResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetMatchmakingTicketDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetMultiplayerServerDetailsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetMultiplayerServerDetailsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetQueueStatisticsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetQueueStatisticsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetRemoteLoginEndpointResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetRemoteLoginEndpointDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetTitleEnabledForMultiplayerServersStatusResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTitleEnabledForMultiplayerServersStatusDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnGetTitleMultiplayerServersQuotasResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FGetTitleMultiplayerServersQuotasDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnJoinMatchmakingTicketResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FJoinMatchmakingTicketDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListArchivedMultiplayerServersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListArchivedMultiplayerServersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListAssetSummariesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListAssetSummariesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListBuildSummariesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListBuildSummariesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListCertificateSummariesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListCertificateSummariesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListContainerImagesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListContainerImagesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListContainerImageTagsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListContainerImageTagsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListMatchmakingTicketsForPlayerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListMatchmakingTicketsForPlayerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListMultiplayerServersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListMultiplayerServersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListPartyQosServersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListPartyQosServersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListQosServersResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListQosServersDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListQosServersForTitleResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListQosServersForTitleDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnListVirtualMachineSummariesResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FListVirtualMachineSummariesDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnRequestMultiplayerServerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRequestMultiplayerServerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnRolloverContainerRegistryCredentialsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FRolloverContainerRegistryCredentialsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnShutdownMultiplayerServerResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FShutdownMultiplayerServerDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnUpdateBuildRegionsResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUpdateBuildRegionsDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);
        void OnUploadCertificateResult(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUploadCertificateDelegate SuccessDelegate, FPlayFabErrorDelegate ErrorDelegate);

    };
};
