# _answer_shipping_query_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**shipping_query_id** | **char \*** | Unique identifier for the query to be answered | 
**ok** | **int** | Pass *True* if delivery to the specified address is possible and *False* if there are any problems (for example, if delivery to the specified address is not possible) | 
**shipping_options** | [**list_t**](shipping_option.md) \* | Required if *ok* is *True*. A JSON-serialized array of available shipping options. | [optional] 
**error_message** | **char \*** | Required if *ok* is *False*. Error message in human readable form that explains why it is impossible to complete the order (e.g. “Sorry, delivery to your desired address is unavailable”). Telegram will display this message to the user. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


