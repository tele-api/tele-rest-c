# message_entity_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **telegram_bot_api_message_entity_TYPE_e** | Type of the entity. Currently, can be “mention” (&#x60;@username&#x60;), “hashtag” (&#x60;#hashtag&#x60; or &#x60;#hashtag@chatusername&#x60;), “cashtag” (&#x60;$USD&#x60; or &#x60;$USD@chatusername&#x60;), “bot\\_command” (&#x60;/start@jobs_bot&#x60;), “url” (&#x60;https://telegram.org&#x60;), “email” (&#x60;do-not-reply@telegram.org&#x60;), “phone\\_number” (&#x60;+1-212-555-0123&#x60;), “bold” (**bold text**), “italic” (*italic text*), “underline” (underlined text), “strikethrough” (strikethrough text), “spoiler” (spoiler message), “blockquote” (block quotation), “expandable\\_blockquote” (collapsed-by-default block quotation), “code” (monowidth string), “pre” (monowidth block), “text\\_link” (for clickable text URLs), “text\\_mention” (for users [without usernames](https://telegram.org/blog/edit#new-mentions)), “custom\\_emoji” (for inline custom emoji stickers) | 
**offset** | **int** | Offset in [UTF-16 code units](https://core.telegram.org/api/entities#entity-length) to the start of the entity | 
**length** | **int** | Length of the entity in [UTF-16 code units](https://core.telegram.org/api/entities#entity-length) | 
**url** | **char \*** | *Optional*. For “text\\_link” only, URL that will be opened after user taps on the text | [optional] 
**user** | [**user_t**](user.md) \* |  | [optional] 
**language** | **char \*** | *Optional*. For “pre” only, the programming language of the entity text | [optional] 
**custom_emoji_id** | **char \*** | *Optional*. For “custom\\_emoji” only, unique identifier of the custom emoji. Use [getCustomEmojiStickers](https://core.telegram.org/bots/api/#getcustomemojistickers) to get full information about the sticker | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


