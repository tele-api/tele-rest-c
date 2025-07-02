# post_set_my_commands_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**commands** | [**list_t**](bot_command.md) \* | A JSON-serialized list of bot commands to be set as the list of the bot&#39;s commands. At most 100 commands can be specified. | 
**scope** | [**bot_command_scope_t**](bot_command_scope.md) \* |  | [optional] 
**language_code** | **char \*** | A two-letter ISO 639-1 language code. If empty, commands will be applied to all users from the given scope, for whose language there are no dedicated commands | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


