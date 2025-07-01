# owned_gift_regular_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the gift, always “regular” | [default to 'regular']
**gift** | [**gift_t**](gift.md) \* |  | 
**send_date** | **int** | Date the gift was sent in Unix time | 
**owned_gift_id** | **char \*** | *Optional*. Unique identifier of the gift for the bot; for gifts received on behalf of business accounts only | [optional] 
**sender_user** | [**user_t**](user.md) \* |  | [optional] 
**text** | **char \*** | *Optional*. Text of the message that was added to the gift | [optional] 
**entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities that appear in the text | [optional] 
**is_private** | **int** | *Optional*. True, if the sender and gift text are shown only to the gift receiver; otherwise, everyone will be able to see them | [optional] [default to true]
**is_saved** | **int** | *Optional*. True, if the gift is displayed on the account&#39;s profile page; for gifts received on behalf of business accounts only | [optional] [default to true]
**can_be_upgraded** | **int** | *Optional*. True, if the gift can be upgraded to a unique gift; for gifts received on behalf of business accounts only | [optional] [default to true]
**was_refunded** | **int** | *Optional*. True, if the gift was refunded and isn&#39;t available anymore | [optional] [default to true]
**convert_star_count** | **int** | *Optional*. Number of Telegram Stars that can be claimed by the receiver instead of the gift; omitted if the gift cannot be converted to Telegram Stars | [optional] 
**prepaid_upgrade_star_count** | **int** | *Optional*. Number of Telegram Stars that were paid by the sender for the ability to upgrade the gift | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


