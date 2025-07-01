# message_reaction_updated_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat** | [**chat_t**](chat.md) \* |  | 
**message_id** | **int** | Unique identifier of the message inside the chat | 
**date** | **int** | Date of the change in Unix time | 
**old_reaction** | [**list_t**](reaction_type.md) \* | Previous list of reaction types that were set by the user | 
**new_reaction** | [**list_t**](reaction_type.md) \* | New list of reaction types that have been set by the user | 
**user** | [**user_t**](user.md) \* |  | [optional] 
**actor_chat** | [**chat_t**](chat.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


