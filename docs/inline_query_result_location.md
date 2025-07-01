# inline_query_result_location_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *location* | [default to 'location']
**id** | **char \*** | Unique identifier for this result, 1-64 Bytes | 
**latitude** | **double** | Location latitude in degrees | 
**longitude** | **double** | Location longitude in degrees | 
**title** | **char \*** | Location title | 
**horizontal_accuracy** | **double** | *Optional*. The radius of uncertainty for the location, measured in meters; 0-1500 | [optional] 
**live_period** | **int** | *Optional*. Period in seconds during which the location can be updated, should be between 60 and 86400, or 0x7FFFFFFF for live locations that can be edited indefinitely. | [optional] 
**heading** | **int** | *Optional*. For live locations, a direction in which the user is moving, in degrees. Must be between 1 and 360 if specified. | [optional] 
**proximity_alert_radius** | **int** | *Optional*. For live locations, a maximum distance for proximity alerts about approaching another chat member, in meters. Must be between 1 and 100000 if specified. | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 
**thumbnail_url** | **char \*** | *Optional*. Url of the thumbnail for the result | [optional] 
**thumbnail_width** | **int** | *Optional*. Thumbnail width | [optional] 
**thumbnail_height** | **int** | *Optional*. Thumbnail height | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


