# answer_inline_query_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**inline_query_id** | **char \*** | Unique identifier for the answered query | 
**results** | [**list_t**](inline_query_result.md) \* | A JSON-serialized array of results for the inline query | 
**cache_time** | **int** | The maximum amount of time in seconds that the result of the inline query may be cached on the server. Defaults to 300. | [optional] [default to 300]
**is_personal** | **int** | Pass *True* if results may be cached on the server side only for the user that sent the query. By default, results may be returned to any user who sends the same query. | [optional] 
**next_offset** | **char \*** | Pass the offset that a client should send in the next query with the same text to receive more results. Pass an empty string if there are no more results or if you don&#39;t support pagination. Offset length can&#39;t exceed 64 bytes. | [optional] 
**button** | [**inline_query_results_button_t**](inline_query_results_button.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


