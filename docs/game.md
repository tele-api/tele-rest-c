# game_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**title** | **char \*** | Title of the game | 
**description** | **char \*** | Description of the game | 
**photo** | [**list_t**](photo_size.md) \* | Photo that will be displayed in the game message in chats. | 
**text** | **char \*** | *Optional*. Brief description of the game or high scores included in the game message. Can be automatically edited to include current high scores for the game when the bot calls [setGameScore](https://core.telegram.org/bots/api/#setgamescore), or manually edited using [editMessageText](https://core.telegram.org/bots/api/#editmessagetext). 0-4096 characters. | [optional] 
**text_entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities that appear in *text*, such as usernames, URLs, bot commands, etc. | [optional] 
**animation** | [**animation_t**](animation.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


