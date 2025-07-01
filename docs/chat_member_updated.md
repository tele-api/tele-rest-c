# chat_member_updated_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat** | [**chat_t**](chat.md) \* |  | 
**from** | [**user_t**](user.md) \* |  | 
**date** | **int** | Date the change was done in Unix time | 
**old_chat_member** | [**chat_member_t**](chat_member.md) \* |  | 
**new_chat_member** | [**chat_member_t**](chat_member.md) \* |  | 
**invite_link** | [**chat_invite_link_t**](chat_invite_link.md) \* |  | [optional] 
**via_join_request** | **int** | *Optional*. True, if the user joined the chat after sending a direct join request without using an invite link and being approved by an administrator | [optional] 
**via_chat_folder_invite_link** | **int** | *Optional*. True, if the user joined the chat via a chat folder invite link | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


