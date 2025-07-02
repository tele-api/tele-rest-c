# post_copy_messages_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_send_message_request_chat_id_t**](post_send_message_request_chat_id.md) \* |  | 
**from_chat_id** | [**post_forward_messages_request_from_chat_id_t**](post_forward_messages_request_from_chat_id.md) \* |  | 
**message_ids** | **list_t \*** | A JSON-serialized list of 1-100 identifiers of messages in the chat *from\\_chat\\_id* to copy. The identifiers must be specified in a strictly increasing order. | 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**disable_notification** | **int** | Sends the messages [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the sent messages from forwarding and saving | [optional] 
**remove_caption** | **int** | Pass *True* to copy the messages without their captions | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


