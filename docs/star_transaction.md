# star_transaction_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique identifier of the transaction. Coincides with the identifier of the original transaction for refund transactions. Coincides with *SuccessfulPayment.telegram\\_payment\\_charge\\_id* for successful incoming payments from users. | 
**amount** | **int** | Integer amount of Telegram Stars transferred by the transaction | 
**date** | **int** | Date the transaction was created in Unix time | 
**nanostar_amount** | **int** | *Optional*. The number of 1/1000000000 shares of Telegram Stars transferred by the transaction; from 0 to 999999999 | [optional] 
**source** | [**transaction_partner_t**](transaction_partner.md) \* |  | [optional] 
**receiver** | [**transaction_partner_t**](transaction_partner.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


