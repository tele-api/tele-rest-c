# _stop_message_live_location_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message to be edited was sent | [optional] 
**chat_id** | [**_edit_message_text_post_request_chat_id_t**](_edit_message_text_post_request_chat_id.md) \* |  | [optional] 
**message_id** | **int** | Required if *inline\\_message\\_id* is not specified. Identifier of the message with live location to stop | [optional] 
**inline_message_id** | **char \*** | Required if *chat\\_id* and *message\\_id* are not specified. Identifier of the inline message | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


