# inline_keyboard_button_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | **char \*** | Label text on the button | 
**url** | **char \*** | *Optional*. HTTP or tg:// URL to be opened when the button is pressed. Links &#x60;tg://user?id&#x3D;&lt;user_id&gt;&#x60; can be used to mention a user by their identifier without using a username, if this is allowed by their privacy settings. | [optional] 
**callback_data** | **char \*** | *Optional*. Data to be sent in a [callback query](https://core.telegram.org/bots/api/#callbackquery) to the bot when the button is pressed, 1-64 bytes | [optional] 
**web_app** | [**web_app_info_t**](web_app_info.md) \* |  | [optional] 
**login_url** | [**login_url_t**](login_url.md) \* |  | [optional] 
**switch_inline_query** | **char \*** | *Optional*. If set, pressing the button will prompt the user to select one of their chats, open that chat and insert the bot&#39;s username and the specified inline query in the input field. May be empty, in which case just the bot&#39;s username will be inserted. Not supported for messages sent on behalf of a Telegram Business account. | [optional] 
**switch_inline_query_current_chat** | **char \*** | *Optional*. If set, pressing the button will insert the bot&#39;s username and the specified inline query in the current chat&#39;s input field. May be empty, in which case only the bot&#39;s username will be inserted.    This offers a quick way for the user to open your bot in inline mode in the same chat - good for selecting something from multiple options. Not supported in channels and for messages sent on behalf of a Telegram Business account. | [optional] 
**switch_inline_query_chosen_chat** | [**switch_inline_query_chosen_chat_t**](switch_inline_query_chosen_chat.md) \* |  | [optional] 
**copy_text** | [**copy_text_button_t**](copy_text_button.md) \* |  | [optional] 
**callback_game** | **any_type_t \*** |  | [optional] 
**pay** | **int** | *Optional*. Specify *True*, to send a [Pay button](https://core.telegram.org/bots/api/#payments). Substrings “⭐” and “XTR” in the buttons&#39;s text will be replaced with a Telegram Star icon.    **NOTE:** This type of button **must** always be the first button in the first row and can only be used in invoice messages. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


