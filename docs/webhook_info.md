# webhook_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**url** | **char \*** | Webhook URL, may be empty if webhook is not set up | 
**has_custom_certificate** | **int** | *True*, if a custom certificate was provided for webhook certificate checks | 
**pending_update_count** | **int** | Number of updates awaiting delivery | 
**ip_address** | **char \*** | *Optional*. Currently used webhook IP address | [optional] 
**last_error_date** | **int** | *Optional*. Unix time for the most recent error that happened when trying to deliver an update via webhook | [optional] 
**last_error_message** | **char \*** | *Optional*. Error message in human-readable format for the most recent error that happened when trying to deliver an update via webhook | [optional] 
**last_synchronization_error_date** | **int** | *Optional*. Unix time of the most recent error that happened when trying to synchronize available updates with Telegram datacenters | [optional] 
**max_connections** | **int** | *Optional*. The maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery | [optional] 
**allowed_updates** | **list_t \*** | *Optional*. A list of update types the bot is subscribed to. Defaults to all update types except *chat\\_member* | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


