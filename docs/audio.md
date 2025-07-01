# audio_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**file_id** | **char \*** | Identifier for this file, which can be used to download or reuse the file | 
**file_unique_id** | **char \*** | Unique identifier for this file, which is supposed to be the same over time and for different bots. Can&#39;t be used to download or reuse the file. | 
**duration** | **int** | Duration of the audio in seconds as defined by the sender | 
**performer** | **char \*** | *Optional*. Performer of the audio as defined by the sender or by audio tags | [optional] 
**title** | **char \*** | *Optional*. Title of the audio as defined by the sender or by audio tags | [optional] 
**file_name** | **char \*** | *Optional*. Original filename as defined by the sender | [optional] 
**mime_type** | **char \*** | *Optional*. MIME type of the file as defined by the sender | [optional] 
**file_size** | **int** | *Optional*. File size in bytes. It can be bigger than 2^31 and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a signed 64-bit integer or double-precision float type are safe for storing this value. | [optional] 
**thumbnail** | [**photo_size_t**](photo_size.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


