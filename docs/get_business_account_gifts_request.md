# get_business_account_gifts_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection | 
**exclude_unsaved** | **int** | Pass True to exclude gifts that aren&#39;t saved to the account&#39;s profile page | [optional] 
**exclude_saved** | **int** | Pass True to exclude gifts that are saved to the account&#39;s profile page | [optional] 
**exclude_unlimited** | **int** | Pass True to exclude gifts that can be purchased an unlimited number of times | [optional] 
**exclude_limited** | **int** | Pass True to exclude gifts that can be purchased a limited number of times | [optional] 
**exclude_unique** | **int** | Pass True to exclude unique gifts | [optional] 
**sort_by_price** | **int** | Pass True to sort results by gift price instead of send date. Sorting is applied before pagination. | [optional] 
**offset** | **char \*** | Offset of the first entry to return as received from the previous request; use empty string to get the first chunk of results | [optional] 
**limit** | **int** | The maximum number of gifts to be returned; 1-100. Defaults to 100 | [optional] [default to 100]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


