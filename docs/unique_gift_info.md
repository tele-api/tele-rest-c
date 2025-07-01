# unique_gift_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gift** | [**unique_gift_t**](unique_gift.md) \* |  | 
**origin** | **telegram_bot_api_unique_gift_info_ORIGIN_e** | Origin of the gift. Currently, either “upgrade” or “transfer” | 
**owned_gift_id** | **char \*** | *Optional*. Unique identifier of the received gift for the bot; only present for gifts received on behalf of business accounts | [optional] 
**transfer_star_count** | **int** | *Optional*. Number of Telegram Stars that must be paid to transfer the gift; omitted if the bot cannot transfer the gift | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


