# post_create_forum_topic_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**post_restrict_chat_member_request_chat_id_t**](post_restrict_chat_member_request_chat_id.md) \* |  | 
**name** | **char \*** | Topic name, 1-128 characters | 
**icon_color** | **int** | Color of the topic icon in RGB format. Currently, must be one of 7322096 (0x6FB9F0), 16766590 (0xFFD67E), 13338331 (0xCB86DB), 9367192 (0x8EEE98), 16749490 (0xFF93B2), or 16478047 (0xFB6F5F) | [optional] 
**icon_custom_emoji_id** | **char \*** | Unique identifier of the custom emoji shown as the topic icon. Use [getForumTopicIconStickers](https://core.telegram.org/bots/api/#getforumtopiciconstickers) to get all allowed custom emoji identifiers. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


