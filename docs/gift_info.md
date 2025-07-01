# gift_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gift** | [**gift_t**](gift.md) \* |  | 
**owned_gift_id** | **char \*** | *Optional*. Unique identifier of the received gift for the bot; only present for gifts received on behalf of business accounts | [optional] 
**convert_star_count** | **int** | *Optional*. Number of Telegram Stars that can be claimed by the receiver by converting the gift; omitted if conversion to Telegram Stars is impossible | [optional] 
**prepaid_upgrade_star_count** | **int** | *Optional*. Number of Telegram Stars that were prepaid by the sender for the ability to upgrade the gift | [optional] 
**can_be_upgraded** | **int** | *Optional*. True, if the gift can be upgraded to a unique gift | [optional] [default to true]
**text** | **char \*** | *Optional*. Text of the message that was added to the gift | [optional] 
**entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities that appear in the text | [optional] 
**is_private** | **int** | *Optional*. True, if the sender and gift text are shown only to the gift receiver; otherwise, everyone will be able to see them | [optional] [default to true]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


