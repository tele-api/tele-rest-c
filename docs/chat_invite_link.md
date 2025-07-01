# chat_invite_link_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**invite_link** | **char \*** | The invite link. If the link was created by another chat administrator, then the second part of the link will be replaced with “…”. | 
**creator** | [**user_t**](user.md) \* |  | 
**creates_join_request** | **int** | *True*, if users joining the chat via the link need to be approved by chat administrators | 
**is_primary** | **int** | *True*, if the link is primary | 
**is_revoked** | **int** | *True*, if the link is revoked | 
**name** | **char \*** | *Optional*. Invite link name | [optional] 
**expire_date** | **int** | *Optional*. Point in time (Unix timestamp) when the link will expire or has been expired | [optional] 
**member_limit** | **int** | *Optional*. The maximum number of users that can be members of the chat simultaneously after joining the chat via this invite link; 1-99999 | [optional] 
**pending_join_request_count** | **int** | *Optional*. Number of pending join requests created using this link | [optional] 
**subscription_period** | **int** | *Optional*. The number of seconds the subscription will be active for before the next payment | [optional] 
**subscription_price** | **int** | *Optional*. The amount of Telegram Stars a user must pay initially and after each subsequent subscription period to be a member of the chat using the link | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


