# _send_message_post_request_reply_markup_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**inline_keyboard** | **list_t \*** | Array of button rows, each represented by an Array of [InlineKeyboardButton](https://core.telegram.org/bots/api/#inlinekeyboardbutton) objects | 
**keyboard** | **list_t \*** | Array of button rows, each represented by an Array of [KeyboardButton](https://core.telegram.org/bots/api/#keyboardbutton) objects | 
**remove_keyboard** | **int** | Requests clients to remove the custom keyboard (user will not be able to summon this keyboard; if you want to hide the keyboard from sight but keep it accessible, use *one\\_time\\_keyboard* in [ReplyKeyboardMarkup](https://core.telegram.org/bots/api/#replykeyboardmarkup)) | [default to true]
**force_reply** | **int** | Shows reply interface to the user, as if they manually selected the bot&#39;s message and tapped &#39;Reply&#39; | [default to true]
**is_persistent** | **int** | *Optional*. Requests clients to always show the keyboard when the regular keyboard is hidden. Defaults to *false*, in which case the custom keyboard can be hidden and opened with a keyboard icon. | [optional] [default to false]
**resize_keyboard** | **int** | *Optional*. Requests clients to resize the keyboard vertically for optimal fit (e.g., make the keyboard smaller if there are just two rows of buttons). Defaults to *false*, in which case the custom keyboard is always of the same height as the app&#39;s standard keyboard. | [optional] [default to false]
**one_time_keyboard** | **int** | *Optional*. Requests clients to hide the keyboard as soon as it&#39;s been used. The keyboard will still be available, but clients will automatically display the usual letter-keyboard in the chat - the user can press a special button in the input field to see the custom keyboard again. Defaults to *false*. | [optional] [default to false]
**input_field_placeholder** | **char \*** | *Optional*. The placeholder to be shown in the input field when the reply is active; 1-64 characters | [optional] 
**selective** | **int** | *Optional*. Use this parameter if you want to force reply from specific users only. Targets: 1) users that are @mentioned in the *text* of the [Message](https://core.telegram.org/bots/api/#message) object; 2) if the bot&#39;s message is a reply to a message in the same chat and forum topic, sender of the original message. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


