# edit_story_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection | 
**story_id** | **int** | Unique identifier of the story to edit | 
**content** | [**input_story_content_t**](input_story_content.md) \* |  | 
**caption** | **char \*** | Caption of the story, 0-2048 characters after entities parsing | [optional] 
**parse_mode** | **char \*** | Mode for parsing entities in the story caption. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. | [optional] 
**caption_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the caption, which can be specified instead of *parse\\_mode* | [optional] 
**areas** | [**list_t**](story_area.md) \* | A JSON-serialized list of clickable areas to be shown on the story | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


