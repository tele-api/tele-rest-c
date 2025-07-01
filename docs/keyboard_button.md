# keyboard_button_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | **char \*** | Text of the button. If none of the optional fields are used, it will be sent as a message when the button is pressed | 
**request_users** | [**keyboard_button_request_users_t**](keyboard_button_request_users.md) \* |  | [optional] 
**request_chat** | [**keyboard_button_request_chat_t**](keyboard_button_request_chat.md) \* |  | [optional] 
**request_contact** | **int** | *Optional*. If *True*, the user&#39;s phone number will be sent as a contact when the button is pressed. Available in private chats only. | [optional] 
**request_location** | **int** | *Optional*. If *True*, the user&#39;s current location will be sent when the button is pressed. Available in private chats only. | [optional] 
**request_poll** | [**keyboard_button_poll_type_t**](keyboard_button_poll_type.md) \* |  | [optional] 
**web_app** | [**web_app_info_t**](web_app_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


