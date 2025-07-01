# _set_chat_permissions_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat_id** | [**_restrict_chat_member_post_request_chat_id_t**](_restrict_chat_member_post_request_chat_id.md) \* |  | 
**permissions** | [**chat_permissions_t**](chat_permissions.md) \* |  | 
**use_independent_chat_permissions** | **int** | Pass *True* if chat permissions are set independently. Otherwise, the *can\\_send\\_other\\_messages* and *can\\_add\\_web\\_page\\_previews* permissions will imply the *can\\_send\\_messages*, *can\\_send\\_audios*, *can\\_send\\_documents*, *can\\_send\\_photos*, *can\\_send\\_videos*, *can\\_send\\_video\\_notes*, and *can\\_send\\_voice\\_notes* permissions; the *can\\_send\\_polls* permission will imply the *can\\_send\\_messages* permission. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


