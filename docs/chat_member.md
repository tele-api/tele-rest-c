# chat_member_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**status** | **char \*** | The member&#39;s status in the chat, always “kicked” | [default to 'kicked']
**user** | [**user_t**](user.md) \* |  | 
**is_anonymous** | **int** | *True*, if the user&#39;s presence in the chat is hidden | 
**can_be_edited** | **int** | *True*, if the bot is allowed to edit administrator privileges of that user | 
**can_manage_chat** | **int** | *True*, if the administrator can access the chat event log, get boost list, see hidden supergroup and channel members, report spam messages and ignore slow mode. Implied by any other administrator privilege. | 
**can_delete_messages** | **int** | *True*, if the administrator can delete messages of other users | 
**can_manage_video_chats** | **int** | *True*, if the administrator can manage video chats | 
**can_restrict_members** | **int** | *True*, if the administrator can restrict, ban or unban chat members, or access supergroup statistics | 
**can_promote_members** | **int** | *True*, if the administrator can add new administrators with a subset of their own privileges or demote administrators that they have promoted, directly or indirectly (promoted by administrators that were appointed by the user) | 
**can_change_info** | **int** | *True*, if the user is allowed to change the chat title, photo and other settings | 
**can_invite_users** | **int** | *True*, if the user is allowed to invite new users to the chat | 
**can_post_stories** | **int** | *True*, if the administrator can post stories to the chat | 
**can_edit_stories** | **int** | *True*, if the administrator can edit stories posted by other users, post stories to the chat page, pin chat stories, and access the chat&#39;s story archive | 
**can_delete_stories** | **int** | *True*, if the administrator can delete stories posted by other users | 
**can_pin_messages** | **int** | *True*, if the user is allowed to pin messages | 
**can_manage_topics** | **int** | *True*, if the user is allowed to create forum topics | 
**until_date** | **int** | Date when restrictions will be lifted for this user; Unix time. If 0, then the user is banned forever | 
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
**custom_title** | **char \*** | *Optional*. Custom title for this user | [optional] 
**can_post_messages** | **int** | *Optional*. *True*, if the administrator can post messages in the channel, or access channel statistics; for channels only | [optional] 
**can_edit_messages** | **int** | *Optional*. *True*, if the administrator can edit messages of other users and can pin messages; for channels only | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


