#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/accepted_gift_types.h"
#include "../model/add_sticker_to_set_response.h"
#include "../model/answer_callback_query_response.h"
#include "../model/answer_inline_query_response.h"
#include "../model/answer_pre_checkout_query_response.h"
#include "../model/answer_shipping_query_response.h"
#include "../model/answer_web_app_query_response.h"
#include "../model/approve_chat_join_request_response.h"
#include "../model/ban_chat_member_request_chat_id.h"
#include "../model/ban_chat_member_response.h"
#include "../model/ban_chat_sender_chat_response.h"
#include "../model/bot_command.h"
#include "../model/bot_command_scope.h"
#include "../model/bot_command_scope_chat_chat_id.h"
#include "../model/chat_administrator_rights.h"
#include "../model/chat_permissions.h"
#include "../model/close_forum_topic_response.h"
#include "../model/close_general_forum_topic_response.h"
#include "../model/close_response.h"
#include "../model/convert_gift_to_stars_response.h"
#include "../model/copy_message_response.h"
#include "../model/copy_messages_response.h"
#include "../model/create_chat_invite_link_response.h"
#include "../model/create_chat_subscription_invite_link_request_chat_id.h"
#include "../model/create_chat_subscription_invite_link_response.h"
#include "../model/create_forum_topic_response.h"
#include "../model/create_invoice_link_response.h"
#include "../model/create_new_sticker_set_response.h"
#include "../model/decline_chat_join_request_response.h"
#include "../model/delete_business_messages_response.h"
#include "../model/delete_chat_photo_response.h"
#include "../model/delete_chat_sticker_set_response.h"
#include "../model/delete_forum_topic_response.h"
#include "../model/delete_message_response.h"
#include "../model/delete_messages_response.h"
#include "../model/delete_my_commands_response.h"
#include "../model/delete_sticker_from_set_response.h"
#include "../model/delete_sticker_set_response.h"
#include "../model/delete_story_response.h"
#include "../model/delete_webhook_response.h"
#include "../model/edit_chat_invite_link_response.h"
#include "../model/edit_chat_subscription_invite_link_response.h"
#include "../model/edit_forum_topic_response.h"
#include "../model/edit_general_forum_topic_response.h"
#include "../model/edit_message_caption_response.h"
#include "../model/edit_message_live_location_response.h"
#include "../model/edit_message_media_response.h"
#include "../model/edit_message_reply_markup_response.h"
#include "../model/edit_message_text_request_chat_id.h"
#include "../model/edit_message_text_response.h"
#include "../model/edit_story_response.h"
#include "../model/edit_user_star_subscription_response.h"
#include "../model/error.h"
#include "../model/export_chat_invite_link_response.h"
#include "../model/forward_message_request_from_chat_id.h"
#include "../model/forward_message_response.h"
#include "../model/forward_messages_request_from_chat_id.h"
#include "../model/forward_messages_response.h"
#include "../model/get_available_gifts_response.h"
#include "../model/get_business_account_gifts_response.h"
#include "../model/get_business_account_star_balance_response.h"
#include "../model/get_business_connection_response.h"
#include "../model/get_chat_administrators_response.h"
#include "../model/get_chat_member_count_response.h"
#include "../model/get_chat_member_response.h"
#include "../model/get_chat_menu_button_response.h"
#include "../model/get_chat_response.h"
#include "../model/get_custom_emoji_stickers_response.h"
#include "../model/get_file_response.h"
#include "../model/get_forum_topic_icon_stickers_response.h"
#include "../model/get_game_high_scores_response.h"
#include "../model/get_me_response.h"
#include "../model/get_my_commands_response.h"
#include "../model/get_my_default_administrator_rights_response.h"
#include "../model/get_my_description_response.h"
#include "../model/get_my_name_response.h"
#include "../model/get_my_short_description_response.h"
#include "../model/get_star_transactions_response.h"
#include "../model/get_sticker_set_response.h"
#include "../model/get_updates_response.h"
#include "../model/get_user_chat_boosts_request_chat_id.h"
#include "../model/get_user_chat_boosts_response.h"
#include "../model/get_user_profile_photos_response.h"
#include "../model/get_webhook_info_response.h"
#include "../model/gift_premium_subscription_response.h"
#include "../model/hide_general_forum_topic_response.h"
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
#include "../model/leave_chat_request_chat_id.h"
#include "../model/leave_chat_response.h"
#include "../model/link_preview_options.h"
#include "../model/log_out_response.h"
#include "../model/mask_position.h"
#include "../model/menu_button.h"
#include "../model/message_entity.h"
#include "../model/passport_element_error.h"
#include "../model/pin_chat_message_response.h"
#include "../model/post_story_response.h"
#include "../model/promote_chat_member_response.h"
#include "../model/reaction_type.h"
#include "../model/read_business_message_response.h"
#include "../model/refund_star_payment_response.h"
#include "../model/remove_business_account_profile_photo_response.h"
#include "../model/remove_chat_verification_response.h"
#include "../model/remove_user_verification_response.h"
#include "../model/reopen_forum_topic_response.h"
#include "../model/reopen_general_forum_topic_response.h"
#include "../model/replace_sticker_in_set_response.h"
#include "../model/reply_parameters.h"
#include "../model/restrict_chat_member_response.h"
#include "../model/revoke_chat_invite_link_request_chat_id.h"
#include "../model/revoke_chat_invite_link_response.h"
#include "../model/save_prepared_inline_message_response.h"
#include "../model/send_animation_response.h"
#include "../model/send_audio_response.h"
#include "../model/send_chat_action_response.h"
#include "../model/send_contact_response.h"
#include "../model/send_dice_response.h"
#include "../model/send_document_response.h"
#include "../model/send_game_response.h"
#include "../model/send_gift_request_chat_id.h"
#include "../model/send_gift_response.h"
#include "../model/send_invoice_response.h"
#include "../model/send_location_response.h"
#include "../model/send_media_group_request_media_inner.h"
#include "../model/send_media_group_response.h"
#include "../model/send_message_request_chat_id.h"
#include "../model/send_message_request_reply_markup.h"
#include "../model/send_message_response.h"
#include "../model/send_paid_media_request_chat_id.h"
#include "../model/send_paid_media_response.h"
#include "../model/send_photo_response.h"
#include "../model/send_poll_response.h"
#include "../model/send_sticker_response.h"
#include "../model/send_venue_response.h"
#include "../model/send_video_note_response.h"
#include "../model/send_video_response.h"
#include "../model/send_voice_response.h"
#include "../model/set_business_account_bio_response.h"
#include "../model/set_business_account_gift_settings_response.h"
#include "../model/set_business_account_name_response.h"
#include "../model/set_business_account_profile_photo_response.h"
#include "../model/set_business_account_username_response.h"
#include "../model/set_chat_administrator_custom_title_response.h"
#include "../model/set_chat_description_response.h"
#include "../model/set_chat_menu_button_response.h"
#include "../model/set_chat_permissions_response.h"
#include "../model/set_chat_photo_response.h"
#include "../model/set_chat_sticker_set_response.h"
#include "../model/set_chat_title_response.h"
#include "../model/set_custom_emoji_sticker_set_thumbnail_response.h"
#include "../model/set_game_score_response.h"
#include "../model/set_message_reaction_response.h"
#include "../model/set_my_commands_response.h"
#include "../model/set_my_default_administrator_rights_response.h"
#include "../model/set_my_description_response.h"
#include "../model/set_my_name_response.h"
#include "../model/set_my_short_description_response.h"
#include "../model/set_passport_data_errors_response.h"
#include "../model/set_sticker_emoji_list_response.h"
#include "../model/set_sticker_keywords_response.h"
#include "../model/set_sticker_mask_position_response.h"
#include "../model/set_sticker_position_in_set_response.h"
#include "../model/set_sticker_set_thumbnail_response.h"
#include "../model/set_sticker_set_title_response.h"
#include "../model/set_user_emoji_status_response.h"
#include "../model/set_webhook_response.h"
#include "../model/shipping_option.h"
#include "../model/stop_message_live_location_response.h"
#include "../model/stop_poll_response.h"
#include "../model/story_area.h"
#include "../model/transfer_business_account_stars_response.h"
#include "../model/transfer_gift_response.h"
#include "../model/unban_chat_member_response.h"
#include "../model/unban_chat_sender_chat_response.h"
#include "../model/unhide_general_forum_topic_response.h"
#include "../model/unpin_all_chat_messages_response.h"
#include "../model/unpin_all_forum_topic_messages_response.h"
#include "../model/unpin_all_general_forum_topic_messages_response.h"
#include "../model/unpin_chat_message_response.h"
#include "../model/upgrade_gift_response.h"
#include "../model/upload_sticker_file_response.h"
#include "../model/verify_chat_response.h"
#include "../model/verify_user_response.h"

// Enum ICONCOLOR for DefaultAPI_postCreateForumTopic
typedef enum  { telegram_bot_api_postCreateForumTopic_ICONCOLOR_NULL = 0, telegram_bot_api_postCreateForumTopic_ICONCOLOR__7322096, telegram_bot_api_postCreateForumTopic_ICONCOLOR__16766590, telegram_bot_api_postCreateForumTopic_ICONCOLOR__13338331, telegram_bot_api_postCreateForumTopic_ICONCOLOR__9367192, telegram_bot_api_postCreateForumTopic_ICONCOLOR__16749490, telegram_bot_api_postCreateForumTopic_ICONCOLOR__16478047 } telegram_bot_api_postCreateForumTopic_icon_color_e;

// Enum STICKERTYPE for DefaultAPI_postCreateNewStickerSet
typedef enum  { telegram_bot_api_postCreateNewStickerSet_STICKERTYPE_NULL = 0, telegram_bot_api_postCreateNewStickerSet_STICKERTYPE_mask, telegram_bot_api_postCreateNewStickerSet_STICKERTYPE_custom_emoji } telegram_bot_api_postCreateNewStickerSet_sticker_type_e;

// Enum MONTHCOUNT for DefaultAPI_postGiftPremiumSubscription
typedef enum  { telegram_bot_api_postGiftPremiumSubscription_MONTHCOUNT_NULL = 0, telegram_bot_api_postGiftPremiumSubscription_MONTHCOUNT__3, telegram_bot_api_postGiftPremiumSubscription_MONTHCOUNT__6, telegram_bot_api_postGiftPremiumSubscription_MONTHCOUNT__12 } telegram_bot_api_postGiftPremiumSubscription_month_count_e;

// Enum ACTIVEPERIOD for DefaultAPI_postPostStory
typedef enum  { telegram_bot_api_postPostStory_ACTIVEPERIOD_NULL = 0, telegram_bot_api_postPostStory_ACTIVEPERIOD__86400 } telegram_bot_api_postPostStory_active_period_e;

// Enum ACTION for DefaultAPI_postSendChatAction
typedef enum  { telegram_bot_api_postSendChatAction_ACTION_NULL = 0, telegram_bot_api_postSendChatAction_ACTION_typing, telegram_bot_api_postSendChatAction_ACTION_upload_photo, telegram_bot_api_postSendChatAction_ACTION_record_video, telegram_bot_api_postSendChatAction_ACTION_upload_video, telegram_bot_api_postSendChatAction_ACTION_record_voice, telegram_bot_api_postSendChatAction_ACTION_upload_voice, telegram_bot_api_postSendChatAction_ACTION_upload_document, telegram_bot_api_postSendChatAction_ACTION_choose_sticker, telegram_bot_api_postSendChatAction_ACTION_find_location, telegram_bot_api_postSendChatAction_ACTION_record_video_note, telegram_bot_api_postSendChatAction_ACTION_upload_video_note } telegram_bot_api_postSendChatAction_action_e;

// Enum EMOJI for DefaultAPI_postSendDice
typedef enum  { telegram_bot_api_postSendDice_EMOJI_NULL = 0, telegram_bot_api_postSendDice_EMOJI_🎲, telegram_bot_api_postSendDice_EMOJI_🎯, telegram_bot_api_postSendDice_EMOJI_🏀, telegram_bot_api_postSendDice_EMOJI_⚽, telegram_bot_api_postSendDice_EMOJI_🎳, telegram_bot_api_postSendDice_EMOJI_🎰 } telegram_bot_api_postSendDice_emoji_e;

// Enum TYPE for DefaultAPI_postSendPoll
typedef enum  { telegram_bot_api_postSendPoll_TYPE_NULL = 0, telegram_bot_api_postSendPoll_TYPE_quiz, telegram_bot_api_postSendPoll_TYPE_regular } telegram_bot_api_postSendPoll_type_e;

// Enum FORMAT for DefaultAPI_postSetStickerSetThumbnail
typedef enum  { telegram_bot_api_postSetStickerSetThumbnail_FORMAT_NULL = 0, telegram_bot_api_postSetStickerSetThumbnail_FORMAT__static, telegram_bot_api_postSetStickerSetThumbnail_FORMAT_animated, telegram_bot_api_postSetStickerSetThumbnail_FORMAT_video } telegram_bot_api_postSetStickerSetThumbnail_format_e;

// Enum STICKERFORMAT for DefaultAPI_postUploadStickerFile
typedef enum  { telegram_bot_api_postUploadStickerFile_STICKERFORMAT_NULL = 0, telegram_bot_api_postUploadStickerFile_STICKERFORMAT__static, telegram_bot_api_postUploadStickerFile_STICKERFORMAT_animated, telegram_bot_api_postUploadStickerFile_STICKERFORMAT_video } telegram_bot_api_postUploadStickerFile_sticker_format_e;


// addStickerToSet
//
// Use this method to add a new sticker to a set created by the bot. Emoji sticker sets can have up to 200 stickers. Other sticker sets can have up to 120 stickers. Returns *True* on success.
//
add_sticker_to_set_response_t*
DefaultAPI_postAddStickerToSet(apiClient_t *apiClient, int *user_id, char *name, input_sticker_t *sticker);


// answerCallbackQuery
//
// Use this method to send answers to callback queries sent from [inline keyboards](https://core.telegram.org/bots/features#inline-keyboards). The answer will be displayed to the user as a notification at the top of the chat screen or as an alert. On success, *True* is returned.  Alternatively, the user can be redirected to the specified Game URL. For this option to work, you must first create a game for your bot via [@BotFather](https://t.me/botfather) and accept the terms. Otherwise, you may use links like `t.me/your_bot?start=XXXX` that open your bot with a parameter.
//
answer_callback_query_response_t*
DefaultAPI_postAnswerCallbackQuery(apiClient_t *apiClient, char *callback_query_id, char *text, int *show_alert, char *url, int *cache_time);


// answerInlineQuery
//
// Use this method to send answers to an inline query. On success, *True* is returned.   No more than **50** results per query are allowed.
//
answer_inline_query_response_t*
DefaultAPI_postAnswerInlineQuery(apiClient_t *apiClient, char *inline_query_id, list_t *results, int *cache_time, int *is_personal, char *next_offset, inline_query_results_button_t *button);


// answerPreCheckoutQuery
//
// Once the user has confirmed their payment and shipping details, the Bot API sends the final confirmation in the form of an [Update](https://core.telegram.org/bots/api/#update) with the field *pre\\_checkout\\_query*. Use this method to respond to such pre-checkout queries. On success, *True* is returned. **Note:** The Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
//
answer_pre_checkout_query_response_t*
DefaultAPI_postAnswerPreCheckoutQuery(apiClient_t *apiClient, char *pre_checkout_query_id, int *ok, char *error_message);


// answerShippingQuery
//
// If you sent an invoice requesting a shipping address and the parameter *is\\_flexible* was specified, the Bot API will send an [Update](https://core.telegram.org/bots/api/#update) with a *shipping\\_query* field to the bot. Use this method to reply to shipping queries. On success, *True* is returned.
//
answer_shipping_query_response_t*
DefaultAPI_postAnswerShippingQuery(apiClient_t *apiClient, char *shipping_query_id, int *ok, list_t *shipping_options, char *error_message);


// answerWebAppQuery
//
// Use this method to set the result of an interaction with a [Web App](https://core.telegram.org/bots/webapps) and send a corresponding message on behalf of the user to the chat from which the query originated. On success, a [SentWebAppMessage](https://core.telegram.org/bots/api/#sentwebappmessage) object is returned.
//
answer_web_app_query_response_t*
DefaultAPI_postAnswerWebAppQuery(apiClient_t *apiClient, char *web_app_query_id, inline_query_result_t *result);


// approveChatJoinRequest
//
// Use this method to approve a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
approve_chat_join_request_response_t*
DefaultAPI_postApproveChatJoinRequest(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *user_id);


// banChatMember
//
// Use this method to ban a user in a group, a supergroup or a channel. In the case of supergroups and channels, the user will not be able to return to the chat on their own using invite links, etc., unless [unbanned](https://core.telegram.org/bots/api/#unbanchatmember) first. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
ban_chat_member_response_t*
DefaultAPI_postBanChatMember(apiClient_t *apiClient, ban_chat_member_request_chat_id_t *chat_id, int *user_id, int *until_date, int *revoke_messages);


// banChatSenderChat
//
// Use this method to ban a channel chat in a supergroup or a channel. Until the chat is [unbanned](https://core.telegram.org/bots/api/#unbanchatsenderchat), the owner of the banned chat won't be able to send messages on behalf of **any of their channels**. The bot must be an administrator in the supergroup or channel for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
ban_chat_sender_chat_response_t*
DefaultAPI_postBanChatSenderChat(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *sender_chat_id);


// close
//
// Use this method to close the bot instance before moving it from one local server to another. You need to delete the webhook before calling this method to ensure that the bot isn't launched again after server restart. The method will return error 429 in the first 10 minutes after the bot is launched. Returns *True* on success. Requires no parameters.
//
close_response_t*
DefaultAPI_postClose(apiClient_t *apiClient);


// closeForumTopic
//
// Use this method to close an open topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
close_forum_topic_response_t*
DefaultAPI_postCloseForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *message_thread_id);


// closeGeneralForumTopic
//
// Use this method to close an open 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
close_general_forum_topic_response_t*
DefaultAPI_postCloseGeneralForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// convertGiftToStars
//
// Converts a given regular gift to Telegram Stars. Requires the *can\\_convert\\_gifts\\_to\\_stars* business bot right. Returns *True* on success.
//
convert_gift_to_stars_response_t*
DefaultAPI_postConvertGiftToStars(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id);


// copyMessage
//
// Use this method to copy messages of any kind. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessage](https://core.telegram.org/bots/api/#forwardmessage), but the copied message doesn't have a link to the original message. Returns the [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent message on success.
//
copy_message_response_t*
DefaultAPI_postCopyMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, forward_message_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// copyMessages
//
// Use this method to copy messages of any kind. If some of the specified messages can't be found or copied, they are skipped. Service messages, paid media messages, giveaway messages, giveaway winners messages, and invoice messages can't be copied. A quiz [poll](https://core.telegram.org/bots/api/#poll) can be copied only if the value of the field *correct\\_option\\_id* is known to the bot. The method is analogous to the method [forwardMessages](https://core.telegram.org/bots/api/#forwardmessages), but the copied messages don't have a link to the original message. Album grouping is kept for copied messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
copy_messages_response_t*
DefaultAPI_postCopyMessages(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, forward_messages_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content, int *remove_caption);


// createChatInviteLink
//
// Use this method to create an additional invite link for a chat. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. The link can be revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
create_chat_invite_link_response_t*
DefaultAPI_postCreateChatInviteLink(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *name, int *expire_date, int *member_limit, int *creates_join_request);


// createChatSubscriptionInviteLink
//
// Use this method to create a [subscription invite link](https://telegram.org/blog/superchannels-star-reactions-subscriptions#star-subscriptions) for a channel chat. The bot must have the *can\\_invite\\_users* administrator rights. The link can be edited using the method [editChatSubscriptionInviteLink](https://core.telegram.org/bots/api/#editchatsubscriptioninvitelink) or revoked using the method [revokeChatInviteLink](https://core.telegram.org/bots/api/#revokechatinvitelink). Returns the new invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
create_chat_subscription_invite_link_response_t*
DefaultAPI_postCreateChatSubscriptionInviteLink(apiClient_t *apiClient, create_chat_subscription_invite_link_request_chat_id_t *chat_id, int *subscription_period, int *subscription_price, char *name);


// createForumTopic
//
// Use this method to create a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns information about the created topic as a [ForumTopic](https://core.telegram.org/bots/api/#forumtopic) object.
//
create_forum_topic_response_t*
DefaultAPI_postCreateForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, char *name, int *icon_color, char *icon_custom_emoji_id);


// createInvoiceLink
//
// Use this method to create a link for an invoice. Returns the created invoice link as *String* on success.
//
create_invoice_link_response_t*
DefaultAPI_postCreateInvoiceLink(apiClient_t *apiClient, char *title, char *description, char *payload, char *currency, list_t *prices, char *business_connection_id, char *provider_token, int *subscription_period, int *max_tip_amount, list_t *suggested_tip_amounts, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible);


// createNewStickerSet
//
// Use this method to create a new sticker set owned by a user. The bot will be able to edit the sticker set thus created. Returns *True* on success.
//
create_new_sticker_set_response_t*
DefaultAPI_postCreateNewStickerSet(apiClient_t *apiClient, int *user_id, char *name, char *title, list_t *stickers, telegram_bot_api_postCreateNewStickerSet_sticker_type_e sticker_type, int *needs_repainting);


// declineChatJoinRequest
//
// Use this method to decline a chat join request. The bot must be an administrator in the chat for this to work and must have the *can\\_invite\\_users* administrator right. Returns *True* on success.
//
decline_chat_join_request_response_t*
DefaultAPI_postDeclineChatJoinRequest(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *user_id);


// deleteBusinessMessages
//
// Delete messages on behalf of a business account. Requires the *can\\_delete\\_outgoing\\_messages* business bot right to delete messages sent by the bot itself, or the *can\\_delete\\_all\\_messages* business bot right to delete any message. Returns *True* on success.
//
delete_business_messages_response_t*
DefaultAPI_postDeleteBusinessMessages(apiClient_t *apiClient, char *business_connection_id, list_t *message_ids);


// deleteChatPhoto
//
// Use this method to delete a chat photo. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
delete_chat_photo_response_t*
DefaultAPI_postDeleteChatPhoto(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id);


// deleteChatStickerSet
//
// Use this method to delete a group sticker set from a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
delete_chat_sticker_set_response_t*
DefaultAPI_postDeleteChatStickerSet(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// deleteForumTopic
//
// Use this method to delete a forum topic along with all its messages in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_delete\\_messages* administrator rights. Returns *True* on success.
//
delete_forum_topic_response_t*
DefaultAPI_postDeleteForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *message_thread_id);


// deleteMessage
//
// Use this method to delete a message, including service messages, with the following limitations:   \\- A message can only be deleted if it was sent less than 48 hours ago.   \\- Service messages about a supergroup, channel, or forum topic creation can't be deleted.   \\- A dice message in a private chat can only be deleted if it was sent more than 24 hours ago.   \\- Bots can delete outgoing messages in private chats, groups, and supergroups.   \\- Bots can delete incoming messages in private chats.   \\- Bots granted *can\\_post\\_messages* permissions can delete outgoing messages in channels.   \\- If the bot is an administrator of a group, it can delete any message there.   \\- If the bot has *can\\_delete\\_messages* permission in a supergroup or a channel, it can delete any message there.   Returns *True* on success.
//
delete_message_response_t*
DefaultAPI_postDeleteMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *message_id);


// deleteMessages
//
// Use this method to delete multiple messages simultaneously. If some of the specified messages can't be found, they are skipped. Returns *True* on success.
//
delete_messages_response_t*
DefaultAPI_postDeleteMessages(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, list_t *message_ids);


// deleteMyCommands
//
// Use this method to delete the list of the bot's commands for the given scope and user language. After deletion, [higher level commands](https://core.telegram.org/bots/api/#determining-list-of-commands) will be shown to affected users. Returns *True* on success.
//
delete_my_commands_response_t*
DefaultAPI_postDeleteMyCommands(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code);


// deleteStickerFromSet
//
// Use this method to delete a sticker from a set created by the bot. Returns *True* on success.
//
delete_sticker_from_set_response_t*
DefaultAPI_postDeleteStickerFromSet(apiClient_t *apiClient, char *sticker);


// deleteStickerSet
//
// Use this method to delete a sticker set that was created by the bot. Returns *True* on success.
//
delete_sticker_set_response_t*
DefaultAPI_postDeleteStickerSet(apiClient_t *apiClient, char *name);


// deleteStory
//
// Deletes a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns *True* on success.
//
delete_story_response_t*
DefaultAPI_postDeleteStory(apiClient_t *apiClient, char *business_connection_id, int *story_id);


// deleteWebhook
//
// Use this method to remove webhook integration if you decide to switch back to [getUpdates](https://core.telegram.org/bots/api/#getupdates). Returns *True* on success.
//
delete_webhook_response_t*
DefaultAPI_postDeleteWebhook(apiClient_t *apiClient, int *drop_pending_updates);


// editChatInviteLink
//
// Use this method to edit a non-primary invite link created by the bot. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
edit_chat_invite_link_response_t*
DefaultAPI_postEditChatInviteLink(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *invite_link, char *name, int *expire_date, int *member_limit, int *creates_join_request);


// editChatSubscriptionInviteLink
//
// Use this method to edit a subscription invite link created by the bot. The bot must have the *can\\_invite\\_users* administrator rights. Returns the edited invite link as a [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
edit_chat_subscription_invite_link_response_t*
DefaultAPI_postEditChatSubscriptionInviteLink(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *invite_link, char *name);


// editForumTopic
//
// Use this method to edit name and icon of a topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
edit_forum_topic_response_t*
DefaultAPI_postEditForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *message_thread_id, char *name, char *icon_custom_emoji_id);


// editGeneralForumTopic
//
// Use this method to edit the name of the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
edit_general_forum_topic_response_t*
DefaultAPI_postEditGeneralForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, char *name);


// editMessageCaption
//
// Use this method to edit captions of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
edit_message_caption_response_t*
DefaultAPI_postEditMessageCaption(apiClient_t *apiClient, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, inline_keyboard_markup_t *reply_markup);


// editMessageLiveLocation
//
// Use this method to edit live location messages. A location can be edited until its *live\\_period* expires or editing is explicitly disabled by a call to [stopMessageLiveLocation](https://core.telegram.org/bots/api/#stopmessagelivelocation). On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
edit_message_live_location_response_t*
DefaultAPI_postEditMessageLiveLocation(apiClient_t *apiClient, double latitude, double longitude, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, int *live_period, double horizontal_accuracy, int *heading, int *proximity_alert_radius, inline_keyboard_markup_t *reply_markup);


// editMessageMedia
//
// Use this method to edit animation, audio, document, photo, or video messages, or to add media to text messages. If a message is part of a message album, then it can be edited only to an audio for audio albums, only to a document for document albums and to a photo or a video otherwise. When an inline message is edited, a new file can't be uploaded; use a previously uploaded file via its file\\_id or specify a URL. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
edit_message_media_response_t*
DefaultAPI_postEditMessageMedia(apiClient_t *apiClient, input_media_t *media, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// editMessageReplyMarkup
//
// Use this method to edit only the reply markup of messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
edit_message_reply_markup_response_t*
DefaultAPI_postEditMessageReplyMarkup(apiClient_t *apiClient, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// editMessageText
//
// Use this method to edit text and [game](https://core.telegram.org/bots/api/#games) messages. On success, if the edited message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Note that business messages that were not sent by the bot and do not contain an inline keyboard can only be edited within **48 hours** from the time they were sent.
//
edit_message_text_response_t*
DefaultAPI_postEditMessageText(apiClient_t *apiClient, char *text, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, inline_keyboard_markup_t *reply_markup);


// editStory
//
// Edits a story previously posted by the bot on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
edit_story_response_t*
DefaultAPI_postEditStory(apiClient_t *apiClient, char *business_connection_id, int *story_id, input_story_content_t *content, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas);


// editUserStarSubscription
//
// Allows the bot to cancel or re-enable extension of a subscription paid in Telegram Stars. Returns *True* on success.
//
edit_user_star_subscription_response_t*
DefaultAPI_postEditUserStarSubscription(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id, int *is_canceled);


// exportChatInviteLink
//
// Use this method to generate a new primary invite link for a chat; any previously generated primary link is revoked. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the new invite link as *String* on success.
//
export_chat_invite_link_response_t*
DefaultAPI_postExportChatInviteLink(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id);


// forwardMessage
//
// Use this method to forward messages of any kind. Service messages and messages with protected content can't be forwarded. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
forward_message_response_t*
DefaultAPI_postForwardMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, forward_message_request_from_chat_id_t *from_chat_id, int *message_id, int *message_thread_id, int *video_start_timestamp, int *disable_notification, int *protect_content);


// forwardMessages
//
// Use this method to forward multiple messages of any kind. If some of the specified messages can't be found or forwarded, they are skipped. Service messages and messages with protected content can't be forwarded. Album grouping is kept for forwarded messages. On success, an array of [MessageId](https://core.telegram.org/bots/api/#messageid) of the sent messages is returned.
//
forward_messages_response_t*
DefaultAPI_postForwardMessages(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, forward_messages_request_from_chat_id_t *from_chat_id, list_t *message_ids, int *message_thread_id, int *disable_notification, int *protect_content);


// getAvailableGifts
//
// Returns the list of gifts that can be sent by the bot to users and channel chats. Requires no parameters. Returns a [Gifts](https://core.telegram.org/bots/api/#gifts) object.
//
get_available_gifts_response_t*
DefaultAPI_postGetAvailableGifts(apiClient_t *apiClient);


// getBusinessAccountGifts
//
// Returns the gifts received and owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [OwnedGifts](https://core.telegram.org/bots/api/#ownedgifts) on success.
//
get_business_account_gifts_response_t*
DefaultAPI_postGetBusinessAccountGifts(apiClient_t *apiClient, char *business_connection_id, int *exclude_unsaved, int *exclude_saved, int *exclude_unlimited, int *exclude_limited, int *exclude_unique, int *sort_by_price, char *offset, int *limit);


// getBusinessAccountStarBalance
//
// Returns the amount of Telegram Stars owned by a managed business account. Requires the *can\\_view\\_gifts\\_and\\_stars* business bot right. Returns [StarAmount](https://core.telegram.org/bots/api/#staramount) on success.
//
get_business_account_star_balance_response_t*
DefaultAPI_postGetBusinessAccountStarBalance(apiClient_t *apiClient, char *business_connection_id);


// getBusinessConnection
//
// Use this method to get information about the connection of the bot with a business account. Returns a [BusinessConnection](https://core.telegram.org/bots/api/#businessconnection) object on success.
//
get_business_connection_response_t*
DefaultAPI_postGetBusinessConnection(apiClient_t *apiClient, char *business_connection_id);


// getChat
//
// Use this method to get up-to-date information about the chat. Returns a [ChatFullInfo](https://core.telegram.org/bots/api/#chatfullinfo) object on success.
//
get_chat_response_t*
DefaultAPI_postGetChat(apiClient_t *apiClient, leave_chat_request_chat_id_t *chat_id);


// getChatAdministrators
//
// Use this method to get a list of administrators in a chat, which aren't bots. Returns an Array of [ChatMember](https://core.telegram.org/bots/api/#chatmember) objects.
//
get_chat_administrators_response_t*
DefaultAPI_postGetChatAdministrators(apiClient_t *apiClient, leave_chat_request_chat_id_t *chat_id);


// getChatMember
//
// Use this method to get information about a member of a chat. The method is only guaranteed to work for other users if the bot is an administrator in the chat. Returns a [ChatMember](https://core.telegram.org/bots/api/#chatmember) object on success.
//
get_chat_member_response_t*
DefaultAPI_postGetChatMember(apiClient_t *apiClient, leave_chat_request_chat_id_t *chat_id, int *user_id);


// getChatMemberCount
//
// Use this method to get the number of members in a chat. Returns *Int* on success.
//
get_chat_member_count_response_t*
DefaultAPI_postGetChatMemberCount(apiClient_t *apiClient, leave_chat_request_chat_id_t *chat_id);


// getChatMenuButton
//
// Use this method to get the current value of the bot's menu button in a private chat, or the default menu button. Returns [MenuButton](https://core.telegram.org/bots/api/#menubutton) on success.
//
get_chat_menu_button_response_t*
DefaultAPI_postGetChatMenuButton(apiClient_t *apiClient, int *chat_id);


// getCustomEmojiStickers
//
// Use this method to get information about custom emoji stickers by their identifiers. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
get_custom_emoji_stickers_response_t*
DefaultAPI_postGetCustomEmojiStickers(apiClient_t *apiClient, list_t *custom_emoji_ids);


// getFile
//
// Use this method to get basic information about a file and prepare it for downloading. For the moment, bots can download files of up to 20MB in size. On success, a [File](https://core.telegram.org/bots/api/#file) object is returned. The file can then be downloaded via the link `https://api.telegram.org/file/bot<token>/<file_path>`, where `<file_path>` is taken from the response. It is guaranteed that the link will be valid for at least 1 hour. When the link expires, a new one can be requested by calling [getFile](https://core.telegram.org/bots/api/#getfile) again.
//
get_file_response_t*
DefaultAPI_postGetFile(apiClient_t *apiClient, char *file_id);


// getForumTopicIconStickers
//
// Use this method to get custom emoji stickers, which can be used as a forum topic icon by any user. Requires no parameters. Returns an Array of [Sticker](https://core.telegram.org/bots/api/#sticker) objects.
//
get_forum_topic_icon_stickers_response_t*
DefaultAPI_postGetForumTopicIconStickers(apiClient_t *apiClient);


// getGameHighScores
//
// Use this method to get data for high score tables. Will return the score of the specified user and several of their neighbors in a game. Returns an Array of [GameHighScore](https://core.telegram.org/bots/api/#gamehighscore) objects.  This method will currently return scores for the target user, plus two of their closest neighbors on each side. Will also return the top three users if the user and their neighbors are not among them. Please note that this behavior is subject to change.
//
get_game_high_scores_response_t*
DefaultAPI_postGetGameHighScores(apiClient_t *apiClient, int *user_id, int *chat_id, int *message_id, char *inline_message_id);


// getMe
//
// A simple method for testing your bot's authentication token. Requires no parameters. Returns basic information about the bot in form of a [User](https://core.telegram.org/bots/api/#user) object.
//
get_me_response_t*
DefaultAPI_postGetMe(apiClient_t *apiClient);


// getMyCommands
//
// Use this method to get the current list of the bot's commands for the given scope and user language. Returns an Array of [BotCommand](https://core.telegram.org/bots/api/#botcommand) objects. If commands aren't set, an empty list is returned.
//
get_my_commands_response_t*
DefaultAPI_postGetMyCommands(apiClient_t *apiClient, bot_command_scope_t *scope, char *language_code);


// getMyDefaultAdministratorRights
//
// Use this method to get the current default administrator rights of the bot. Returns [ChatAdministratorRights](https://core.telegram.org/bots/api/#chatadministratorrights) on success.
//
get_my_default_administrator_rights_response_t*
DefaultAPI_postGetMyDefaultAdministratorRights(apiClient_t *apiClient, int *for_channels);


// getMyDescription
//
// Use this method to get the current bot description for the given user language. Returns [BotDescription](https://core.telegram.org/bots/api/#botdescription) on success.
//
get_my_description_response_t*
DefaultAPI_postGetMyDescription(apiClient_t *apiClient, char *language_code);


// getMyName
//
// Use this method to get the current bot name for the given user language. Returns [BotName](https://core.telegram.org/bots/api/#botname) on success.
//
get_my_name_response_t*
DefaultAPI_postGetMyName(apiClient_t *apiClient, char *language_code);


// getMyShortDescription
//
// Use this method to get the current bot short description for the given user language. Returns [BotShortDescription](https://core.telegram.org/bots/api/#botshortdescription) on success.
//
get_my_short_description_response_t*
DefaultAPI_postGetMyShortDescription(apiClient_t *apiClient, char *language_code);


// getStarTransactions
//
// Returns the bot's Telegram Star transactions in chronological order. On success, returns a [StarTransactions](https://core.telegram.org/bots/api/#startransactions) object.
//
get_star_transactions_response_t*
DefaultAPI_postGetStarTransactions(apiClient_t *apiClient, int *offset, int *limit);


// getStickerSet
//
// Use this method to get a sticker set. On success, a [StickerSet](https://core.telegram.org/bots/api/#stickerset) object is returned.
//
get_sticker_set_response_t*
DefaultAPI_postGetStickerSet(apiClient_t *apiClient, char *name);


// getUpdates
//
// Use this method to receive incoming updates using long polling ([wiki](https://en.wikipedia.org/wiki/Push_technology#Long_polling)). Returns an Array of [Update](https://core.telegram.org/bots/api/#update) objects.
//
get_updates_response_t*
DefaultAPI_postGetUpdates(apiClient_t *apiClient, int *offset, int *limit, int *timeout, list_t *allowed_updates);


// getUserChatBoosts
//
// Use this method to get the list of boosts added to a chat by a user. Requires administrator rights in the chat. Returns a [UserChatBoosts](https://core.telegram.org/bots/api/#userchatboosts) object.
//
get_user_chat_boosts_response_t*
DefaultAPI_postGetUserChatBoosts(apiClient_t *apiClient, get_user_chat_boosts_request_chat_id_t *chat_id, int *user_id);


// getUserProfilePhotos
//
// Use this method to get a list of profile pictures for a user. Returns a [UserProfilePhotos](https://core.telegram.org/bots/api/#userprofilephotos) object.
//
get_user_profile_photos_response_t*
DefaultAPI_postGetUserProfilePhotos(apiClient_t *apiClient, int *user_id, int *offset, int *limit);


// getWebhookInfo
//
// Use this method to get current webhook status. Requires no parameters. On success, returns a [WebhookInfo](https://core.telegram.org/bots/api/#webhookinfo) object. If the bot is using [getUpdates](https://core.telegram.org/bots/api/#getupdates), will return an object with the *url* field empty.
//
get_webhook_info_response_t*
DefaultAPI_postGetWebhookInfo(apiClient_t *apiClient);


// giftPremiumSubscription
//
// Gifts a Telegram Premium subscription to the given user. Returns *True* on success.
//
gift_premium_subscription_response_t*
DefaultAPI_postGiftPremiumSubscription(apiClient_t *apiClient, int *user_id, int *month_count, int *star_count, char *text, char *text_parse_mode, list_t *text_entities);


// hideGeneralForumTopic
//
// Use this method to hide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically closed if it was open. Returns *True* on success.
//
hide_general_forum_topic_response_t*
DefaultAPI_postHideGeneralForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// leaveChat
//
// Use this method for your bot to leave a group, supergroup or channel. Returns *True* on success.
//
leave_chat_response_t*
DefaultAPI_postLeaveChat(apiClient_t *apiClient, leave_chat_request_chat_id_t *chat_id);


// logOut
//
// Use this method to log out from the cloud Bot API server before launching the bot locally. You **must** log out the bot before running it locally, otherwise there is no guarantee that the bot will receive updates. After a successful call, you can immediately log in on a local server, but will not be able to log in back to the cloud Bot API server for 10 minutes. Returns *True* on success. Requires no parameters.
//
log_out_response_t*
DefaultAPI_postLogOut(apiClient_t *apiClient);


// pinChatMessage
//
// Use this method to add a message to the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
pin_chat_message_response_t*
DefaultAPI_postPinChatMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, int *disable_notification);


// postStory
//
// Posts a story on behalf of a managed business account. Requires the *can\\_manage\\_stories* business bot right. Returns [Story](https://core.telegram.org/bots/api/#story) on success.
//
post_story_response_t*
DefaultAPI_postPostStory(apiClient_t *apiClient, char *business_connection_id, input_story_content_t *content, int *active_period, char *caption, char *parse_mode, list_t *caption_entities, list_t *areas, int *post_to_chat_page, int *protect_content);


// promoteChatMember
//
// Use this method to promote or demote a user in a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Pass *False* for all boolean parameters to demote a user. Returns *True* on success.
//
promote_chat_member_response_t*
DefaultAPI_postPromoteChatMember(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *user_id, int *is_anonymous, int *can_manage_chat, int *can_delete_messages, int *can_manage_video_chats, int *can_restrict_members, int *can_promote_members, int *can_change_info, int *can_invite_users, int *can_post_stories, int *can_edit_stories, int *can_delete_stories, int *can_post_messages, int *can_edit_messages, int *can_pin_messages, int *can_manage_topics);


// readBusinessMessage
//
// Marks incoming message as read on behalf of a business account. Requires the *can\\_read\\_messages* business bot right. Returns *True* on success.
//
read_business_message_response_t*
DefaultAPI_postReadBusinessMessage(apiClient_t *apiClient, char *business_connection_id, int *chat_id, int *message_id);


// refundStarPayment
//
// Refunds a successful payment in [Telegram Stars](https://t.me/BotNews/90). Returns *True* on success.
//
refund_star_payment_response_t*
DefaultAPI_postRefundStarPayment(apiClient_t *apiClient, int *user_id, char *telegram_payment_charge_id);


// removeBusinessAccountProfilePhoto
//
// Removes the current profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
remove_business_account_profile_photo_response_t*
DefaultAPI_postRemoveBusinessAccountProfilePhoto(apiClient_t *apiClient, char *business_connection_id, int *is_public);


// removeChatVerification
//
// Removes verification from a chat that is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
remove_chat_verification_response_t*
DefaultAPI_postRemoveChatVerification(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id);


// removeUserVerification
//
// Removes verification from a user who is currently verified [on behalf of the organization](https://telegram.org/verify#third-party-verification) represented by the bot. Returns *True* on success.
//
remove_user_verification_response_t*
DefaultAPI_postRemoveUserVerification(apiClient_t *apiClient, int *user_id);


// reopenForumTopic
//
// Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights, unless it is the creator of the topic. Returns *True* on success.
//
reopen_forum_topic_response_t*
DefaultAPI_postReopenForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *message_thread_id);


// reopenGeneralForumTopic
//
// Use this method to reopen a closed 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. The topic will be automatically unhidden if it was hidden. Returns *True* on success.
//
reopen_general_forum_topic_response_t*
DefaultAPI_postReopenGeneralForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// replaceStickerInSet
//
// Use this method to replace an existing sticker in a sticker set with a new one. The method is equivalent to calling [deleteStickerFromSet](https://core.telegram.org/bots/api/#deletestickerfromset), then [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), then [setStickerPositionInSet](https://core.telegram.org/bots/api/#setstickerpositioninset). Returns *True* on success.
//
replace_sticker_in_set_response_t*
DefaultAPI_postReplaceStickerInSet(apiClient_t *apiClient, int *user_id, char *name, char *old_sticker, input_sticker_t *sticker);


// restrictChatMember
//
// Use this method to restrict a user in a supergroup. The bot must be an administrator in the supergroup for this to work and must have the appropriate administrator rights. Pass *True* for all permissions to lift restrictions from a user. Returns *True* on success.
//
restrict_chat_member_response_t*
DefaultAPI_postRestrictChatMember(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *user_id, chat_permissions_t *permissions, int *use_independent_chat_permissions, int *until_date);


// revokeChatInviteLink
//
// Use this method to revoke an invite link created by the bot. If the primary link is revoked, a new link is automatically generated. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns the revoked invite link as [ChatInviteLink](https://core.telegram.org/bots/api/#chatinvitelink) object.
//
revoke_chat_invite_link_response_t*
DefaultAPI_postRevokeChatInviteLink(apiClient_t *apiClient, revoke_chat_invite_link_request_chat_id_t *chat_id, char *invite_link);


// savePreparedInlineMessage
//
// Stores a message that can be sent by a user of a Mini App. Returns a [PreparedInlineMessage](https://core.telegram.org/bots/api/#preparedinlinemessage) object.
//
save_prepared_inline_message_response_t*
DefaultAPI_postSavePreparedInlineMessage(apiClient_t *apiClient, int *user_id, inline_query_result_t *result, int *allow_user_chats, int *allow_bot_chats, int *allow_group_chats, int *allow_channel_chats);


// sendAnimation
//
// Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send animation files of up to 50 MB in size, this limit may be changed in the future.
//
send_animation_response_t*
DefaultAPI_postSendAnimation(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *animation, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, char *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendAudio
//
// Use this method to send audio files, if you want Telegram clients to display them in the music player. Your audio must be in the .MP3 or .M4A format. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send audio files of up to 50 MB in size, this limit may be changed in the future.  For sending voice messages, use the [sendVoice](https://core.telegram.org/bots/api/#sendvoice) method instead.
//
send_audio_response_t*
DefaultAPI_postSendAudio(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *audio, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, char *performer, char *title, char *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendChatAction
//
// Use this method when you need to tell the user that something is happening on the bot's side. The status is set for 5 seconds or less (when a message arrives from your bot, Telegram clients clear its typing status). Returns *True* on success.  Example: The [ImageBot](https://t.me/imagebot) needs some time to process a request and upload the image. Instead of sending a text message along the lines of “Retrieving image, please wait…”, the bot may use [sendChatAction](https://core.telegram.org/bots/api/#sendchataction) with *action* = *upload\\_photo*. The user will see a “sending photo” status for the bot.  We only recommend using this method when a response from the bot will take a **noticeable** amount of time to arrive.
//
send_chat_action_response_t*
DefaultAPI_postSendChatAction(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, telegram_bot_api_postSendChatAction_action_e action, char *business_connection_id, int *message_thread_id);


// sendContact
//
// Use this method to send phone contacts. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_contact_response_t*
DefaultAPI_postSendContact(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *phone_number, char *first_name, char *business_connection_id, int *message_thread_id, char *last_name, char *vcard, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendDice
//
// Use this method to send an animated emoji that will display a random value. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_dice_response_t*
DefaultAPI_postSendDice(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *business_connection_id, int *message_thread_id, telegram_bot_api_postSendDice_emoji_e emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendDocument
//
// Use this method to send general files. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send files of any type of up to 50 MB in size, this limit may be changed in the future.
//
send_document_response_t*
DefaultAPI_postSendDocument(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *document, char *business_connection_id, int *message_thread_id, char *thumbnail, char *caption, char *parse_mode, list_t *caption_entities, int *disable_content_type_detection, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendGame
//
// Use this method to send a game. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_game_response_t*
DefaultAPI_postSendGame(apiClient_t *apiClient, int *chat_id, char *game_short_name, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup);


// sendGift
//
// Sends a gift to the given user or channel chat. The gift can't be converted to Telegram Stars by the receiver. Returns *True* on success.
//
send_gift_response_t*
DefaultAPI_postSendGift(apiClient_t *apiClient, char *gift_id, int *user_id, send_gift_request_chat_id_t *chat_id, int *pay_for_upgrade, char *text, char *text_parse_mode, list_t *text_entities);


// sendInvoice
//
// Use this method to send invoices. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_invoice_response_t*
DefaultAPI_postSendInvoice(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *title, char *description, char *payload, char *currency, list_t *prices, int *message_thread_id, char *provider_token, int *max_tip_amount, list_t *suggested_tip_amounts, char *start_parameter, char *provider_data, char *photo_url, int *photo_size, int *photo_width, int *photo_height, int *need_name, int *need_phone_number, int *need_email, int *need_shipping_address, int *send_phone_number_to_provider, int *send_email_to_provider, int *is_flexible, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, inline_keyboard_markup_t *reply_markup);


// sendLocation
//
// Use this method to send point on the map. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_location_response_t*
DefaultAPI_postSendLocation(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, double latitude, double longitude, char *business_connection_id, int *message_thread_id, double horizontal_accuracy, int *live_period, int *heading, int *proximity_alert_radius, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendMediaGroup
//
// Use this method to send a group of photos, videos, documents or audios as an album. Documents and audio files can be only grouped in an album with messages of the same type. On success, an array of [Messages](https://core.telegram.org/bots/api/#message) that were sent is returned.
//
send_media_group_response_t*
DefaultAPI_postSendMediaGroup(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, list_t *media, char *business_connection_id, int *message_thread_id, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters);


// sendMessage
//
// Use this method to send text messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_message_response_t*
DefaultAPI_postSendMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *text, char *business_connection_id, int *message_thread_id, char *parse_mode, list_t *entities, link_preview_options_t *link_preview_options, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendPaidMedia
//
// Use this method to send paid media. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_paid_media_response_t*
DefaultAPI_postSendPaidMedia(apiClient_t *apiClient, send_paid_media_request_chat_id_t *chat_id, int *star_count, list_t *media, char *business_connection_id, char *payload, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *disable_notification, int *protect_content, int *allow_paid_broadcast, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendPhoto
//
// Use this method to send photos. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_photo_response_t*
DefaultAPI_postSendPhoto(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *photo, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendPoll
//
// Use this method to send a native poll. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_poll_response_t*
DefaultAPI_postSendPoll(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *question, list_t *options, char *business_connection_id, int *message_thread_id, char *question_parse_mode, list_t *question_entities, int *is_anonymous, telegram_bot_api_postSendPoll_type_e type, int *allows_multiple_answers, int *correct_option_id, char *explanation, char *explanation_parse_mode, list_t *explanation_entities, int *open_period, int *close_date, int *is_closed, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendSticker
//
// Use this method to send static .WEBP, [animated](https://telegram.org/blog/animated-stickers) .TGS, or [video](https://telegram.org/blog/video-stickers-better-reactions) .WEBM stickers. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_sticker_response_t*
DefaultAPI_postSendSticker(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *sticker, char *business_connection_id, int *message_thread_id, char *emoji, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendVenue
//
// Use this method to send information about a venue. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_venue_response_t*
DefaultAPI_postSendVenue(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, double latitude, double longitude, char *title, char *address, char *business_connection_id, int *message_thread_id, char *foursquare_id, char *foursquare_type, char *google_place_id, char *google_place_type, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendVideo
//
// Use this method to send video files, Telegram clients support MPEG4 videos (other formats may be sent as [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send video files of up to 50 MB in size, this limit may be changed in the future.
//
send_video_response_t*
DefaultAPI_postSendVideo(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *video, char *business_connection_id, int *message_thread_id, int *duration, int *width, int *height, char *thumbnail, char *cover, int *start_timestamp, char *caption, char *parse_mode, list_t *caption_entities, int *show_caption_above_media, int *has_spoiler, int *supports_streaming, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendVideoNote
//
// As of [v.4.0](https://telegram.org/blog/video-messages-and-telescope), Telegram clients support rounded square MPEG4 videos of up to 1 minute long. Use this method to send video messages. On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned.
//
send_video_note_response_t*
DefaultAPI_postSendVideoNote(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *video_note, char *business_connection_id, int *message_thread_id, int *duration, int *length, char *thumbnail, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// sendVoice
//
// Use this method to send audio files, if you want Telegram clients to display the file as a playable voice message. For this to work, your audio must be in an .OGG file encoded with OPUS, or in .MP3 format, or in .M4A format (other formats may be sent as [Audio](https://core.telegram.org/bots/api/#audio) or [Document](https://core.telegram.org/bots/api/#document)). On success, the sent [Message](https://core.telegram.org/bots/api/#message) is returned. Bots can currently send voice messages of up to 50 MB in size, this limit may be changed in the future.
//
send_voice_response_t*
DefaultAPI_postSendVoice(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *voice, char *business_connection_id, int *message_thread_id, char *caption, char *parse_mode, list_t *caption_entities, int *duration, int *disable_notification, int *protect_content, int *allow_paid_broadcast, char *message_effect_id, reply_parameters_t *reply_parameters, send_message_request_reply_markup_t *reply_markup);


// setBusinessAccountBio
//
// Changes the bio of a managed business account. Requires the *can\\_change\\_bio* business bot right. Returns *True* on success.
//
set_business_account_bio_response_t*
DefaultAPI_postSetBusinessAccountBio(apiClient_t *apiClient, char *business_connection_id, char *bio);


// setBusinessAccountGiftSettings
//
// Changes the privacy settings pertaining to incoming gifts in a managed business account. Requires the *can\\_change\\_gift\\_settings* business bot right. Returns *True* on success.
//
set_business_account_gift_settings_response_t*
DefaultAPI_postSetBusinessAccountGiftSettings(apiClient_t *apiClient, char *business_connection_id, int *show_gift_button, accepted_gift_types_t *accepted_gift_types);


// setBusinessAccountName
//
// Changes the first and last name of a managed business account. Requires the *can\\_change\\_name* business bot right. Returns *True* on success.
//
set_business_account_name_response_t*
DefaultAPI_postSetBusinessAccountName(apiClient_t *apiClient, char *business_connection_id, char *first_name, char *last_name);


// setBusinessAccountProfilePhoto
//
// Changes the profile photo of a managed business account. Requires the *can\\_edit\\_profile\\_photo* business bot right. Returns *True* on success.
//
set_business_account_profile_photo_response_t*
DefaultAPI_postSetBusinessAccountProfilePhoto(apiClient_t *apiClient, char *business_connection_id, input_profile_photo_t *photo, int *is_public);


// setBusinessAccountUsername
//
// Changes the username of a managed business account. Requires the *can\\_change\\_username* business bot right. Returns *True* on success.
//
set_business_account_username_response_t*
DefaultAPI_postSetBusinessAccountUsername(apiClient_t *apiClient, char *business_connection_id, char *username);


// setChatAdministratorCustomTitle
//
// Use this method to set a custom title for an administrator in a supergroup promoted by the bot. Returns *True* on success.
//
set_chat_administrator_custom_title_response_t*
DefaultAPI_postSetChatAdministratorCustomTitle(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *user_id, char *custom_title);


// setChatDescription
//
// Use this method to change the description of a group, a supergroup or a channel. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
set_chat_description_response_t*
DefaultAPI_postSetChatDescription(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *description);


// setChatMenuButton
//
// Use this method to change the bot's menu button in a private chat, or the default menu button. Returns *True* on success.
//
set_chat_menu_button_response_t*
DefaultAPI_postSetChatMenuButton(apiClient_t *apiClient, int *chat_id, menu_button_t *menu_button);


// setChatPermissions
//
// Use this method to set default chat permissions for all members. The bot must be an administrator in the group or a supergroup for this to work and must have the *can\\_restrict\\_members* administrator rights. Returns *True* on success.
//
set_chat_permissions_response_t*
DefaultAPI_postSetChatPermissions(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, chat_permissions_t *permissions, int *use_independent_chat_permissions);


// setChatPhoto
//
// Use this method to set a new profile photo for the chat. Photos can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
set_chat_photo_response_t*
DefaultAPI_postSetChatPhoto(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, photo);


// setChatStickerSet
//
// Use this method to set a new group sticker set for a supergroup. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Use the field *can\\_set\\_sticker\\_set* optionally returned in [getChat](https://core.telegram.org/bots/api/#getchat) requests to check if the bot can use this method. Returns *True* on success.
//
set_chat_sticker_set_response_t*
DefaultAPI_postSetChatStickerSet(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, char *sticker_set_name);


// setChatTitle
//
// Use this method to change the title of a chat. Titles can't be changed for private chats. The bot must be an administrator in the chat for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
set_chat_title_response_t*
DefaultAPI_postSetChatTitle(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *title);


// setCustomEmojiStickerSetThumbnail
//
// Use this method to set the thumbnail of a custom emoji sticker set. Returns *True* on success.
//
set_custom_emoji_sticker_set_thumbnail_response_t*
DefaultAPI_postSetCustomEmojiStickerSetThumbnail(apiClient_t *apiClient, char *name, char *custom_emoji_id);


// setGameScore
//
// Use this method to set the score of the specified user in a game message. On success, if the message is not an inline message, the [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned. Returns an error, if the new score is not greater than the user's current score in the chat and *force* is *False*.
//
set_game_score_response_t*
DefaultAPI_postSetGameScore(apiClient_t *apiClient, int *user_id, int *score, int *force, int *disable_edit_message, int *chat_id, int *message_id, char *inline_message_id);


// setMessageReaction
//
// Use this method to change the chosen reactions on a message. Service messages of some types can't be reacted to. Automatically forwarded messages from a channel to its discussion group have the same available reactions as messages in the channel. Bots can't use paid reactions. Returns *True* on success.
//
set_message_reaction_response_t*
DefaultAPI_postSetMessageReaction(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *message_id, list_t *reaction, int *is_big);


// setMyCommands
//
// Use this method to change the list of the bot's commands. See [this manual](https://core.telegram.org/bots/features#commands) for more details about bot commands. Returns *True* on success.
//
set_my_commands_response_t*
DefaultAPI_postSetMyCommands(apiClient_t *apiClient, list_t *commands, bot_command_scope_t *scope, char *language_code);


// setMyDefaultAdministratorRights
//
// Use this method to change the default administrator rights requested by the bot when it's added as an administrator to groups or channels. These rights will be suggested to users, but they are free to modify the list before adding the bot. Returns *True* on success.
//
set_my_default_administrator_rights_response_t*
DefaultAPI_postSetMyDefaultAdministratorRights(apiClient_t *apiClient, chat_administrator_rights_t *rights, int *for_channels);


// setMyDescription
//
// Use this method to change the bot's description, which is shown in the chat with the bot if the chat is empty. Returns *True* on success.
//
set_my_description_response_t*
DefaultAPI_postSetMyDescription(apiClient_t *apiClient, char *description, char *language_code);


// setMyName
//
// Use this method to change the bot's name. Returns *True* on success.
//
set_my_name_response_t*
DefaultAPI_postSetMyName(apiClient_t *apiClient, char *name, char *language_code);


// setMyShortDescription
//
// Use this method to change the bot's short description, which is shown on the bot's profile page and is sent together with the link when users share the bot. Returns *True* on success.
//
set_my_short_description_response_t*
DefaultAPI_postSetMyShortDescription(apiClient_t *apiClient, char *short_description, char *language_code);


// setPassportDataErrors
//
// Informs a user that some of the Telegram Passport elements they provided contains errors. The user will not be able to re-submit their Passport to you until the errors are fixed (the contents of the field for which you returned the error must change). Returns *True* on success.  Use this if the data submitted by the user doesn't satisfy the standards your service requires for any reason. For example, if a birthday date seems invalid, a submitted document is blurry, a scan shows evidence of tampering, etc. Supply some details in the error message to make sure the user knows how to correct the issues.
//
set_passport_data_errors_response_t*
DefaultAPI_postSetPassportDataErrors(apiClient_t *apiClient, int *user_id, list_t *errors);


// setStickerEmojiList
//
// Use this method to change the list of emoji assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
set_sticker_emoji_list_response_t*
DefaultAPI_postSetStickerEmojiList(apiClient_t *apiClient, char *sticker, list_t *emoji_list);


// setStickerKeywords
//
// Use this method to change search keywords assigned to a regular or custom emoji sticker. The sticker must belong to a sticker set created by the bot. Returns *True* on success.
//
set_sticker_keywords_response_t*
DefaultAPI_postSetStickerKeywords(apiClient_t *apiClient, char *sticker, list_t *keywords);


// setStickerMaskPosition
//
// Use this method to change the [mask position](https://core.telegram.org/bots/api/#maskposition) of a mask sticker. The sticker must belong to a sticker set that was created by the bot. Returns *True* on success.
//
set_sticker_mask_position_response_t*
DefaultAPI_postSetStickerMaskPosition(apiClient_t *apiClient, char *sticker, mask_position_t *mask_position);


// setStickerPositionInSet
//
// Use this method to move a sticker in a set created by the bot to a specific position. Returns *True* on success.
//
set_sticker_position_in_set_response_t*
DefaultAPI_postSetStickerPositionInSet(apiClient_t *apiClient, char *sticker, int *position);


// setStickerSetThumbnail
//
// Use this method to set the thumbnail of a regular or mask sticker set. The format of the thumbnail file must match the format of the stickers in the set. Returns *True* on success.
//
set_sticker_set_thumbnail_response_t*
DefaultAPI_postSetStickerSetThumbnail(apiClient_t *apiClient, char *name, int *user_id, telegram_bot_api_postSetStickerSetThumbnail_format_e format, char *thumbnail);


// setStickerSetTitle
//
// Use this method to set the title of a created sticker set. Returns *True* on success.
//
set_sticker_set_title_response_t*
DefaultAPI_postSetStickerSetTitle(apiClient_t *apiClient, char *name, char *title);


// setUserEmojiStatus
//
// Changes the emoji status for a given user that previously allowed the bot to manage their emoji status via the Mini App method [requestEmojiStatusAccess](https://core.telegram.org/bots/webapps#initializing-mini-apps). Returns *True* on success.
//
set_user_emoji_status_response_t*
DefaultAPI_postSetUserEmojiStatus(apiClient_t *apiClient, int *user_id, char *emoji_status_custom_emoji_id, int *emoji_status_expiration_date);


// setWebhook
//
// Use this method to specify a URL and receive incoming updates via an outgoing webhook. Whenever there is an update for the bot, we will send an HTTPS POST request to the specified URL, containing a JSON-serialized [Update](https://core.telegram.org/bots/api/#update). In case of an unsuccessful request (a request with response [HTTP status code](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes) different from `2XY`), we will repeat the request and give up after a reasonable amount of attempts. Returns *True* on success.  If you'd like to make sure that the webhook was set by you, you can specify secret data in the parameter *secret\\_token*. If specified, the request will contain a header “X-Telegram-Bot-Api-Secret-Token” with the secret token as content.
//
set_webhook_response_t*
DefaultAPI_postSetWebhook(apiClient_t *apiClient, char *url, certificate, char *ip_address, int *max_connections, list_t *allowed_updates, int *drop_pending_updates, char *secret_token);


// stopMessageLiveLocation
//
// Use this method to stop updating a live location message before *live\\_period* expires. On success, if the message is not an inline message, the edited [Message](https://core.telegram.org/bots/api/#message) is returned, otherwise *True* is returned.
//
stop_message_live_location_response_t*
DefaultAPI_postStopMessageLiveLocation(apiClient_t *apiClient, char *business_connection_id, edit_message_text_request_chat_id_t *chat_id, int *message_id, char *inline_message_id, inline_keyboard_markup_t *reply_markup);


// stopPoll
//
// Use this method to stop a poll which was sent by the bot. On success, the stopped [Poll](https://core.telegram.org/bots/api/#poll) is returned.
//
stop_poll_response_t*
DefaultAPI_postStopPoll(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *message_id, char *business_connection_id, inline_keyboard_markup_t *reply_markup);


// transferBusinessAccountStars
//
// Transfers Telegram Stars from the business account balance to the bot's balance. Requires the *can\\_transfer\\_stars* business bot right. Returns *True* on success.
//
transfer_business_account_stars_response_t*
DefaultAPI_postTransferBusinessAccountStars(apiClient_t *apiClient, char *business_connection_id, int *star_count);


// transferGift
//
// Transfers an owned unique gift to another user. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Requires *can\\_transfer\\_stars* business bot right if the transfer is paid. Returns *True* on success.
//
transfer_gift_response_t*
DefaultAPI_postTransferGift(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *new_owner_chat_id, int *star_count);


// unbanChatMember
//
// Use this method to unban a previously banned user in a supergroup or channel. The user will **not** return to the group or channel automatically, but will be able to join via link, etc. The bot must be an administrator for this to work. By default, this method guarantees that after the call the user is not a member of the chat, but will be able to join it. So if the user is a member of the chat they will also be **removed** from the chat. If you don't want this, use the parameter *only\\_if\\_banned*. Returns *True* on success.
//
unban_chat_member_response_t*
DefaultAPI_postUnbanChatMember(apiClient_t *apiClient, ban_chat_member_request_chat_id_t *chat_id, int *user_id, int *only_if_banned);


// unbanChatSenderChat
//
// Use this method to unban a previously banned channel chat in a supergroup or channel. The bot must be an administrator for this to work and must have the appropriate administrator rights. Returns *True* on success.
//
unban_chat_sender_chat_response_t*
DefaultAPI_postUnbanChatSenderChat(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, int *sender_chat_id);


// unhideGeneralForumTopic
//
// Use this method to unhide the 'General' topic in a forum supergroup chat. The bot must be an administrator in the chat for this to work and must have the *can\\_manage\\_topics* administrator rights. Returns *True* on success.
//
unhide_general_forum_topic_response_t*
DefaultAPI_postUnhideGeneralForumTopic(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// unpinAllChatMessages
//
// Use this method to clear the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
unpin_all_chat_messages_response_t*
DefaultAPI_postUnpinAllChatMessages(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id);


// unpinAllForumTopicMessages
//
// Use this method to clear the list of pinned messages in a forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
unpin_all_forum_topic_messages_response_t*
DefaultAPI_postUnpinAllForumTopicMessages(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id, int *message_thread_id);


// unpinAllGeneralForumTopicMessages
//
// Use this method to clear the list of pinned messages in a General forum topic. The bot must be an administrator in the chat for this to work and must have the *can\\_pin\\_messages* administrator right in the supergroup. Returns *True* on success.
//
unpin_all_general_forum_topic_messages_response_t*
DefaultAPI_postUnpinAllGeneralForumTopicMessages(apiClient_t *apiClient, bot_command_scope_chat_chat_id_t *chat_id);


// unpinChatMessage
//
// Use this method to remove a message from the list of pinned messages in a chat. If the chat is not a private chat, the bot must be an administrator in the chat for this to work and must have the 'can\\_pin\\_messages' administrator right in a supergroup or 'can\\_edit\\_messages' administrator right in a channel. Returns *True* on success.
//
unpin_chat_message_response_t*
DefaultAPI_postUnpinChatMessage(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *business_connection_id, int *message_id);


// upgradeGift
//
// Upgrades a given regular gift to a unique gift. Requires the *can\\_transfer\\_and\\_upgrade\\_gifts* business bot right. Additionally requires the *can\\_transfer\\_stars* business bot right if the upgrade is paid. Returns *True* on success.
//
upgrade_gift_response_t*
DefaultAPI_postUpgradeGift(apiClient_t *apiClient, char *business_connection_id, char *owned_gift_id, int *keep_original_details, int *star_count);


// uploadStickerFile
//
// Use this method to upload a file with a sticker for later use in the [createNewStickerSet](https://core.telegram.org/bots/api/#createnewstickerset), [addStickerToSet](https://core.telegram.org/bots/api/#addstickertoset), or [replaceStickerInSet](https://core.telegram.org/bots/api/#replacestickerinset) methods (the file can be used multiple times). Returns the uploaded [File](https://core.telegram.org/bots/api/#file) on success.
//
upload_sticker_file_response_t*
DefaultAPI_postUploadStickerFile(apiClient_t *apiClient, int *user_id, sticker, telegram_bot_api_postUploadStickerFile_sticker_format_e sticker_format);


// verifyChat
//
// Verifies a chat [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
verify_chat_response_t*
DefaultAPI_postVerifyChat(apiClient_t *apiClient, send_message_request_chat_id_t *chat_id, char *custom_description);


// verifyUser
//
// Verifies a user [on behalf of the organization](https://telegram.org/verify#third-party-verification) which is represented by the bot. Returns *True* on success.
//
verify_user_response_t*
DefaultAPI_postVerifyUser(apiClient_t *apiClient, int *user_id, char *custom_description);


