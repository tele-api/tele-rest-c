# affiliate_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**commission_per_mille** | **int** | The number of Telegram Stars received by the affiliate for each 1000 Telegram Stars received by the bot from referred users | 
**amount** | **int** | Integer amount of Telegram Stars received by the affiliate from the transaction, rounded to 0; can be negative for refunds | 
**affiliate_user** | [**user_t**](user.md) \* |  | [optional] 
**affiliate_chat** | [**chat_t**](chat.md) \* |  | [optional] 
**nanostar_amount** | **int** | *Optional*. The number of 1/1000000000 shares of Telegram Stars received by the affiliate; from -999999999 to 999999999; can be negative for refunds | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


