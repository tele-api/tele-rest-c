# edit_message_text_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | **char \*** | New text of the message, 1-4096 characters after entities parsing | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message to be edited was sent | [optional] 
**chat_id** | [**edit_message_text_request_chat_id_t**](edit_message_text_request_chat_id.md) \* |  | [optional] 
**message_id** | **int** | Required if *inline\\_message\\_id* is not specified. Identifier of the message to edit | [optional] 
**inline_message_id** | **char \*** | Required if *chat\\_id* and *message\\_id* are not specified. Identifier of the inline message | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the message text. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in message text, which can be specified instead of *parse\\_mode* | [optional] 
**link_preview_options** | [**link_preview_options_t**](link_preview_options.md) \* |  | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


