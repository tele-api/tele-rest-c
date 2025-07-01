# input_story_content_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the content, must be *video* | [default to 'video']
**photo** | **char \*** | The photo to post as a story. The photo must be of the size 1080x1920 and must not exceed 10 MB. The photo can&#39;t be reused and can only be uploaded as a new file, so you can pass “attach://\\&lt;file\\_attach\\_name\\&gt;” if the photo was uploaded using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt;. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files) | 
**video** | **char \*** | The video to post as a story. The video must be of the size 720x1280, streamable, encoded with H.265 codec, with key frames added each second in the MPEG4 format, and must not exceed 30 MB. The video can&#39;t be reused and can only be uploaded as a new file, so you can pass “attach://\\&lt;file\\_attach\\_name\\&gt;” if the video was uploaded using multipart/form-data under \\&lt;file\\_attach\\_name\\&gt;. [More information on Sending Files »](https://core.telegram.org/bots/api/#sending-files) | 
**duration** | **double** | *Optional*. Precise duration of the video in seconds; 0-60 | [optional] 
**cover_frame_timestamp** | **double** | *Optional*. Timestamp in seconds of the frame that will be used as the static cover for the story. Defaults to 0.0. | [optional] 
**is_animation** | **int** | *Optional*. Pass *True* if the video has no sound | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


