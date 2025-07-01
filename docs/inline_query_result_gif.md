# inline_query_result_gif_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *gif* | [default to 'gif']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**gif_url** | **char \*** | A valid URL for the GIF file | 
**thumbnail_url** | **char \*** | URL of the static (JPEG or GIF) or animated (MPEG4) thumbnail for the result | 
**gif_width** | **int** | *Optional*. Width of the GIF | [optional] 
**gif_height** | **int** | *Optional*. Height of the GIF | [optional] 
**gif_duration** | **int** | *Optional*. Duration of the GIF in seconds | [optional] 
**thumbnail_mime_type** | **telegram_bot_api_inline_query_result_gif_THUMBNAILMIMETYPE_e** | *Optional*. MIME type of the thumbnail, must be one of “image/jpeg”, “image/gif”, or “video/mp4”. Defaults to “image/jpeg” | [optional] [default to 'image/jpeg']
**title** | **char \*** | *Optional*. Title for the result | [optional] 
**caption** | **char \*** | *Optional*. Caption of the GIF file to be sent, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | *Optional*. Pass *True*, if the caption must be shown above the message media | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


