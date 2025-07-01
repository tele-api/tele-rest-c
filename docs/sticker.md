# sticker_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**file_id** | **char \*** | Identifier for this file, which can be used to download or reuse the file | 
**file_unique_id** | **char \*** | Unique identifier for this file, which is supposed to be the same over time and for different bots. Can&#39;t be used to download or reuse the file. | 
**type** | **telegram_bot_api_sticker_TYPE_e** | Type of the sticker, currently one of “regular”, “mask”, “custom\\_emoji”. The type of the sticker is independent from its format, which is determined by the fields *is\\_animated* and *is\\_video*. | 
**width** | **int** | Sticker width | 
**height** | **int** | Sticker height | 
**is_animated** | **int** | *True*, if the sticker is [animated](https://telegram.org/blog/animated-stickers) | 
**is_video** | **int** | *True*, if the sticker is a [video sticker](https://telegram.org/blog/video-stickers-better-reactions) | 
**thumbnail** | [**photo_size_t**](photo_size.md) \* |  | [optional] 
**emoji** | **char \*** | *Optional*. Emoji associated with the sticker | [optional] 
**set_name** | **char \*** | *Optional*. Name of the sticker set to which the sticker belongs | [optional] 
**premium_animation** | [**binary_t*_t**](file.md) \* |  | [optional] 
**mask_position** | [**mask_position_t**](mask_position.md) \* |  | [optional] 
**custom_emoji_id** | **char \*** | *Optional*. For custom emoji stickers, unique identifier of the custom emoji | [optional] 
**needs_repainting** | **int** | *Optional*. *True*, if the sticker must be repainted to a text color in messages, the color of the Telegram Premium badge in emoji status, white color on chat photos, or another appropriate color in other places | [optional] [default to true]
**file_size** | **int** | *Optional*. File size in bytes | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


