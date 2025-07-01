# passport_element_error_data_field_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**source** | **char \*** | Error source, must be *data* | [default to 'data']
**type** | **telegram_bot_api_passport_element_error_data_field_TYPE_e** | The section of the user&#39;s Telegram Passport which has the error, one of “personal\\_details”, “passport”, “driver\\_license”, “identity\\_card”, “internal\\_passport”, “address” | 
**field_name** | **char \*** | Name of the data field which has the error | 
**data_hash** | **char \*** | Base64-encoded data hash | 
**message** | **char \*** | Error message | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


