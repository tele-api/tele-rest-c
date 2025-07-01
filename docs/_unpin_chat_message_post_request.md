# _unpin_chat_message_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**_send_message_post_request_chat_id_t**](_send_message_post_request_chat_id.md) \* |  | 
**business_connection_id** | **char \*** | Unique identifier of the business connection on behalf of which the message will be unpinned | [optional] 
**message_id** | **int** | Identifier of the message to unpin. Required if *business\\_connection\\_id* is specified. If not specified, the most recent pinned message (by sending date) will be unpinned. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


