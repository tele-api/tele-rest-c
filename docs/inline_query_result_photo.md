# inline_query_result_photo_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *photo* | [default to 'photo']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**photo_url** | **char \*** | A valid URL of the photo. Photo must be in **JPEG** format. Photo size must not exceed 5MB | 
**thumbnail_url** | **char \*** | URL of the thumbnail for the photo | 
**photo_width** | **int** | *Optional*. Width of the photo | [optional] 
**photo_height** | **int** | *Optional*. Height of the photo | [optional] 
**title** | **char \*** | *Optional*. Title for the result | [optional] 
**description** | **char \*** | *Optional*. Short description of the result | [optional] 
**caption** | **char \*** | *Optional*. Caption of the photo to be sent, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the photo caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | *Optional*. Pass *True*, if the caption must be shown above the message media | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


