# post_get_updates_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**offset** | **int** | Identifier of the first update to be returned. Must be greater by one than the highest among the identifiers of previously received updates. By default, updates starting with the earliest unconfirmed update are returned. An update is considered confirmed as soon as [getUpdates](https://core.telegram.org/bots/api/#getupdates) is called with an *offset* higher than its *update\\_id*. The negative offset can be specified to retrieve updates starting from *-offset* update from the end of the updates queue. All previous updates will be forgotten. | [optional] 
**limit** | **int** | Limits the number of updates to be retrieved. Values between 1-100 are accepted. Defaults to 100. | [optional] [default to 100]
**timeout** | **int** | Timeout in seconds for long polling. Defaults to 0, i.e. usual short polling. Should be positive, short polling should be used for testing purposes only. | [optional] [default to 0]
**allowed_updates** | **list_t \*** | A JSON-serialized list of the update types you want your bot to receive. For example, specify &#x60;[\&quot;message\&quot;, \&quot;edited_channel_post\&quot;, \&quot;callback_query\&quot;]&#x60; to only receive updates of these types. See [Update](https://core.telegram.org/bots/api/#update) for a complete list of available update types. Specify an empty list to receive all update types except *chat\\_member*, *message\\_reaction*, and *message\\_reaction\\_count* (default). If not specified, the previous setting will be used.    Please note that this parameter doesn&#39;t affect updates created before the call to getUpdates, so unwanted updates may be received for a short period of time. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


