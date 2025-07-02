# post_story_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection | 
**content** | [**input_story_content_t**](input_story_content.md) \* |  | 
**active_period** | **int** | Period after which the story is moved to the archive, in seconds; must be one of &#x60;6 * 3600&#x60;, &#x60;12 * 3600&#x60;, &#x60;86400&#x60;, or &#x60;2 * 86400&#x60; | 
**caption** | **char \*** | Caption of the story, 0-2048 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the story caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**areas** | [**list_t**](story_area.md) \* | A JSON-serialized list of clickable areas to be shown on the story | [optional] 
**post_to_chat_page** | **int** | Pass *True* to keep the story accessible after it expires | [optional] 
**protect_content** | **int** | Pass *True* if the content of the story must be protected from forwarding and screenshotting | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


