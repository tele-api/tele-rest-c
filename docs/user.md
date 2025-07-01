# user_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **int** | Unique identifier for this user or bot. This number may have more than 32 significant bits and some programming languages may have difficulty/silent defects in interpreting it. But it has at most 52 significant bits, so a 64-bit integer or double-precision float type are safe for storing this identifier. | 
**is_bot** | **int** | *True*, if this user is a bot | 
**first_name** | **char \*** | User&#39;s or bot&#39;s first name | 
**last_name** | **char \*** | *Optional*. User&#39;s or bot&#39;s last name | [optional] 
**username** | **char \*** | *Optional*. User&#39;s or bot&#39;s username | [optional] 
**language_code** | **char \*** | *Optional*. [IETF language tag](https://en.wikipedia.org/wiki/IETF_language_tag) of the user&#39;s language | [optional] 
**is_premium** | **int** | *Optional*. *True*, if this user is a Telegram Premium user | [optional] [default to true]
**added_to_attachment_menu** | **int** | *Optional*. *True*, if this user added the bot to the attachment menu | [optional] [default to true]
**can_join_groups** | **int** | *Optional*. *True*, if the bot can be invited to groups. Returned only in [getMe](https://core.telegram.org/bots/api/#getme). | [optional] 
**can_read_all_group_messages** | **int** | *Optional*. *True*, if [privacy mode](https://core.telegram.org/bots/features#privacy-mode) is disabled for the bot. Returned only in [getMe](https://core.telegram.org/bots/api/#getme). | [optional] 
**supports_inline_queries** | **int** | *Optional*. *True*, if the bot supports inline queries. Returned only in [getMe](https://core.telegram.org/bots/api/#getme). | [optional] 
**can_connect_to_business** | **int** | *Optional*. *True*, if the bot can be connected to a Telegram Business account to receive its messages. Returned only in [getMe](https://core.telegram.org/bots/api/#getme). | [optional] 
**has_main_web_app** | **int** | *Optional*. *True*, if the bot has a main Web App. Returned only in [getMe](https://core.telegram.org/bots/api/#getme). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


