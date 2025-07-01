# transaction_partner_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the transaction partner, always “other” | [default to 'other']
**transaction_type** | **telegram_bot_api_transaction_partner_TRANSACTIONTYPE_e** | Type of the transaction, currently one of “invoice\\_payment” for payments via invoices, “paid\\_media\\_payment” for payments for paid media, “gift\\_purchase” for gifts sent by the bot, “premium\\_purchase” for Telegram Premium subscriptions gifted by the bot, “business\\_account\\_transfer” for direct transfers from managed business accounts | 
**user** | [**user_t**](user.md) \* |  | 
**chat** | [**chat_t**](chat.md) \* |  | 
**commission_per_mille** | **int** | The number of Telegram Stars received by the bot for each 1000 Telegram Stars received by the affiliate program sponsor from referred users | 
**request_count** | **int** | The number of successful requests that exceeded regular limits and were therefore billed | 
**affiliate** | [**affiliate_info_t**](affiliate_info.md) \* |  | [optional] 
**invoice_payload** | **char \*** | *Optional*. Bot-specified invoice payload. Can be available only for “invoice\\_payment” transactions. | [optional] 
**subscription_period** | **int** | *Optional*. The duration of the paid subscription. Can be available only for “invoice\\_payment” transactions. | [optional] 
**paid_media** | [**list_t**](paid_media.md) \* | *Optional*. Information about the paid media bought by the user; for “paid\\_media\\_payment” transactions only | [optional] 
**paid_media_payload** | **char \*** | *Optional*. Bot-specified paid media payload. Can be available only for “paid\\_media\\_payment” transactions. | [optional] 
**gift** | [**gift_t**](gift.md) \* |  | [optional] 
**premium_subscription_duration** | **int** | *Optional*. Number of months the gifted Telegram Premium subscription will be active for; for “premium\\_purchase” transactions only | [optional] 
**sponsor_user** | [**user_t**](user.md) \* |  | [optional] 
**withdrawal_state** | [**revenue_withdrawal_state_t**](revenue_withdrawal_state.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


