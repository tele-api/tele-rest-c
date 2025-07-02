# create_chat_subscription_invite_link_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**create_chat_subscription_invite_link_request_chat_id_t**](create_chat_subscription_invite_link_request_chat_id.md) \* |  | 
**subscription_period** | **int** | The number of seconds the subscription will be active for before the next payment. Currently, it must always be 2592000 (30 days). | 
**subscription_price** | **int** | The amount of Telegram Stars a user must pay initially and after each subsequent subscription period to be a member of the chat; 1-10000 | 
**name** | **char \*** | Invite link name; 0-32 characters | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


