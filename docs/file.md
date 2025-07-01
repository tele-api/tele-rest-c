# file_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**file_id** | **char \*** | Identifier for this file, which can be used to download or reuse the file | 
**file_unique_id** | **char \*** | Unique identifier for this file, which is supposed to be the same over time and for different bots. Can&#39;t be used to download or reuse the file. | 
**file_size** | **int** | *Optional*. File size in bytes. It can be bigger than 2^31 and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a signed 64-bit integer or double-precision float type are safe for storing this value. | [optional] 
**file_path** | **char \*** | *Optional*. File path. Use &#x60;https://api.telegram.org/file/bot&lt;token&gt;/&lt;file_path&gt;&#x60; to get the file. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


