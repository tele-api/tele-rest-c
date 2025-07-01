# business_connection_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique identifier of the business connection | 
**user** | [**user_t**](user.md) \* |  | 
**user_chat_id** | **int** | Identifier of a private chat with the user who created the business connection. This number may have more than 32 significant bits and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a 64-bit integer or double-precision float type are safe for storing this identifier. | 
**date** | **int** | Date the connection was established in Unix time | 
**is_enabled** | **int** | True, if the connection is active | 
**rights** | [**business_bot_rights_t**](business_bot_rights.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


