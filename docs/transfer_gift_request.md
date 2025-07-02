# transfer_gift_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection | 
**owned_gift_id** | **char \*** | Unique identifier of the regular gift that should be transferred | 
**new_owner_chat_id** | **int** | Unique identifier of the chat which will own the gift. The chat must be active in the last 24 hours. | 
**star_count** | **int** | The amount of Telegram Stars that will be paid for the transfer from the business account balance. If positive, then the *can\\_transfer\\_stars* business bot right is required. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


