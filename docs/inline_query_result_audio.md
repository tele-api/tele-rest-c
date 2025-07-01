# inline_query_result_audio_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *audio* | [default to 'audio']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**audio_url** | **char \*** | A valid URL for the audio file | 
**title** | **char \*** | Title | 
**caption** | **char \*** | *Optional*. Caption, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the audio caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**performer** | **char \*** | *Optional*. Performer | [optional] 
**audio_duration** | **int** | *Optional*. Audio duration in seconds | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


