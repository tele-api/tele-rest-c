# inline_query_result_video_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *video* | [default to 'video']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**video_url** | **char \*** | A valid URL for the embedded video player or video file | 
**mime_type** | **telegram_bot_api_inline_query_result_video_MIMETYPE_e** | MIME type of the content of the video URL, “text/html” or “video/mp4” | 
**thumbnail_url** | **char \*** | URL of the thumbnail (JPEG only) for the video | 
**title** | **char \*** | Title for the result | 
**caption** | **char \*** | *Optional*. Caption of the video to be sent, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the video caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | *Optional*. Pass *True*, if the caption must be shown above the message media | [optional] 
**video_width** | **int** | *Optional*. Video width | [optional] 
**video_height** | **int** | *Optional*. Video height | [optional] 
**video_duration** | **int** | *Optional*. Video duration in seconds | [optional] 
**description** | **char \*** | *Optional*. Short description of the result | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


