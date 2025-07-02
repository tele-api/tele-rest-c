# edit_message_caption_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message to be edited was sent | [optional] 
**chat_id** | [**edit_message_text_request_chat_id_t**](edit_message_text_request_chat_id.md) \* |  | [optional] 
**message_id** | **int** | Required if *inline\\_message\\_id* is not specified. Identifier of the message to edit | [optional] 
**inline_message_id** | **char \*** | Required if *chat\\_id* and *message\\_id* are not specified. Identifier of the inline message | [optional] 
**caption** | **char \*** | New caption of the message, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the message caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | Pass *True*, if the caption must be shown above the message media. Supported only for animation, photo and video messages. | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


