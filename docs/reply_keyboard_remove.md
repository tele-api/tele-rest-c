# reply_keyboard_remove_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**remove_keyboard** | **int** | Requests clients to remove the custom keyboard (user will not be able to summon this keyboard; if you want to hide the keyboard from sight but keep it accessible, use *one\\_time\\_keyboard* in [ReplyKeyboardMarkup](https://core.telegram.org/bots/api/#replykeyboardmarkup)) | [default to true]
**selective** | **int** | *Optional*. Use this parameter if you want to remove the keyboard for specific users only. Targets: 1) users that are @mentioned in the *text* of the [Message](https://core.telegram.org/bots/api/#message) object; 2) if the bot&#39;s message is a reply to a message in the same chat and forum topic, sender of the original message.    *Example:* A user votes in a poll, bot returns confirmation message in reply to the vote and removes the keyboard for that user, while still showing the keyboard with poll options to users who haven&#39;t voted yet. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


