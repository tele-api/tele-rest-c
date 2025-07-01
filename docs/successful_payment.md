# successful_payment_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** | Three-letter ISO 4217 [currency](https://core.telegram.org/bots/payments#supported-currencies) code, or “XTR” for payments in [Telegram Stars](https://t.me/BotNews/90) | 
**total_amount** | **int** | Total price in the *smallest units* of the currency (integer, **not** float/double). For example, for a price of &#x60;US$ 1.45&#x60; pass &#x60;amount &#x3D; 145&#x60;. See the *exp* parameter in [currencies.json](https://core.telegram.org/bots/payments/currencies.json), it shows the number of digits past the decimal point for each currency (2 for the majority of currencies). | 
**invoice_payload** | **char \*** | Bot-specified invoice payload | 
**telegram_payment_charge_id** | **char \*** | Telegram payment identifier | 
**provider_payment_charge_id** | **char \*** | Provider payment identifier | 
**subscription_expiration_date** | **int** | *Optional*. Expiration date of the subscription, in Unix time; for recurring payments only | [optional] 
**is_recurring** | **int** | *Optional*. True, if the payment is a recurring payment for a subscription | [optional] [default to true]
**is_first_recurring** | **int** | *Optional*. True, if the payment is the first payment for a subscription | [optional] [default to true]
**shipping_option_id** | **char \*** | *Optional*. Identifier of the shipping option chosen by the user | [optional] 
**order_info** | [**order_info_t**](order_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


