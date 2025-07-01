# chat_member_restricted_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | The member&#39;s status in the chat, always “restricted” | [default to 'restricted']
**user** | [**user_t**](user.md) \* |  | 
**is_member** | **int** | *True*, if the user is a member of the chat at the moment of the request | 
**can_send_messages** | **int** | *True*, if the user is allowed to send text messages, contacts, giveaways, giveaway winners, invoices, locations and venues | 
**can_send_audios** | **int** | *True*, if the user is allowed to send audios | 
**can_send_documents** | **int** | *True*, if the user is allowed to send documents | 
**can_send_photos** | **int** | *True*, if the user is allowed to send photos | 
**can_send_videos** | **int** | *True*, if the user is allowed to send videos | 
**can_send_video_notes** | **int** | *True*, if the user is allowed to send video notes | 
**can_send_voice_notes** | **int** | *True*, if the user is allowed to send voice notes | 
**can_send_polls** | **int** | *True*, if the user is allowed to send polls | 
**can_send_other_messages** | **int** | *True*, if the user is allowed to send animations, games, stickers and use inline bots | 
**can_add_web_page_previews** | **int** | *True*, if the user is allowed to add web page previews to their messages | 
**can_change_info** | **int** | *True*, if the user is allowed to change the chat title, photo and other settings | 
**can_invite_users** | **int** | *True*, if the user is allowed to invite new users to the chat | 
**can_pin_messages** | **int** | *True*, if the user is allowed to pin messages | 
**can_manage_topics** | **int** | *True*, if the user is allowed to create forum topics | 
**until_date** | **int** | Date when restrictions will be lifted for this user; Unix time. If 0, then the user is restricted forever | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


