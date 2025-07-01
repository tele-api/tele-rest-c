# video_note_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**file_id** | **char \*** | Identifier for this file, which can be used to download or reuse the file | 
**file_unique_id** | **char \*** | Unique identifier for this file, which is supposed to be the same over time and for different bots. Can&#39;t be used to download or reuse the file. | 
**length** | **int** | Video width and height (diameter of the video message) as defined by the sender | 
**duration** | **int** | Duration of the video in seconds as defined by the sender | 
**thumbnail** | [**photo_size_t**](photo_size.md) \* |  | [optional] 
**file_size** | **int** | *Optional*. File size in bytes | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


