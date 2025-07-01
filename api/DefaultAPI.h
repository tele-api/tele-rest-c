#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/_answer_web_app_query_post_200_response.h"
#include "../model/_ban_chat_member_post_request_chat_id.h"
#include "../model/_copy_message_post_200_response.h"
#include "../model/_create_chat_invite_link_post_200_response.h"
#include "../model/_create_chat_subscription_invite_link_post_request_chat_id.h"
#include "../model/_create_forum_topic_post_200_response.h"
#include "../model/_edit_message_text_post_200_response.h"
#include "../model/_edit_message_text_post_request_chat_id.h"
#include "../model/_export_chat_invite_link_post_200_response.h"
#include "../model/_forward_message_post_request_from_chat_id.h"
#include "../model/_forward_messages_post_200_response.h"
#include "../model/_forward_messages_post_request_from_chat_id.h"
#include "../model/_get_available_gifts_post_200_response.h"
#include "../model/_get_business_account_gifts_post_200_response.h"
#include "../model/_get_business_account_star_balance_post_200_response.h"
#include "../model/_get_business_connection_post_200_response.h"
#include "../model/_get_chat_administrators_post_200_response.h"
#include "../model/_get_chat_member_count_post_200_response.h"
#include "../model/_get_chat_member_post_200_response.h"
#include "../model/_get_chat_menu_button_post_200_response.h"
#include "../model/_get_chat_post_200_response.h"
#include "../model/_get_file_post_200_response.h"
#include "../model/_get_forum_topic_icon_stickers_post_200_response.h"
#include "../model/_get_game_high_scores_post_200_response.h"
#include "../model/_get_me_post_200_response.h"
#include "../model/_get_my_commands_post_200_response.h"
#include "../model/_get_my_default_administrator_rights_post_200_response.h"
#include "../model/_get_my_description_post_200_response.h"
#include "../model/_get_my_name_post_200_response.h"
#include "../model/_get_my_short_description_post_200_response.h"
#include "../model/_get_star_transactions_post_200_response.h"
#include "../model/_get_sticker_set_post_200_response.h"
#include "../model/_get_updates_post_200_response.h"
#include "../model/_get_user_chat_boosts_post_200_response.h"
#include "../model/_get_user_chat_boosts_post_request_chat_id.h"
#include "../model/_get_user_profile_photos_post_200_response.h"
#include "../model/_get_webhook_info_post_200_response.h"
#include "../model/_leave_chat_post_request_chat_id.h"
#include "../model/_post_story_post_200_response.h"
#include "../model/_restrict_chat_member_post_request_chat_id.h"
#include "../model/_revoke_chat_invite_link_post_request_chat_id.h"
#include "../model/_save_prepared_inline_message_post_200_response.h"
#include "../model/_send_animation_post_request_animation.h"
#include "../model/_send_audio_post_request_audio.h"
#include "../model/_send_audio_post_request_thumbnail.h"
#include "../model/_send_document_post_request_document.h"
#include "../model/_send_gift_post_request_chat_id.h"
#include "../model/_send_media_group_post_200_response.h"
#include "../model/_send_media_group_post_request_media_inner.h"
#include "../model/_send_message_post_200_response.h"
#include "../model/_send_message_post_request_chat_id.h"
#include "../model/_send_message_post_request_reply_markup.h"
#include "../model/_send_paid_media_post_request_chat_id.h"
#include "../model/_send_photo_post_request_photo.h"
#include "../model/_send_sticker_post_request_sticker.h"
#include "../model/_send_video_note_post_request_video_note.h"
#include "../model/_send_video_post_request_cover.h"
#include "../model/_send_video_post_request_video.h"
#include "../model/_send_voice_post_request_voice.h"
#include "../model/_set_sticker_set_thumbnail_post_request_thumbnail.h"
#include "../model/_set_webhook_post_200_response.h"
#include "../model/_stop_poll_post_200_response.h"
#include "../model/accepted_gift_types.h"
#include "../model/bot_command.h"
#include "../model/bot_command_scope.h"
#include "../model/chat_administrator_rights.h"
#include "../model/chat_permissions.h"
#include "../model/error.h"
#include "../model/inline_keyboard_markup.h"
#include "../model/inline_query_result.h"
#include "../model/inline_query_results_button.h"
#include "../model/input_media.h"
#include "../model/input_paid_media.h"
#include "../model/input_poll_option.h"
#include "../model/input_profile_photo.h"
#include "../model/input_sticker.h"
#include "../model/input_story_content.h"
#include "../model/labeled_price.h"
#include "../model/link_preview_options.h"
#include "../model/mask_position.h"
#include "../model/menu_button.h"
#include "../model/message_entity.h"
#include "../model/passport_element_error.h"
#include "../model/reaction_type.h"
#include "../model/reply_parameters.h"
#include "../model/shipping_option.h"
#include "../model/story_area.h"

// Enum ICONCOLOR for DefaultAPI_createForumTopicPost
typedef enum  { telegram_bot_api_createForumTopicPost_ICONCOLOR_NULL = 0, telegram_bot_api_createForumTopicPost_ICONCOLOR__7322096, telegram_bot_api_createForumTopicPost_ICONCOLOR__16766590, telegram_bot_api_createForumTopicPost_ICONCOLOR__13338331, telegram_bot_api_createForumTopicPost_ICONCOLOR__9367192, telegram_bot_api_createForumTopicPost_ICONCOLOR__16749490, telegram_bot_api_createForumTopicPost_ICONCOLOR__16478047 } telegram_bot_api_createForumTopicPost_icon_color_e;

// Enum STICKERTYPE for DefaultAPI_createNewStickerSetPost
typedef enum  { telegram_bot_api_createNewStickerSetPost_STICKERTYPE_NULL = 0, telegram_bot_api_createNewStickerSetPost_STICKERTYPE_mask, telegram_bot_api_createNewStickerSetPost_STICKERTYPE_custom_emoji } telegram_bot_api_createNewStickerSetPost_sticker_type_e;

// Enum MONTHCOUNT for DefaultAPI_giftPremiumSubscriptionPost
typedef enum  { telegram_bot_api_giftPremiumSubscriptionPost_MONTHCOUNT_NULL = 0, telegram_bot_api_giftPremiumSubscriptionPost_MONTHCOUNT__3, telegram_bot_api_giftPremiumSubscriptionPost_MONTHCOUNT__6, telegram_bot_api_giftPremiumSubscriptionPost_MONTHCOUNT__12 } telegram_bot_api_giftPremiumSubscriptionPost_month_count_e;

// Enum ACTIVEPERIOD for DefaultAPI_postStoryPost
typedef enum  { telegram_bot_api_postStoryPost_ACTIVEPERIOD_NULL = 0, telegram_bot_api_postStoryPost_ACTIVEPERIOD__86400 } telegram_bot_api_postStoryPost_active_period_e;

// Enum ACTION for DefaultAPI_sendChatActionPost
typedef enum  { telegram_bot_api_sendChatActionPost_ACTION_NULL = 0, telegram_bot_api_sendChatActionPost_ACTION_typing, telegram_bot_api_sendChatActionPost_ACTION_upload_photo, telegram_bot_api_sendChatActionPost_ACTION_record_video, telegram_bot_api_sendChatActionPost_ACTION_upload_video, telegram_bot_api_sendChatActionPost_ACTION_record_voice, telegram_bot_api_sendChatActionPost_ACTION_upload_voice, telegram_bot_api_sendChatActionPost_ACTION_upload_document, telegram_bot_api_sendChatActionPost_ACTION_choose_sticker, telegram_bot_api_sendChatActionPost_ACTION_find_location, telegram_bot_api_sendChatActionPost_ACTION_record_video_note, telegram_bot_api_sendChatActionPost_ACTION_upload_video_note } telegram_bot_api_sendChatActionPost_action_e;

// Enum EMOJI for DefaultAPI_sendDicePost
typedef enum  { telegram_bot_api_sendDicePost_EMOJI_NULL = 0, telegram_bot_api_sendDicePost_EMOJI_🎲, telegram_bot_api_sendDicePost_EMOJI_🎯, telegram_bot_api_sendDicePost_EMOJI_🏀, telegram_bot_api_sendDicePost_EMOJI_⚽, telegram_bot_api_sendDicePost_EMOJI_🎳, telegram_bot_api_sendDicePost_EMOJI_🎰 } telegram_bot_api_sendDicePost_emoji_e;

// Enum TYPE for DefaultAPI_sendPollPost
typedef enum  { telegram_bot_api_sendPollPost_TYPE_NULL = 0, telegram_bot_api_sendPollPost_TYPE_quiz, telegram_bot_api_sendPollPost_TYPE_regular } telegram_bot_api_sendPollPost_type_e;

// Enum FORMAT for DefaultAPI_setStickerSetThumbnailPost
typedef enum  { telegram_bot_api_setStickerSetThumbnailPost_FORMAT_NULL = 0, telegram_bot_api_setStickerSetThumbnailPost_FORMAT__static, telegram_bot_api_setStickerSetThumbnailPost_FORMAT_animated, telegram_bot_api_setStickerSetThumbnailPost_FORMAT_video } telegram_bot_api_setStickerSetThumbnailPost_format_e;

// Enum STICKERFORMAT for DefaultAPI_uploadStickerFilePost
typedef enum  { telegram_bot_api_uploadStickerFilePost_STICKERFORMAT_NULL = 0, telegram_bot_api_uploadStickerFilePost_STICKERFORMAT__static, telegram_bot_api_uploadStickerFilePost_STICKERFORMAT_animated, telegram_bot_api_uploadStickerFilePost_STICKERFORMAT_video } telegram_bot_api_uploadStickerFilePost_sticker_format_e;


// Use this method to add a new sticker to a set created by the bot. Emoji sticker sets can have up to 200 stickers. Other sticker sets can have up to 120 stickers. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_addStickerToSetPost(apiClient_t *apiClient, int *user_id, char *name, input_sticker_t *sticker);


// Use this method to send answers to callback queries sent from [inline keyboards](https://core.telegram.org/bots/features#inline-keyboards). The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, *True* is returned.  Alternatively, the user can be redirected to the specified Game URL. For this option to work, you must first create a game for your bot via [@BotFather](https://t.me/botfather) and accept the terms. Otherwise, you may use links like `t.me/your_bot?start=XXXX` that open your bot with a parameter.
//
_set_webhook_post_200_response_t*
DefaultAPI_answerCallbackQueryPost(apiClient_t *apiClient, char *callback_query_id, char *text, int *show_alert, char *url, int *cache_time);


// Use this method to send answers to an inline query. On success, *True* is returned.   No more than **50** results per query are allowed.
//
_set_webhook_post_200_response_t*
DefaultAPI_answerInlineQueryPost(apiClient_t *apiClient, char *inline_query_id, list_t *results, int *cache_time, int *is_personal, char *next_offset, inline_query_results_button_t *button);


// Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an [Update](https://core.telegram.org/bots/api/#update) with the field *pre\\_checkout\\_query*. Use this method to respond to such pre-checkout queries. On success, *True* is returned. **Note:** The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
//
_set_webhook_post_200_response_t*
DefaultAPI_answerPreCheckoutQueryPost(apiClient_t *apiClient, char *pre_checkout_query_id, int *ok, char *error_message);


// If you sent an invoice requesting a shipping address and the parameter *is\\_flexible* was specified, the Bot API will send an [Update](https://core.telegram.org/bots/api/#update) with a *shipping\\_query* field to the bot. Use this method to reply to shipping queries. On success, *True* is returned.
//
_set_webhook_post_200_response_t*
DefaultAPI_answerShippingQueryPost(apiClient_t *apiClient, char *shipping_query_id, int *ok, list_t *shipping_options, char *error_message);


// Use this method to set the result of an interaction with a [Web App](https://core.telegram.org/bots/webapps) and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a [SentWebAppMessage](https://core.telegram.org/bots/api/#sentwebappmessage) object is returned.
//
_answer_web_app_query_post_200_response_t*
DefaultAPI_answerWebAppQueryPost(apiClient_t *apiClient, char *web_app_query_id, inline_query_result_t *result);


// Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_approveChatJoinRequestPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *user_id);


// Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless [unbanned](https://core.telegram.org/bots/api/#unbanchatmember) first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_banChatMemberPost(apiClient_t *apiClient, _ban_chat_member_post_request_chat_id_t *chat_id, int *user_id, int *until_date, int *revoke_messages);


// Use this method to ban a channel chat in a supergroup or a channel. Until the chat is [unbanned](https://core.telegram.org/bots/api/#unbanchatsenderchat), the owner of the banned chat won't be able to send messages on behalf of **any of their channels**. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_banChatSenderChatPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *sender_chat_id);


// Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_closeForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *message_thread_id);


// Use this method to close an open 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_closeGeneralForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn't launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns *True* on success. Requires no parameters.
//
_set_webhook_post_200_response_t*
DefaultAPI_closePost(apiClient_t *apiClient);


// Converts a given regular gift to Telegram Stars. Requires the *can\\_convert\\_gifts\\_to\\_stars* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_convertGiftToStarsPost(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id);


// Use this method to copy messages of any kind. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessage](https://core.telegram.org/bots/api/#forwardmessage), but the copied message doesn't have a link to the original message. Returns the [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent message on success.
//
_copy_message_post_200_response_t*
DefaultAPI_copyMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _forward_message_post_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to copy messages of any kind. If some of the specified messages can't be found or copied, they are skipped. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessages](https://core.telegram.org/bots/api/#forwardmessages), but the copied messages don't have a link to the original message. Album grouping is kept for copied messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
_forward_messages_post_200_response_t*
DefaultAPI_copyMessagesPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _forward_messages_post_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content, int *remove_caption);


// Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
_create_chat_invite_link_post_200_response_t*
DefaultAPI_createChatInviteLinkPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *name, int *expire_date, int *member_limit, int *creates_join_request);


// Use this method to create a [subscription invite link](https://telegram.org/blog/superchannels-star-reactions-subscriptions#star-subscriptions) for a channel chat. The bot must have the *can\\_invite\\_users* administrator rights. The link can be edited using the method [editChatSubscriptionInviteLink](https://core.telegram.org/bots/api/#editchatsubscriptioninvitelink) or revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
_create_chat_invite_link_post_200_response_t*
DefaultAPI_createChatSubscriptionInviteLinkPost(apiClient_t *apiClient, _create_chat_subscription_invite_link_post_request_chat_id_t *chat_id, int *subscription_period, int *subscription_price, char *name);


// Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns information about the created topic as a [ForumTopic](https://core.telegram.org/bots/api/#forumtopic) object.
//
_create_forum_topic_post_200_response_t*
DefaultAPI_createForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, char *name, int *icon_color, char *icon_custom_emoji_id);


// Use this method to create a link for an invoice. Returns the created invoice link as *String* on success.
//
_export_chat_invite_link_post_200_response_t*
DefaultAPI_createInvoiceLinkPost(apiClient_t *apiClient, char *title, char *description, char *payload, char *currency, list_t *prices, char *business_connection_id, char *provider_token, int *subscription_period, int *max_tip_amount, list_t *suggested_tip_amounts, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible);


// Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_createNewStickerSetPost(apiClient_t *apiClient, int *user_id, char *name, char *title, list_t *stickers, telegram_bot_api_createNewStickerSetPost_sticker_type_e sticker_type, int *needs_repainting);


// Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_declineChatJoinRequestPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *user_id);


// Delete messages on behalf of a business account. Requires the *can\\_delete\\_sent\\_messages* business bot right to delete messages sent by the bot itself, or the *can\\_delete\\_all\\_messages* business bot right to delete any message. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteBusinessMessagesPost(apiClient_t *apiClient, char *business_connection_id, list_t *message_ids);


// Use this method to delete a chat photo. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteChatPhotoPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id);


// Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteChatStickerSetPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_delete\\_messages* administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *message_thread_id);


// Use this method to delete a message, including service messages, with the following limitations:   \\- A message can only be deleted if it was sent less than 48 hours ago.   \\- Service messages about a supergroup, channel, or forum topic creation can't be deleted.   \\- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.   \\- Bots can delete outgoing messages in private chats, groups, and supergroups.   \\- Bots can delete incoming messages in private chats.   \\- Bots granted *can\\_post\\_messages* permissions can delete outgoing messages in channels.   \\- If the bot is an administrator of a group, it can delete any message there.   \\- If the bot has *can\\_delete\\_messages* permission in a supergroup or a channel, it can delete any message there.   Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *message_id);


// Use this method to delete multiple messages simultaneously. If some of the specified messages can't be found, they are skipped. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteMessagesPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, list_t *message_ids);


// Use this method to delete the list of the bot's commands for the given scope and user language. After deletion, [higher level commands](https://core.telegram.org/bots/api/#determining-list-of-commands) will be shown to affected users. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteMyCommandsPost(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code);


// Use this method to delete a sticker from a set created by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteStickerFromSetPost(apiClient_t *apiClient, char *sticker);


// Use this method to delete a sticker set that was created by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteStickerSetPost(apiClient_t *apiClient, char *name);


// Deletes a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteStoryPost(apiClient_t *apiClient, char *business_connection_id, int *story_id);


// Use this method to remove webhook integration if you decide to switch back to [getUpdates](https://core.telegram.org/bots/api/#getupdates). Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_deleteWebhookPost(apiClient_t *apiClient, int *drop_pending_updates);


// Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
_create_chat_invite_link_post_200_response_t*
DefaultAPI_editChatInviteLinkPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *invite_link, char *name, int *expire_date, int *member_limit, int *creates_join_request);


// Use this method to edit a subscription invite link created by the bot. The bot must have the *can\\_invite\\_users* administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
_create_chat_invite_link_post_200_response_t*
DefaultAPI_editChatSubscriptionInviteLinkPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *invite_link, char *name);


// Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_editForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *message_thread_id, char *name, char *icon_custom_emoji_id);


// Use this method to edit the name of the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_editGeneralForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, char *name);


// Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
_edit_message_text_post_200_response_t*
DefaultAPI_editMessageCaptionPost(apiClient_t *apiClient, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, inline_keyboard_markup_t *reply_markup);


// Use this method to edit live location messages. A location can be edited until its *live\\_period* expires or editing is explicitly disabled by a call to [stopMessageLiveLocation](https://core.telegram.org/bots/api/#stopmessagelivelocation). On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
_edit_message_text_post_200_response_t*
DefaultAPI_editMessageLiveLocationPost(apiClient_t *apiClient, double latitude, double longitude, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, int *live_period, double horizontal_accuracy, int *heading, int *proximity_alert_radius, inline_keyboard_markup_t *reply_markup);


// Use this method to edit animation, audio, document, photo, or video messages, or to add media to text messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can't be uploaded; use a previously uploaded file via its file\\_id or specify a URL. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
_edit_message_text_post_200_response_t*
DefaultAPI_editMessageMediaPost(apiClient_t *apiClient, input_media_t *media, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
_edit_message_text_post_200_response_t*
DefaultAPI_editMessageReplyMarkupPost(apiClient_t *apiClient, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// Use this method to edit text and [game](https://core.telegram.org/bots/api/#games) messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
_edit_message_text_post_200_response_t*
DefaultAPI_editMessageTextPost(apiClient_t *apiClient, char *text, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, inline_keyboard_markup_t *reply_markup);


// Edits a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
_post_story_post_200_response_t*
DefaultAPI_editStoryPost(apiClient_t *apiClient, char *business_connection_id, int *story_id, input_story_content_t *content, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas);


// Allows the bot to cancel or re-enable extension of a subscription paid in Telegram Stars. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_editUserStarSubscriptionPost(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id, int *is_canceled);


// Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as *String* on success.
//
_export_chat_invite_link_post_200_response_t*
DefaultAPI_exportChatInviteLinkPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id);


// Use this method to forward messages of any kind. Service messages and messages with protected content can't be forwarded. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_forwardMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _forward_message_post_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, int *disable_notification, int *protect_content);


// Use this method to forward multiple messages of any kind. If some of the specified messages can't be found or forwarded, they are skipped. Service messages and messages with protected content can't be forwarded. Album grouping is kept for forwarded messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
_forward_messages_post_200_response_t*
DefaultAPI_forwardMessagesPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _forward_messages_post_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content);


// Returns the list of gifts that can be sent by the bot to users and channel chats. Requires no parameters. Returns a [Gifts](https://core.telegram.org/bots/api/#gifts) object.
//
_get_available_gifts_post_200_response_t*
DefaultAPI_getAvailableGiftsPost(apiClient_t *apiClient);


// Returns the gifts received and owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [OwnedGifts](https://core.telegram.org/bots/api/#ownedgifts) on success.
//
_get_business_account_gifts_post_200_response_t*
DefaultAPI_getBusinessAccountGiftsPost(apiClient_t *apiClient, char *business_connection_id, int *exclude_unsaved, int *exclude_saved, int *exclude_unlimited, int *exclude_limited, int *exclude_unique, int *sort_by_price, char *offset, int *limit);


// Returns the amount of Telegram Stars owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [StarAmount](https://core.telegram.org/bots/api/#staramount) on success.
//
_get_business_account_star_balance_post_200_response_t*
DefaultAPI_getBusinessAccountStarBalancePost(apiClient_t *apiClient, char *business_connection_id);


// Use this method to get information about the connection of the bot with a business account. Returns a [BusinessConnection](https://core.telegram.org/bots/api/#businessconnection) object on success.
//
_get_business_connection_post_200_response_t*
DefaultAPI_getBusinessConnectionPost(apiClient_t *apiClient, char *business_connection_id);


// Use this method to get a list of administrators in a chat, which aren't bots. Returns an Array of [ChatMember](https://core.telegram.org/bots/api/#chatmember) objects.
//
_get_chat_administrators_post_200_response_t*
DefaultAPI_getChatAdministratorsPost(apiClient_t *apiClient, _leave_chat_post_request_chat_id_t *chat_id);


// Use this method to get the number of members in a chat. Returns *Int* on success.
//
_get_chat_member_count_post_200_response_t*
DefaultAPI_getChatMemberCountPost(apiClient_t *apiClient, _leave_chat_post_request_chat_id_t *chat_id);


// Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a [ChatMember](https://core.telegram.org/bots/api/#chatmember) object on success.
//
_get_chat_member_post_200_response_t*
DefaultAPI_getChatMemberPost(apiClient_t *apiClient, _leave_chat_post_request_chat_id_t *chat_id, int *user_id);


// Use this method to get the current value of the bot's menu button in a private chat, or the default menu button. Returns [MenuButton](https://core.telegram.org/bots/api/#menubutton) on success.
//
_get_chat_menu_button_post_200_response_t*
DefaultAPI_getChatMenuButtonPost(apiClient_t *apiClient, int *chat_id);


// Use this method to get up-to-date information about the chat. Returns a [ChatFullInfo](https://core.telegram.org/bots/api/#chatfullinfo) object on success.
//
_get_chat_post_200_response_t*
DefaultAPI_getChatPost(apiClient_t *apiClient, _leave_chat_post_request_chat_id_t *chat_id);


// Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
_get_forum_topic_icon_stickers_post_200_response_t*
DefaultAPI_getCustomEmojiStickersPost(apiClient_t *apiClient, list_t *custom_emoji_ids);


// Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a [File](https://core.telegram.org/bots/api/#file) object is returned. The file can then be downloaded via the link `https://api.telegram.org/file/bot<token>/<file_path>`, where `<file_path>` is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling [getFile](https://core.telegram.org/bots/api/#getfile) again.
//
_get_file_post_200_response_t*
DefaultAPI_getFilePost(apiClient_t *apiClient, char *file_id);


// Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
_get_forum_topic_icon_stickers_post_200_response_t*
DefaultAPI_getForumTopicIconStickersPost(apiClient_t *apiClient);


// Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of [GameHighScore](https://core.telegram.org/bots/api/#gamehighscore) objects.  This method will currently return scores for the target user, plus two of their closest neighbors on each side. Will also return the top three users if the user and their neighbors are not among them. Please note that this behavior is subject to change.
//
_get_game_high_scores_post_200_response_t*
DefaultAPI_getGameHighScoresPost(apiClient_t *apiClient, int *user_id, int *chat_id, int *message_id, char *inline_message_id);


// A simple method for testing your bot's authentication token. Requires no parameters. Returns basic information about the bot in form of a [User](https://core.telegram.org/bots/api/#user) object.
//
_get_me_post_200_response_t*
DefaultAPI_getMePost(apiClient_t *apiClient);


// Use this method to get the current list of the bot's commands for the given scope and user language. Returns an Array of [BotCommand](https://core.telegram.org/bots/api/#botcommand) objects. If commands aren't set, an empty list is returned.
//
_get_my_commands_post_200_response_t*
DefaultAPI_getMyCommandsPost(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code);


// Use this method to get the current default administrator rights of the bot. Returns [ChatAdministratorRights](https://core.telegram.org/bots/api/#chatadministratorrights) on success.
//
_get_my_default_administrator_rights_post_200_response_t*
DefaultAPI_getMyDefaultAdministratorRightsPost(apiClient_t *apiClient, int *for_channels);


// Use this method to get the current bot description for the given user language. Returns [BotDescription](https://core.telegram.org/bots/api/#botdescription) on success.
//
_get_my_description_post_200_response_t*
DefaultAPI_getMyDescriptionPost(apiClient_t *apiClient, char *language_code);


// Use this method to get the current bot name for the given user language. Returns [BotName](https://core.telegram.org/bots/api/#botname) on success.
//
_get_my_name_post_200_response_t*
DefaultAPI_getMyNamePost(apiClient_t *apiClient, char *language_code);


// Use this method to get the current bot short description for the given user language. Returns [BotShortDescription](https://core.telegram.org/bots/api/#botshortdescription) on success.
//
_get_my_short_description_post_200_response_t*
DefaultAPI_getMyShortDescriptionPost(apiClient_t *apiClient, char *language_code);


// Returns the bot's Telegram Star transactions in chronological order. On success, returns a [StarTransactions](https://core.telegram.org/bots/api/#startransactions) object.
//
_get_star_transactions_post_200_response_t*
DefaultAPI_getStarTransactionsPost(apiClient_t *apiClient, int *offset, int *limit);


// Use this method to get a sticker set. On success, a [StickerSet](https://core.telegram.org/bots/api/#stickerset) object is returned.
//
_get_sticker_set_post_200_response_t*
DefaultAPI_getStickerSetPost(apiClient_t *apiClient, char *name);


// Use this method to receive incoming updates using long polling ([wiki](https://en.wikipedia.org/wiki/Push_technology#Long_polling)). Returns an Array of [Update](https://core.telegram.org/bots/api/#update) objects.
//
_get_updates_post_200_response_t*
DefaultAPI_getUpdatesPost(apiClient_t *apiClient, int *offset, int *limit, int *timeout, list_t *allowed_updates);


// Use this method to get the list of boosts added to a chat by a user. Requires administrator rights in the chat. Returns a [UserChatBoosts](https://core.telegram.org/bots/api/#userchatboosts) object.
//
_get_user_chat_boosts_post_200_response_t*
DefaultAPI_getUserChatBoostsPost(apiClient_t *apiClient, _get_user_chat_boosts_post_request_chat_id_t *chat_id, int *user_id);


// Use this method to get a list of profile pictures for a user. Returns a [UserProfilePhotos](https://core.telegram.org/bots/api/#userprofilephotos) object.
//
_get_user_profile_photos_post_200_response_t*
DefaultAPI_getUserProfilePhotosPost(apiClient_t *apiClient, int *user_id, int *offset, int *limit);


// Use this method to get current webhook status. Requires no parameters. On success, returns a [WebhookInfo](https://core.telegram.org/bots/api/#webhookinfo) object. If the bot is using [getUpdates](https://core.telegram.org/bots/api/#getupdates), will return an object with the *url* field empty.
//
_get_webhook_info_post_200_response_t*
DefaultAPI_getWebhookInfoPost(apiClient_t *apiClient);


// Gifts a Telegram Premium subscription to the given user. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_giftPremiumSubscriptionPost(apiClient_t *apiClient, int *user_id, int *month_count, int *star_count, char *text, char *text_parse_mode, list_t *text_entities);


// Use this method to hide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically closed if it was open. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_hideGeneralForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method for your bot to leave a group, supergroup or channel. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_leaveChatPost(apiClient_t *apiClient, _leave_chat_post_request_chat_id_t *chat_id);


// Use this method to log out from the cloud Bot API server before launching the bot locally. You **must** log out the bot before running it locally, otherwise there is no guarantee that the bot will receive updates. After a successful call, you can immediately log in on a local server, but will not be able to log in back to the cloud Bot API server for 10 minutes. Returns *True* on success. Requires no parameters.
//
_set_webhook_post_200_response_t*
DefaultAPI_logOutPost(apiClient_t *apiClient);


// Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_pinChatMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, int *disable_notification);


// Posts a story on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
_post_story_post_200_response_t*
DefaultAPI_postStoryPost(apiClient_t *apiClient, char *business_connection_id, input_story_content_t *content, int *active_period, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas, int *post_to_chat_page, int *protect_content);


// Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass *False* for all boolean parameters to demote a user. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_promoteChatMemberPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *user_id, int *is_anonymous, int *can_manage_chat, int *can_delete_messages, int *can_manage_video_chats, int *can_restrict_members, int *can_promote_members, int *can_change_info, int *can_invite_users, int *can_post_stories, int *can_edit_stories, int *can_delete_stories, int *can_post_messages, int *can_edit_messages, int *can_pin_messages, int *can_manage_topics);


// Marks incoming message as read on behalf of a business account. Requires the *can\\_read\\_messages* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_readBusinessMessagePost(apiClient_t *apiClient, char *business_connection_id, int *chat_id, int *message_id);


// Refunds a successful payment in [Telegram Stars](https://t.me/BotNews/90). Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_refundStarPaymentPost(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id);


// Removes the current profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_removeBusinessAccountProfilePhotoPost(apiClient_t *apiClient, char *business_connection_id, int *is_public);


// Removes verification from a chat that is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_removeChatVerificationPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id);


// Removes verification from a user who is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_removeUserVerificationPost(apiClient_t *apiClient, int *user_id);


// Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_reopenForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *message_thread_id);


// Use this method to reopen a closed 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically unhidden if it was hidden. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_reopenGeneralForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method to replace an existing sticker in a sticker set with a new one. The method is equivalent to calling [deleteStickerFromSet](https://core.telegram.org/bots/api/#deletestickerfromset), then [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), then [setStickerPositionInSet](https://core.telegram.org/bots/api/#setstickerpositioninset). Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_replaceStickerInSetPost(apiClient_t *apiClient, int *user_id, char *name, char *old_sticker, input_sticker_t *sticker);


// Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass *True* for all permissions to lift restrictions from a user. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_restrictChatMemberPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *user_id, chat_permissions_t *permissions, int *use_independent_chat_permissions, int *until_date);


// Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
_create_chat_invite_link_post_200_response_t*
DefaultAPI_revokeChatInviteLinkPost(apiClient_t *apiClient, _revoke_chat_invite_link_post_request_chat_id_t *chat_id, char *invite_link);


// Stores a message that can be sent by a user of a Mini App. Returns a [PreparedInlineMessage](https://core.telegram.org/bots/api/#preparedinlinemessage) object.
//
_save_prepared_inline_message_post_200_response_t*
DefaultAPI_savePreparedInlineMessagePost(apiClient_t *apiClient, int *user_id, inline_query_result_t *result, int *allow_user_chats, int *allow_bot_chats, int *allow_group_chats, int *allow_channel_chats);


// Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
//
_send_message_post_200_response_t*
DefaultAPI_sendAnimationPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_animation_post_request_animation_t *animation, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, _send_audio_post_request_thumbnail_t *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.  For sending voice messages, use the [sendVoice](https://core.telegram.org/bots/api/#sendvoice) method instead.
//
_send_message_post_200_response_t*
DefaultAPI_sendAudioPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_audio_post_request_audio_t *audio, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, char *performer, char *title, _send_audio_post_request_thumbnail_t *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method when you need to tell the user that something is happening on the bot's side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns *True* on success.  Example: The [ImageBot](https://t.me/imagebot) needs some time to process a request and upload the image. Instead of sending a text message along the lines of “Retrieving image, please wait…”, the bot may use [sendChatAction](https://core.telegram.org/bots/api/#sendchataction) with *action* = *upload\\_photo*. The user will see a “sending photo” status for the bot.  We only recommend using this method when a response from the bot will take a **noticeable** amount of time to arrive.
//
_set_webhook_post_200_response_t*
DefaultAPI_sendChatActionPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, telegram_bot_api_sendChatActionPost_action_e action, char *business_connection_id, int *message_thread_id);


// Use this method to send phone contacts. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendContactPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *phone_number, char *first_name, char *business_connection_id, int *message_thread_id, char *last_name, char *vcard, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send an animated emoji that will display a random value. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendDicePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *business_connection_id, int *message_thread_id, telegram_bot_api_sendDicePost_emoji_e emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send general files. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
//
_send_message_post_200_response_t*
DefaultAPI_sendDocumentPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_document_post_request_document_t *document, char *business_connection_id, int *message_thread_id, _send_audio_post_request_thumbnail_t *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *disable_content_type_detection, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send a game. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendGamePost(apiClient_t *apiClient, int *chat_id, char *game_short_name, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup);


// Sends a gift to the given user or channel chat. The gift can't be converted to Telegram Stars by the receiver. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_sendGiftPost(apiClient_t *apiClient, char *gift_id, int *user_id, _send_gift_post_request_chat_id_t *chat_id, int *pay_for_upgrade, char *text, char *text_parse_mode, list_t *text_entities);


// Use this method to send invoices. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendInvoicePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *title, char *description, char *payload, char *currency, list_t *prices, int *message_thread_id, char *provider_token, int *max_tip_amount, list_t *suggested_tip_amounts, char *start_parameter, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup);


// Use this method to send point on the map. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendLocationPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, double latitude, double longitude, char *business_connection_id, int *message_thread_id, double horizontal_accuracy, int *live_period, int *heading, int *proximity_alert_radius, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of [Messages](https://core.telegram.org/bots/api/#message) that were sent is returned.
//
_send_media_group_post_200_response_t*
DefaultAPI_sendMediaGroupPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, list_t *media, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters);


// Use this method to send text messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *text, char *business_connection_id, int *message_thread_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send paid media. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendPaidMediaPost(apiClient_t *apiClient, _send_paid_media_post_request_chat_id_t *chat_id, int *star_count, list_t *media, char *business_connection_id, char *payload, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send photos. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendPhotoPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_photo_post_request_photo_t *photo, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send a native poll. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendPollPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *question, list_t *options, char *business_connection_id, int *message_thread_id, char *question_parse_mode, list_t *question_entities, int *is_anonymous, telegram_bot_api_sendPollPost_type_e type, int *allows_multiple_answers, int *correct_option_id, char *explanation, char *explanation_parse_mode, list_t *explanation_entities, int *open_period, int *close_date, int *is_closed, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send static .WEBP, [animated](https://telegram.org/blog/animated-stickers) .TGS, or [video](https://telegram.org/blog/video-stickers-better-reactions) .WEBM stickers. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendStickerPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_sticker_post_request_sticker_t *sticker, char *business_connection_id, int *message_thread_id, char *emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send information about a venue. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendVenuePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, double latitude, double longitude, char *title, char *address, char *business_connection_id, int *message_thread_id, char *foursquare_id, char *foursquare_type, char *google_place_id, char *google_place_type, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// As of [v.4.0](https://telegram.org/blog/video-messages-and-telescope), Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
_send_message_post_200_response_t*
DefaultAPI_sendVideoNotePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_video_note_post_request_video_note_t *video_note, char *business_connection_id, int *message_thread_id, int *duration, int *length, _send_audio_post_request_thumbnail_t *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
//
_send_message_post_200_response_t*
DefaultAPI_sendVideoPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_video_post_request_video_t *video, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, _send_audio_post_request_thumbnail_t *thumbnail, _send_video_post_request_cover_t *cover, int *start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *supports_streaming, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS, or in .MP3 format, or in .M4A format (other formats may be sent as [Audio](https://core.telegram.org/bots/api/#audio) or [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
//
_send_message_post_200_response_t*
DefaultAPI_sendVoicePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, _send_voice_post_request_voice_t *voice, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, _send_message_post_request_reply_markup_t *reply_markup);


// Changes the bio of a managed business account. Requires the *can\\_change\\_bio* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setBusinessAccountBioPost(apiClient_t *apiClient, char *business_connection_id, char *bio);


// Changes the privacy settings pertaining to incoming gifts in a managed business account. Requires the *can\\_change\\_gift\\_settings* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setBusinessAccountGiftSettingsPost(apiClient_t *apiClient, char *business_connection_id, int *show_gift_button, accepted_gift_types_t *accepted_gift_types);


// Changes the first and last name of a managed business account. Requires the *can\\_change\\_name* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setBusinessAccountNamePost(apiClient_t *apiClient, char *business_connection_id, char *first_name, char *last_name);


// Changes the profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setBusinessAccountProfilePhotoPost(apiClient_t *apiClient, char *business_connection_id, input_profile_photo_t *photo, int *is_public);


// Changes the username of a managed business account. Requires the *can\\_change\\_username* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setBusinessAccountUsernamePost(apiClient_t *apiClient, char *business_connection_id, char *username);


// Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatAdministratorCustomTitlePost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *user_id, char *custom_title);


// Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatDescriptionPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *description);


// Use this method to change the bot's menu button in a private chat, or the default menu button. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatMenuButtonPost(apiClient_t *apiClient, int *chat_id, menu_button_t *menu_button);


// Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the *can\\_restrict\\_members* administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatPermissionsPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, chat_permissions_t *permissions, int *use_independent_chat_permissions);


// Use this method to set a new profile photo for the chat. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatPhotoPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, photo);


// Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatStickerSetPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, char *sticker_set_name);


// Use this method to change the title of a chat. Titles can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setChatTitlePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *title);


// Use this method to set the thumbnail of a custom emoji sticker set. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setCustomEmojiStickerSetThumbnailPost(apiClient_t *apiClient, char *name, char *custom_emoji_id);


// Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Returns an error, if the new score is not greater than the user's current score in the chat and *force* is *False*.
//
_edit_message_text_post_200_response_t*
DefaultAPI_setGameScorePost(apiClient_t *apiClient, int *user_id, int *score, int *force, int *disable_edit_message, int *chat_id, int *message_id, char *inline_message_id);


// Use this method to change the chosen reactions on a message. Service messages of some types can't be reacted to. Automatically forwarded messages from a channel to its discussion group have the same available reactions as messages in the channel. Bots can't use paid reactions. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMessageReactionPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *message_id, list_t *reaction, int *is_big);


// Use this method to change the list of the bot's commands. See [this manual](https://core.telegram.org/bots/features#commands) for more details about bot commands. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMyCommandsPost(apiClient_t *apiClient, list_t *commands, bot_command_scope_t *scope, char *language_code);


// Use this method to change the default administrator rights requested by the bot when it's added as an administrator to groups or channels. These rights will be suggested to users, but they are free to modify the list before adding the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMyDefaultAdministratorRightsPost(apiClient_t *apiClient, chat_administrator_rights_t *rights, int *for_channels);


// Use this method to change the bot's description, which is shown in the chat with the bot if the chat is empty. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMyDescriptionPost(apiClient_t *apiClient, char *description, char *language_code);


// Use this method to change the bot's name. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMyNamePost(apiClient_t *apiClient, char *name, char *language_code);


// Use this method to change the bot's short description, which is shown on the bot's profile page and is sent together with the link when users share the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setMyShortDescriptionPost(apiClient_t *apiClient, char *short_description, char *language_code);


// Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns *True* on success.  Use this if the data submitted by the user doesn't satisfy the standards your service requires for any reason. For example, if a birthday date seems invalid, a submitted document is blurry, a scan shows evidence of tampering, etc. Supply some details in the error message to make sure the user knows how to correct the issues.
//
_set_webhook_post_200_response_t*
DefaultAPI_setPassportDataErrorsPost(apiClient_t *apiClient, int *user_id, list_t *errors);


// Use this method to change the list of emoji assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerEmojiListPost(apiClient_t *apiClient, char *sticker, list_t *emoji_list);


// Use this method to change search keywords assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerKeywordsPost(apiClient_t *apiClient, char *sticker, list_t *keywords);


// Use this method to change the [mask position](https://core.telegram.org/bots/api/#maskposition) of a mask sticker. The sticker must belong to a sticker set that was created by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerMaskPositionPost(apiClient_t *apiClient, char *sticker, mask_position_t *mask_position);


// Use this method to move a sticker in a set created by the bot to a specific position. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerPositionInSetPost(apiClient_t *apiClient, char *sticker, int *position);


// Use this method to set the thumbnail of a regular or mask sticker set. The format of the thumbnail file must match the format of the stickers in the set. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerSetThumbnailPost(apiClient_t *apiClient, char *name, int *user_id, telegram_bot_api_setStickerSetThumbnailPost_format_e format, _set_sticker_set_thumbnail_post_request_thumbnail_t *thumbnail);


// Use this method to set the title of a created sticker set. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setStickerSetTitlePost(apiClient_t *apiClient, char *name, char *title);


// Changes the emoji status for a given user that previously allowed the bot to manage their emoji status via the Mini App method [requestEmojiStatusAccess](https://core.telegram.org/bots/webapps#initializing-mini-apps). Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_setUserEmojiStatusPost(apiClient_t *apiClient, int *user_id, char *emoji_status_custom_emoji_id, int *emoji_status_expiration_date);


// Use this method to specify a URL and receive incoming updates via an outgoing webhook. Whenever there is an update for the bot, we will send an HTTPS POST request to the specified URL, containing a JSON-serialized [Update](https://core.telegram.org/bots/api/#update). In case of an unsuccessful request (a request with response [HTTP status code](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) different from `2XY`), we will repeat the request and give up after a reasonable amount of attempts. Returns *True* on success.  If you'd like to make sure that the webhook was set by you, you can specify secret data in the parameter *secret\\_token*. If specified, the request will contain a header “X-Telegram-Bot-Api-Secret-Token” with the secret token as content.
//
_set_webhook_post_200_response_t*
DefaultAPI_setWebhookPost(apiClient_t *apiClient, char *url, certificate, char *ip_address, int *max_connections, list_t *allowed_updates, int *drop_pending_updates, char *secret_token);


// Use this method to stop updating a live location message before *live\\_period* expires. On success, if the message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
_edit_message_text_post_200_response_t*
DefaultAPI_stopMessageLiveLocationPost(apiClient_t *apiClient, char *business_connection_id, _edit_message_text_post_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// Use this method to stop a poll which was sent by the bot. On success, the stopped [Poll](https://core.telegram.org/bots/api/#poll) is returned.
//
_stop_poll_post_200_response_t*
DefaultAPI_stopPollPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, inline_keyboard_markup_t *reply_markup);


// Transfers Telegram Stars from the business account balance to the bot's balance. Requires the *can\\_transfer\\_stars* business bot right. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_transferBusinessAccountStarsPost(apiClient_t *apiClient, char *business_connection_id, int *star_count);


// Transfers an owned unique gift to another user. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Requires *can\\_transfer\\_stars* business bot right if the transfer is paid. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_transferGiftPost(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *new_owner_chat_id, int *star_count);


// Use this method to unban a previously banned user in a supergroup or channel. The user will **not** return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be **removed** from the chat. If you don't want this, use the parameter *only\\_if\\_banned*. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unbanChatMemberPost(apiClient_t *apiClient, _ban_chat_member_post_request_chat_id_t *chat_id, int *user_id, int *only_if_banned);


// Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unbanChatSenderChatPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, int *sender_chat_id);


// Use this method to unhide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unhideGeneralForumTopicPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unpinAllChatMessagesPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id);


// Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unpinAllForumTopicMessagesPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id, int *message_thread_id);


// Use this method to clear the list of pinned messages in a General forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unpinAllGeneralForumTopicMessagesPost(apiClient_t *apiClient, _restrict_chat_member_post_request_chat_id_t *chat_id);


// Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_unpinChatMessagePost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *business_connection_id, int *message_id);


// Upgrades a given regular gift to a unique gift. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Additionally requires the *can\\_transfer\\_stars* business bot right if the upgrade is paid. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_upgradeGiftPost(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *keep_original_details, int *star_count);


// Use this method to upload a file with a sticker for later use in the [createNewStickerSet](https://core.telegram.org/bots/api/#createnewstickerset), [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), or [replaceStickerInSet](https://core.telegram.org/bots/api/#replacestickerinset) methods (the file can be used multiple times). Returns the uploaded [File](https://core.telegram.org/bots/api/#file) on success.
//
_get_file_post_200_response_t*
DefaultAPI_uploadStickerFilePost(apiClient_t *apiClient, int *user_id, sticker, telegram_bot_api_uploadStickerFilePost_sticker_format_e sticker_format);


// Verifies a chat [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_verifyChatPost(apiClient_t *apiClient, _send_message_post_request_chat_id_t *chat_id, char *custom_description);


// Verifies a user [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
_set_webhook_post_200_response_t*
DefaultAPI_verifyUserPost(apiClient_t *apiClient, int *user_id, char *custom_description);


