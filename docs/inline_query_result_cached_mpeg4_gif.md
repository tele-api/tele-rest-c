# inline_query_result_cached_mpeg4_gif_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *mpeg4\\_gif* | [default to 'mpeg4_gif']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**mpeg4_file_id** | **char \*** | A valid file identifier for the MPEG4 file | 
**title** | **char \*** | *Optional*. Title for the result | [optional] 
**caption** | **char \*** | *Optional*. Caption of the MPEG-4 file to be sent, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | *Optional*. Pass *True*, if the caption must be shown above the message media | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


