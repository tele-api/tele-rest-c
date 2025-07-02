# post_copy_message_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_send_message_request_chat_id_t**](post_send_message_request_chat_id.md) \* |  | 
**from_chat_id** | [**post_forward_message_request_from_chat_id_t**](post_forward_message_request_from_chat_id.md) \* |  | 
**message_id** | **int** | Message identifier in the chat specified in *from\\_chat\\_id* | 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**video_start_timestamp** | **int** | New start timestamp for the copied video in the message | [optional] 
**caption** | **char \*** | New caption for media, 0-1024 characters after entities parsing. If not specified, the original caption is kept | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the new caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the new caption, which can be specified instead of *parse\\_mode* | [optional] 
**show_caption_above_media** | **int** | Pass *True*, if the caption must be shown above the message media. Ignored if a new caption isn&#39;t specified. | [optional] 
**disable_notification** | **int** | Sends the message [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the sent message from forwarding and saving | [optional] 
**allow_paid_broadcast** | **int** | Pass *True* to allow up to 1000 messages per second, ignoring [broadcasting limits](https://core.telegram.org/bots/faq#how-can-i-message-all-of-my-bot-39s-subscribers-at-once) for a fee of 0.1 Telegram Stars per message. The relevant Stars will be withdrawn from the bot&#39;s balance | [optional] 
**reply_parameters** | [**reply_parameters_t**](reply_parameters.md) \* |  | [optional] 
**reply_markup** | [**post_send_message_request_reply_markup_t**](post_send_message_request_reply_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


