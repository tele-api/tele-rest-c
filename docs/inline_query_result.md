# inline_query_result_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *voice* | [default to 'voice']
**id** | **char \*** | Unique identifier for this result, 1-64 bytes | 
**audio_file_id** | **char \*** | A valid file identifier for the audio file | 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | 
**title** | **char \*** | Recording title | 
**document_file_id** | **char \*** | A valid file identifier for the file | 
**gif_file_id** | **char \*** | A valid file identifier for the GIF file | 
**mpeg4_file_id** | **char \*** | A valid file identifier for the MPEG4 file | 
**photo_file_id** | **char \*** | A valid file identifier of the photo | 
**sticker_file_id** | **char \*** | A valid file identifier of the sticker | 
**video_file_id** | **char \*** | A valid file identifier for the video file | 
**voice_file_id** | **char \*** | A valid file identifier for the voice message | 
**thumbnail_url** | **char \*** | URL of the thumbnail (JPEG only) for the video | 
**audio_url** | **char \*** | A valid URL for the audio file | 
**phone_number** | **char \*** | Contact&#39;s phone number | 
**first_name** | **char \*** | Contact&#39;s first name | 
**game_short_name** | **char \*** | Short name of the game | 
**document_url** | **char \*** | A valid URL for the file | 
**mime_type** | **telegram_bot_api_inline_query_result_MIMETYPE_e** | MIME type of the content of the video URL, “text/html” or “video/mp4” | 
**gif_url** | **char \*** | A valid URL for the GIF file | 
**latitude** | **double** | Latitude of the venue location in degrees | 
**longitude** | **double** | Longitude of the venue location in degrees | 
**mpeg4_url** | **char \*** | A valid URL for the MPEG4 file | 
**photo_url** | **char \*** | A valid URL of the photo. Photo must be in **JPEG** format. Photo size must not exceed 5MB | 
**address** | **char \*** | Address of the venue | 
**video_url** | **char \*** | A valid URL for the embedded video player or video file | 
**voice_url** | **char \*** | A valid URL for the voice recording | 
**caption** | **char \*** | *Optional*. Caption, 0-1024 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the voice message caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | *Optional*. List of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**description** | **char \*** | *Optional*. Short description of the result | [optional] 
**show_caption_above_media** | **int** | *Optional*. Pass *True*, if the caption must be shown above the message media | [optional] 
**url** | **char \*** | *Optional*. URL of the result | [optional] 
**thumbnail_width** | **int** | *Optional*. Thumbnail width | [optional] 
**thumbnail_height** | **int** | *Optional*. Thumbnail height | [optional] 
**performer** | **char \*** | *Optional*. Performer | [optional] 
**audio_duration** | **int** | *Optional*. Audio duration in seconds | [optional] 
**last_name** | **char \*** | *Optional*. Contact&#39;s last name | [optional] 
**vcard** | **char \*** | *Optional*. Additional data about the contact in the form of a [vCard](https://en.wikipedia.org/wiki/VCard), 0-2048 bytes | [optional] 
**gif_width** | **int** | *Optional*. Width of the GIF | [optional] 
**gif_height** | **int** | *Optional*. Height of the GIF | [optional] 
**gif_duration** | **int** | *Optional*. Duration of the GIF in seconds | [optional] 
**thumbnail_mime_type** | **telegram_bot_api_inline_query_result_THUMBNAILMIMETYPE_e** | *Optional*. MIME type of the thumbnail, must be one of “image/jpeg”, “image/gif”, or “video/mp4”. Defaults to “image/jpeg” | [optional] [default to 'image/jpeg']
**horizontal_accuracy** | **double** | *Optional*. The radius of uncertainty for the location, measured in meters; 0-1500 | [optional] 
**live_period** | **int** | *Optional*. Period in seconds during which the location can be updated, should be between 60 and 86400, or 0x7FFFFFFF for live locations that can be edited indefinitely. | [optional] 
**heading** | **int** | *Optional*. For live locations, a direction in which the user is moving, in degrees. Must be between 1 and 360 if specified. | [optional] 
**proximity_alert_radius** | **int** | *Optional*. For live locations, a maximum distance for proximity alerts about approaching another chat member, in meters. Must be between 1 and 100000 if specified. | [optional] 
**mpeg4_width** | **int** | *Optional*. Video width | [optional] 
**mpeg4_height** | **int** | *Optional*. Video height | [optional] 
**mpeg4_duration** | **int** | *Optional*. Video duration in seconds | [optional] 
**photo_width** | **int** | *Optional*. Width of the photo | [optional] 
**photo_height** | **int** | *Optional*. Height of the photo | [optional] 
**foursquare_id** | **char \*** | *Optional*. Foursquare identifier of the venue if known | [optional] 
**foursquare_type** | **char \*** | *Optional*. Foursquare type of the venue, if known. (For example, “arts\\_entertainment/default”, “arts\\_entertainment/aquarium” or “food/icecream”.) | [optional] 
**google_place_id** | **char \*** | *Optional*. Google Places identifier of the venue | [optional] 
**google_place_type** | **char \*** | *Optional*. Google Places type of the venue. (See [supported types](https://developers.google.com/places/web-service/supported_types).) | [optional] 
**video_width** | **int** | *Optional*. Video width | [optional] 
**video_height** | **int** | *Optional*. Video height | [optional] 
**video_duration** | **int** | *Optional*. Video duration in seconds | [optional] 
**voice_duration** | **int** | *Optional*. Recording duration in seconds | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


