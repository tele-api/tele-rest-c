# _forward_messages_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**_send_message_post_request_chat_id_t**](_send_message_post_request_chat_id.md) \* |  | 
**from_chat_id** | [**_forward_messages_post_request_from_chat_id_t**](_forward_messages_post_request_from_chat_id.md) \* |  | 
**message_ids** | **list_t \*** | A JSON-serialized list of 1-100 identifiers of messages in the chat *from\\_chat\\_id* to forward. The identifiers must be specified in a strictly increasing order. | 
**message_thread_id** | **int** | Unique identifier for the target message thread (topic) of the forum; for forum supergroups only | [optional] 
**disable_notification** | **int** | Sends the messages [silently](https://telegram.org/blog/channels-2-0#silent-messages). Users will receive a notification with no sound. | [optional] 
**protect_content** | **int** | Protects the contents of the forwarded messages from forwarding and saving | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


