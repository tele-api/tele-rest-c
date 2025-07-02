# post_send_poll_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_send_message_request_chat_id_t**](post_send_message_request_chat_id.md) \* |  | 
**question** | **char \*** | Poll question, 1-300 characters | 
**options** | [**list_t**](input_poll_option.md) \* | A JSON-serialized list of 2-10 answer options | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message will be sent | [optional] 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**question_parse_mode** | **char \*** | Mode for parsing entities in the question. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. Currently, only custom emoji entities are allowed | [optional] 
**question_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the poll question. It can be specified instead of *question\\_parse\\_mode* | [optional] 
**is_anonymous** | **int** | *True*, if the poll needs to be anonymous, defaults to *True* | [optional] 
**type** | **telegram_bot_api_post_send_poll_request_TYPE_e** | Poll type, “quiz” or “regular”, defaults to “regular” | [optional] 
**allows_multiple_answers** | **int** | *True*, if the poll allows multiple answers, ignored for polls in quiz mode, defaults to *False* | [optional] 
**correct_option_id** | **int** | 0-based identifier of the correct answer option, required for polls in quiz mode | [optional] 
**explanation** | **char \*** | Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-200 characters with at most 2 line feeds after entities parsing | [optional] 
**explanation_parse_mode** | **char \*** | Mode for parsing entities in the explanation. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**explanation_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the poll explanation. It can be specified instead of *explanation\\_parse\\_mode* | [optional] 
**open_period** | **int** | Amount of time in seconds the poll will be active after creation, 5-600. Can&#39;t be used together with *close\\_date*. | [optional] 
**close_date** | **int** | Point in time (Unix timestamp) when the poll will be automatically closed. Must be at least 5 and no more than 600 seconds in the future. Can&#39;t be used together with *open\\_period*. | [optional] 
**is_closed** | **int** | Pass *True* if the poll needs to be immediately closed. This can be useful for poll preview. | [optional] 
**disable_notification** | **int** | Sends the message [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the sent message from forwarding and saving | [optional] 
**allow_paid_broadcast** | **int** | Pass *True* to allow up to 1000 messages per second, ignoring [broadcasting limits](https://core.telegram.org/bots/faq#how-can-i-message-all-of-my-bot-39s-subscribers-at-once) for a fee of 0.1 Telegram Stars per message. The relevant Stars will be withdrawn from the bot&#39;s balance | [optional] 
**message_effect_id** | **char \*** | Unique identifier of the message effect to be added to the message; for private chats only | [optional] 
**reply_parameters** | [**reply_parameters_t**](reply_parameters.md) \* |  | [optional] 
**reply_markup** | [**post_send_message_request_reply_markup_t**](post_send_message_request_reply_markup.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


