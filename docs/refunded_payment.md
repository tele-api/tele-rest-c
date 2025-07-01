# refunded_payment_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**currency** | **char \*** | Three-letter ISO 4217 [currency](https://core.telegram.org/bots/payments#supported-currencies) code, or “XTR” for payments in [Telegram Stars](https://t.me/BotNews/90). Currently, always “XTR” | [default to 'XTR']
**total_amount** | **int** | Total refunded price in the *smallest units* of the currency (integer, **not** float/double). For example, for a price of &#x60;US$ 1.45&#x60;, &#x60;total_amount &#x3D; 145&#x60;. See the *exp* parameter in [currencies.json](https://core.telegram.org/bots/payments/currencies.json), it shows the number of digits past the decimal point for each currency (2 for the majority of currencies). | 
**invoice_payload** | **char \*** | Bot-specified invoice payload | 
**telegram_payment_charge_id** | **char \*** | Telegram payment identifier | 
**provider_payment_charge_id** | **char \*** | *Optional*. Provider payment identifier | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


