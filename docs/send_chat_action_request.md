# send_chat_action_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**send_message_request_chat_id_t**](send_message_request_chat_id.md) \* |  | 
**action** | **telegram_bot_api_send_chat_action_request_ACTION_e** | Type of action to broadcast. Choose one, depending on what the user is about to receive: *typing* for [text messages](https://core.telegram.org/bots/api/#sendmessage), *upload\\_photo* for [photos](https://core.telegram.org/bots/api/#sendphoto), *record\\_video* or *upload\\_video* for [videos](https://core.telegram.org/bots/api/#sendvideo), *record\\_voice* or *upload\\_voice* for [voice notes](https://core.telegram.org/bots/api/#sendvoice), *upload\\_document* for [general files](https://core.telegram.org/bots/api/#senddocument), *choose\\_sticker* for [stickers](https://core.telegram.org/bots/api/#sendsticker), *find\\_location* for [location data](https://core.telegram.org/bots/api/#sendlocation), *record\\_video\\_note* or *upload\\_video\\_note* for [video notes](https://core.telegram.org/bots/api/#sendvideonote). | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the action will be sent | [optional] 
**message_thread_id** | **int** | Unique identifier for the target message thread; for supergroups only | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


