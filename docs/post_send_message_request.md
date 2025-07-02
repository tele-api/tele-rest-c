# post_send_message_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_send_message_request_chat_id_t**](post_send_message_request_chat_id.md) \* |  | 
**text** | **char \*** | Text of the message to be sent, 1-4096 characters after entities parsing | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message will be sent | [optional] 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the message text. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in message text, which can be specified instead of *parse\\_mode* | [optional] 
**link_preview_options** | [**link_preview_options_t**](link_preview_options.md) \* |  | [optional] 
**disable_notification** | **int** | Sends the message [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the sent message from forwarding and saving | [optional] 
**allow_paid_broadcast** | **int** | Pass *True* to allow up to 1000 messages per second, ignoring [broadcasting limits](https://core.telegram.org/bots/faq#how-can-i-message-all-of-my-bot-39s-subscribers-at-once) for a fee of 0.1 Telegram Stars per message. The relevant Stars will be withdrawn from the bot&#39;s balance | [optional] 
**message_effect_id** | **char \*** | Unique identifier of the message effect to be added to the message; for private chats only | [optional] 
**reply_parameters** | [**reply_parameters_t**](reply_parameters.md) \* |  | [optional] 
**reply_markup** | [**post_send_message_request_reply_markup_t**](post_send_message_request_reply_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


