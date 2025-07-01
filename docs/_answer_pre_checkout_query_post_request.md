# _answer_pre_checkout_query_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**pre_checkout_query_id** | **char \*** | Unique identifier for the query to be answered | 
**ok** | **int** | Specify *True* if everything is alright (goods are available, etc.) and the bot is ready to proceed with the order. Use *False* if there are any problems. | 
**error_message** | **char \*** | Required if *ok* is *False*. Error message in human readable form that explains the reason for failure to proceed with the checkout (e.g. \&quot;Sorry, somebody just bought the last of our amazing black T-shirts while you were busy filling out your payment details. Please choose a different color or garment!\&quot;). Telegram will display this message to the user. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


