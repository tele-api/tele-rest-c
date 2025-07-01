# chosen_inline_result_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**result_id** | **char \*** | The unique identifier for the result that was chosen | 
**from** | [**user_t**](user.md) \* |  | 
**query** | **char \*** | The query that was used to obtain the result | 
**location** | [**location_t**](location.md) \* |  | [optional] 
**inline_message_id** | **char \*** | *Optional*. Identifier of the sent inline message. Available only if there is an [inline keyboard](https://core.telegram.org/bots/api/#inlinekeyboardmarkup) attached to the message. Will be also received in [callback queries](https://core.telegram.org/bots/api/#callbackquery) and can be used to [edit](https://core.telegram.org/bots/api/#updating-messages) the message. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


