# owned_gift_unique_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the gift, always “unique” | [default to 'unique']
**gift** | [**unique_gift_t**](unique_gift.md) \* |  | 
**send_date** | **int** | Date the gift was sent in Unix time | 
**owned_gift_id** | **char \*** | *Optional*. Unique identifier of the received gift for the bot; for gifts received on behalf of business accounts only | [optional] 
**sender_user** | [**user_t**](user.md) \* |  | [optional] 
**is_saved** | **int** | *Optional*. True, if the gift is displayed on the account&#39;s profile page; for gifts received on behalf of business accounts only | [optional] [default to true]
**can_be_transferred** | **int** | *Optional*. True, if the gift can be transferred to another owner; for gifts received on behalf of business accounts only | [optional] [default to true]
**transfer_star_count** | **int** | *Optional*. Number of Telegram Stars that must be paid to transfer the gift; omitted if the bot cannot transfer the gift | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


