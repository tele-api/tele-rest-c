# inline_query_result_venue_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *venue* | [default to 'venue']
**id** | **char \*** | Unique identifier for this result, 1-64 Bytes | 
**latitude** | **double** | Latitude of the venue location in degrees | 
**longitude** | **double** | Longitude of the venue location in degrees | 
**title** | **char \*** | Title of the venue | 
**address** | **char \*** | Address of the venue | 
**foursquare_id** | **char \*** | *Optional*. Foursquare identifier of the venue if known | [optional] 
**foursquare_type** | **char \*** | *Optional*. Foursquare type of the venue, if known. (For example, “arts\\_entertainment/default”, “arts\\_entertainment/aquarium” or “food/icecream”.) | [optional] 
**google_place_id** | **char \*** | *Optional*. Google Places identifier of the venue | [optional] 
**google_place_type** | **char \*** | *Optional*. Google Places type of the venue. (See [supported types](https://developers.google.com/places/web-service/supported_types).) | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 
**thumbnail_url** | **char \*** | *Optional*. Url of the thumbnail for the result | [optional] 
**thumbnail_width** | **int** | *Optional*. Thumbnail width | [optional] 
**thumbnail_height** | **int** | *Optional*. Thumbnail height | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


