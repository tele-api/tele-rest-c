# edit_message_live_location_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**latitude** | **double** | Latitude of new location | 
**longitude** | **double** | Longitude of new location | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message to be edited was sent | [optional] 
**chat_id** | [**edit_message_text_request_chat_id_t**](edit_message_text_request_chat_id.md) \* |  | [optional] 
**message_id** | **int** | Required if *inline\\_message\\_id* is not specified. Identifier of the message to edit | [optional] 
**inline_message_id** | **char \*** | Required if *chat\\_id* and *message\\_id* are not specified. Identifier of the inline message | [optional] 
**live_period** | **int** | New period in seconds during which the location can be updated, starting from the message send date. If 0x7FFFFFFF is specified, then the location can be updated forever. Otherwise, the new value must not exceed the current *live\\_period* by more than a day, and the live location expiration date must remain within the next 90 days. If not specified, then *live\\_period* remains unchanged | [optional] 
**horizontal_accuracy** | **double** | The radius of uncertainty for the location, measured in meters; 0-1500 | [optional] 
**heading** | **int** | Direction in which the user is moving, in degrees. Must be between 1 and 360 if specified. | [optional] 
**proximity_alert_radius** | **int** | The maximum distance for proximity alerts about approaching another chat member, in meters. Must be between 1 and 100000 if specified. | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


