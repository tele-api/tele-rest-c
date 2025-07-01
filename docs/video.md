# video_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**file_id** | **char \*** | Identifier for this file, which can be used to download or reuse the file | 
**file_unique_id** | **char \*** | Unique identifier for this file, which is supposed to be the same over time and for different bots. Can&#39;t be used to download or reuse the file. | 
**width** | **int** | Video width as defined by the sender | 
**height** | **int** | Video height as defined by the sender | 
**duration** | **int** | Duration of the video in seconds as defined by the sender | 
**thumbnail** | [**photo_size_t**](photo_size.md) \* |  | [optional] 
**cover** | [**list_t**](photo_size.md) \* | *Optional*. Available sizes of the cover of the video in the message | [optional] 
**start_timestamp** | **int** | *Optional*. Timestamp in seconds from which the video will play in the message | [optional] 
**file_name** | **char \*** | *Optional*. Original filename as defined by the sender | [optional] 
**mime_type** | **char \*** | *Optional*. MIME type of the file as defined by the sender | [optional] 
**file_size** | **int** | *Optional*. File size in bytes. It can be bigger than 2^31 and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a signed 64-bit integer or double-precision float type are safe for storing this value. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


