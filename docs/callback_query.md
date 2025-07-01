# callback_query_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique identifier for this query | 
**from** | [**user_t**](user.md) \* |  | 
**chat_instance** | **char \*** | Global identifier, uniquely corresponding to the chat to which the message with the callback button was sent. Useful for high scores in [games](https://core.telegram.org/bots/api/#games). | 
**message** | [**maybe_inaccessible_message_t**](maybe_inaccessible_message.md) \* |  | [optional] 
**inline_message_id** | **char \*** | *Optional*. Identifier of the message sent via the bot in inline mode, that originated the query. | [optional] 
**data** | **char \*** | *Optional*. Data associated with the callback button. Be aware that the message originated the query can contain no callback buttons with this data. | [optional] 
**game_short_name** | **char \*** | *Optional*. Short name of a [Game](https://core.telegram.org/bots/api/#games) to be returned, serves as the unique identifier for the game | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


