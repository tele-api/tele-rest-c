# keyboard_button_request_chat_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**request_id** | **int** | Signed 32-bit identifier of the request, which will be received back in the [ChatShared](https://core.telegram.org/bots/api/#chatshared) object. Must be unique within the message | 
**chat_is_channel** | **int** | Pass *True* to request a channel chat, pass *False* to request a group or a supergroup chat. | 
**chat_is_forum** | **int** | *Optional*. Pass *True* to request a forum supergroup, pass *False* to request a non-forum chat. If not specified, no additional restrictions are applied. | [optional] 
**chat_has_username** | **int** | *Optional*. Pass *True* to request a supergroup or a channel with a username, pass *False* to request a chat without a username. If not specified, no additional restrictions are applied. | [optional] 
**chat_is_created** | **int** | *Optional*. Pass *True* to request a chat owned by the user. Otherwise, no additional restrictions are applied. | [optional] 
**user_administrator_rights** | [**chat_administrator_rights_t**](chat_administrator_rights.md) \* |  | [optional] 
**bot_administrator_rights** | [**chat_administrator_rights_t**](chat_administrator_rights.md) \* |  | [optional] 
**bot_is_member** | **int** | *Optional*. Pass *True* to request a chat with the bot as a member. Otherwise, no additional restrictions are applied. | [optional] 
**request_title** | **int** | *Optional*. Pass *True* to request the chat&#39;s title | [optional] 
**request_username** | **int** | *Optional*. Pass *True* to request the chat&#39;s username | [optional] 
**request_photo** | **int** | *Optional*. Pass *True* to request the chat&#39;s photo | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


