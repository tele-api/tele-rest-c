# post_send_venue_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_send_message_request_chat_id_t**](post_send_message_request_chat_id.md) \* |  | 
**latitude** | **double** | Latitude of the venue | 
**longitude** | **double** | Longitude of the venue | 
**title** | **char \*** | Name of the venue | 
**address** | **char \*** | Address of the venue | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message will be sent | [optional] 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**foursquare_id** | **char \*** | Foursquare identifier of the venue | [optional] 
**foursquare_type** | **char \*** | Foursquare type of the venue, if known. (For example, “arts\\_entertainment/default”, “arts\\_entertainment/aquarium” or “food/icecream”.) | [optional] 
**google_place_id** | **char \*** | Google Places identifier of the venue | [optional] 
**google_place_type** | **char \*** | Google Places type of the venue. (See [supported types](https://developers.google.com/places/web-service/supported_types).) | [optional] 
**disable_notification** | **int** | Sends the message [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the sent message from forwarding and saving | [optional] 
**allow_paid_broadcast** | **int** | Pass *True* to allow up to 1000 messages per second, ignoring [broadcasting limits](https://core.telegram.org/bots/faq#how-can-i-message-all-of-my-bot-39s-subscribers-at-once) for a fee of 0.1 Telegram Stars per message. The relevant Stars will be withdrawn from the bot&#39;s balance | [optional] 
**message_effect_id** | **char \*** | Unique identifier of the message effect to be added to the message; for private chats only | [optional] 
**reply_parameters** | [**reply_parameters_t**](reply_parameters.md) \* |  | [optional] 
**reply_markup** | [**post_send_message_request_reply_markup_t**](post_send_message_request_reply_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


