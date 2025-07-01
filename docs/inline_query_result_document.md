# inline_query_result_document_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *document* | [default to 'document']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**title** | **char \*** | Title for the result | 
**document_url** | **char \*** | A valid URL for the file | 
**mime_type** | **telegram_bot_api_inline_query_result_document_MIMETYPE_e** | MIME type of the content of the file, either “application/pdf” or “application/zip” | 
**caption** | **char \*** | *Optional*. Caption of the document to be sent, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the document caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**description** | **char \*** | *Optional*. Short description of the result | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 
**thumbnail_url** | **char \*** | *Optional*. URL of the thumbnail (JPEG only) for the file | [optional] 
**thumbnail_width** | **int** | *Optional*. Thumbnail width | [optional] 
**thumbnail_height** | **int** | *Optional*. Thumbnail height | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


