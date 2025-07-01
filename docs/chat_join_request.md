# chat_join_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat** | [**chat_t**](chat.md) \* |  | 
**from** | [**user_t**](user.md) \* |  | 
**user_chat_id** | **int** | Identifier of a private chat with the user who sent the join request. This number may have more than 32 significant bits and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a 64-bit integer or double-precision float type are safe for storing this identifier. The bot can use this identifier for 5 minutes to send messages until the join request is processed, assuming no other administrator contacted the user. | 
**date** | **int** | Date the request was sent in Unix time | 
**bio** | **char \*** | *Optional*. Bio of the user. | [optional] 
**invite_link** | [**chat_invite_link_t**](chat_invite_link.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


