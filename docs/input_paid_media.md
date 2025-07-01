# input_paid_media_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the media, must be *video* | [default to 'video']
**media** | **char \*** | File to send. Pass a file\\_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://\\&lt;file\\_attach\\_name\\&gt;” to upload a new one using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt; name. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files) | 
**thumbnail** | **char \*** | *Optional*. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. The thumbnail should be in JPEG format and less than 200 kB in size. A thumbnail&#39;s width and height should not exceed 320. Ignored if the file is not uploaded using multipart/form-data. Thumbnails can&#39;t be reused and can be only uploaded as a new file, so you can pass “attach://\\&lt;file\\_attach\\_name\\&gt;” if the thumbnail was uploaded using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt;. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files) | [optional] 
**cover** | **char \*** | *Optional*. Cover for the video in the message. Pass a file\\_id to send a file that exists on the Telegram servers (recommended), pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://\\&lt;file\\_attach\\_name\\&gt;” to upload a new one using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt; name. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files) | [optional] 
**start_timestamp** | **int** | *Optional*. Start timestamp for the video in the message | [optional] 
**width** | **int** | *Optional*. Video width | [optional] 
**height** | **int** | *Optional*. Video height | [optional] 
**duration** | **int** | *Optional*. Video duration in seconds | [optional] 
**supports_streaming** | **int** | *Optional*. Pass *True* if the uploaded video is suitable for streaming | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


