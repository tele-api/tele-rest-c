# set_webhook_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**url** | **char \*** | HTTPS URL to send updates to. Use an empty string to remove webhook integration | 
**certificate** | **any_type_t \*** |  | [optional] 
**ip_address** | **char \*** | The fixed IP address which will be used to send webhook requests instead of the IP address resolved through DNS | [optional] 
**max_connections** | **int** | The maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery, 1-100. Defaults to *40*. Use lower values to limit the load on your bot&#39;s server, and higher values to increase your bot&#39;s throughput. | [optional] [default to 40]
**allowed_updates** | **list_t \*** | A JSON-serialized list of the update types you want your bot to receive. For example, specify &#x60;[\&quot;message\&quot;, \&quot;edited_channel_post\&quot;, \&quot;callback_query\&quot;]&#x60; to only receive updates of these types. See [Update](https://core.telegram.org/bots/api/#update) for a complete list of available update types. Specify an empty list to receive all update types except *chat\\_member*, *message\\_reaction*, and *message\\_reaction\\_count* (default). If not specified, the previous setting will be used.   Please note that this parameter doesn&#39;t affect updates created before the call to the setWebhook, so unwanted updates may be received for a short period of time. | [optional] 
**drop_pending_updates** | **int** | Pass *True* to drop all pending updates | [optional] 
**secret_token** | **char \*** | A secret token to be sent in a header “X-Telegram-Bot-Api-Secret-Token” in every webhook request, 1-256 characters. Only characters &#x60;A-Z&#x60;, &#x60;a-z&#x60;, &#x60;0-9&#x60;, &#x60;_&#x60; and &#x60;-&#x60; are allowed. The header is useful to ensure that the request comes from a webhook set by you. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


