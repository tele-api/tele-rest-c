# create_chat_invite_link_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**send_message_request_chat_id_t**](send_message_request_chat_id.md) \* |  | 
**name** | **char \*** | Invite link name; 0-32 characters | [optional] 
**expire_date** | **int** | Point in time (Unix timestamp) when the link will expire | [optional] 
**member_limit** | **int** | The maximum number of users that can be members of the chat simultaneously after joining the chat via this invite link; 1-99999 | [optional] 
**creates_join_request** | **int** | *True*, if users joining the chat via the link need to be approved by chat administrators. If *True*, *member\\_limit* can&#39;t be specified | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


