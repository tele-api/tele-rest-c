# C API client for telegram_bot_api

## Overview

- API version: 9.0.0
- Package version: 
- Build date: 2025-07-01T14:14:32.829734896Z[Etc/UTC]
- Generator version: 7.14.0

## Installation
You'll need the `curl 7.58.0` package in order to build the API. To have code formatted nicely, you also need to have uncrustify version 0.67 or later.

# Prerequisites

## Install the `curl 7.58.0` package with the following command on Linux.
```bash
sudo apt remove curl
wget http://curl.haxx.se/download/curl-7.58.0.tar.gz
tar -xvf curl-7.58.0.tar.gz
cd curl-7.58.0/
./configure
make
sudo make install
```
## Install the `uncrustify 0.67` package with the following command on Linux.
```bash
git clone https://github.com/uncrustify/uncrustify.git
cd uncrustify
mkdir build
cd build
cmake ..
make
sudo make install
```

## Compile the sample:
This will compile the generated code and create a library in the build folder which has to be linked to the codes where API will be used.
```bash
mkdir build
cd build
// To install library to specific location, use following commands
cmake -DCMAKE_INSTALL_PREFIX=/pathtolocation ..
// for normal install use following command
cmake ..
make
sudo make install
```
## How to use compiled library
Considering the test/source code which uses the API is written in main.c(respective api include is written and all objects necessary are defined and created)

To compile main.c(considering the file is present in build folder) use following command
-L - location of the library(not required if cmake with normal installation is performed)
-l library name
```bash
gcc main.c -L. -ltelegram_bot_api -o main
```
Once compiled, you can run it with ``` ./main ```

Note: You don't need to specify includes for models and include folder separately as they are path linked. You just have to import the api.h file in your code, the include linking will work.

## Documentation for API Endpoints

All URIs are relative to *https://api.telegram.org/bot123456:ABC-DEF1234ghIkl-zyx57W2v1u123ew11*

Category | Method | HTTP request | Description
------------ | ------------- | ------------- | -------------
*DefaultAPI* | [**DefaultAPI_addStickerToSetPost**](docs/DefaultAPI.md#DefaultAPI_addStickerToSetPost) | **POST** /addStickerToSet | 
*DefaultAPI* | [**DefaultAPI_answerCallbackQueryPost**](docs/DefaultAPI.md#DefaultAPI_answerCallbackQueryPost) | **POST** /answerCallbackQuery | 
*DefaultAPI* | [**DefaultAPI_answerInlineQueryPost**](docs/DefaultAPI.md#DefaultAPI_answerInlineQueryPost) | **POST** /answerInlineQuery | 
*DefaultAPI* | [**DefaultAPI_answerPreCheckoutQueryPost**](docs/DefaultAPI.md#DefaultAPI_answerPreCheckoutQueryPost) | **POST** /answerPreCheckoutQuery | 
*DefaultAPI* | [**DefaultAPI_answerShippingQueryPost**](docs/DefaultAPI.md#DefaultAPI_answerShippingQueryPost) | **POST** /answerShippingQuery | 
*DefaultAPI* | [**DefaultAPI_answerWebAppQueryPost**](docs/DefaultAPI.md#DefaultAPI_answerWebAppQueryPost) | **POST** /answerWebAppQuery | 
*DefaultAPI* | [**DefaultAPI_approveChatJoinRequestPost**](docs/DefaultAPI.md#DefaultAPI_approveChatJoinRequestPost) | **POST** /approveChatJoinRequest | 
*DefaultAPI* | [**DefaultAPI_banChatMemberPost**](docs/DefaultAPI.md#DefaultAPI_banChatMemberPost) | **POST** /banChatMember | 
*DefaultAPI* | [**DefaultAPI_banChatSenderChatPost**](docs/DefaultAPI.md#DefaultAPI_banChatSenderChatPost) | **POST** /banChatSenderChat | 
*DefaultAPI* | [**DefaultAPI_closeForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_closeForumTopicPost) | **POST** /closeForumTopic | 
*DefaultAPI* | [**DefaultAPI_closeGeneralForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_closeGeneralForumTopicPost) | **POST** /closeGeneralForumTopic | 
*DefaultAPI* | [**DefaultAPI_closePost**](docs/DefaultAPI.md#DefaultAPI_closePost) | **POST** /close | 
*DefaultAPI* | [**DefaultAPI_convertGiftToStarsPost**](docs/DefaultAPI.md#DefaultAPI_convertGiftToStarsPost) | **POST** /convertGiftToStars | 
*DefaultAPI* | [**DefaultAPI_copyMessagePost**](docs/DefaultAPI.md#DefaultAPI_copyMessagePost) | **POST** /copyMessage | 
*DefaultAPI* | [**DefaultAPI_copyMessagesPost**](docs/DefaultAPI.md#DefaultAPI_copyMessagesPost) | **POST** /copyMessages | 
*DefaultAPI* | [**DefaultAPI_createChatInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_createChatInviteLinkPost) | **POST** /createChatInviteLink | 
*DefaultAPI* | [**DefaultAPI_createChatSubscriptionInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_createChatSubscriptionInviteLinkPost) | **POST** /createChatSubscriptionInviteLink | 
*DefaultAPI* | [**DefaultAPI_createForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_createForumTopicPost) | **POST** /createForumTopic | 
*DefaultAPI* | [**DefaultAPI_createInvoiceLinkPost**](docs/DefaultAPI.md#DefaultAPI_createInvoiceLinkPost) | **POST** /createInvoiceLink | 
*DefaultAPI* | [**DefaultAPI_createNewStickerSetPost**](docs/DefaultAPI.md#DefaultAPI_createNewStickerSetPost) | **POST** /createNewStickerSet | 
*DefaultAPI* | [**DefaultAPI_declineChatJoinRequestPost**](docs/DefaultAPI.md#DefaultAPI_declineChatJoinRequestPost) | **POST** /declineChatJoinRequest | 
*DefaultAPI* | [**DefaultAPI_deleteBusinessMessagesPost**](docs/DefaultAPI.md#DefaultAPI_deleteBusinessMessagesPost) | **POST** /deleteBusinessMessages | 
*DefaultAPI* | [**DefaultAPI_deleteChatPhotoPost**](docs/DefaultAPI.md#DefaultAPI_deleteChatPhotoPost) | **POST** /deleteChatPhoto | 
*DefaultAPI* | [**DefaultAPI_deleteChatStickerSetPost**](docs/DefaultAPI.md#DefaultAPI_deleteChatStickerSetPost) | **POST** /deleteChatStickerSet | 
*DefaultAPI* | [**DefaultAPI_deleteForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_deleteForumTopicPost) | **POST** /deleteForumTopic | 
*DefaultAPI* | [**DefaultAPI_deleteMessagePost**](docs/DefaultAPI.md#DefaultAPI_deleteMessagePost) | **POST** /deleteMessage | 
*DefaultAPI* | [**DefaultAPI_deleteMessagesPost**](docs/DefaultAPI.md#DefaultAPI_deleteMessagesPost) | **POST** /deleteMessages | 
*DefaultAPI* | [**DefaultAPI_deleteMyCommandsPost**](docs/DefaultAPI.md#DefaultAPI_deleteMyCommandsPost) | **POST** /deleteMyCommands | 
*DefaultAPI* | [**DefaultAPI_deleteStickerFromSetPost**](docs/DefaultAPI.md#DefaultAPI_deleteStickerFromSetPost) | **POST** /deleteStickerFromSet | 
*DefaultAPI* | [**DefaultAPI_deleteStickerSetPost**](docs/DefaultAPI.md#DefaultAPI_deleteStickerSetPost) | **POST** /deleteStickerSet | 
*DefaultAPI* | [**DefaultAPI_deleteStoryPost**](docs/DefaultAPI.md#DefaultAPI_deleteStoryPost) | **POST** /deleteStory | 
*DefaultAPI* | [**DefaultAPI_deleteWebhookPost**](docs/DefaultAPI.md#DefaultAPI_deleteWebhookPost) | **POST** /deleteWebhook | 
*DefaultAPI* | [**DefaultAPI_editChatInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_editChatInviteLinkPost) | **POST** /editChatInviteLink | 
*DefaultAPI* | [**DefaultAPI_editChatSubscriptionInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_editChatSubscriptionInviteLinkPost) | **POST** /editChatSubscriptionInviteLink | 
*DefaultAPI* | [**DefaultAPI_editForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_editForumTopicPost) | **POST** /editForumTopic | 
*DefaultAPI* | [**DefaultAPI_editGeneralForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_editGeneralForumTopicPost) | **POST** /editGeneralForumTopic | 
*DefaultAPI* | [**DefaultAPI_editMessageCaptionPost**](docs/DefaultAPI.md#DefaultAPI_editMessageCaptionPost) | **POST** /editMessageCaption | 
*DefaultAPI* | [**DefaultAPI_editMessageLiveLocationPost**](docs/DefaultAPI.md#DefaultAPI_editMessageLiveLocationPost) | **POST** /editMessageLiveLocation | 
*DefaultAPI* | [**DefaultAPI_editMessageMediaPost**](docs/DefaultAPI.md#DefaultAPI_editMessageMediaPost) | **POST** /editMessageMedia | 
*DefaultAPI* | [**DefaultAPI_editMessageReplyMarkupPost**](docs/DefaultAPI.md#DefaultAPI_editMessageReplyMarkupPost) | **POST** /editMessageReplyMarkup | 
*DefaultAPI* | [**DefaultAPI_editMessageTextPost**](docs/DefaultAPI.md#DefaultAPI_editMessageTextPost) | **POST** /editMessageText | 
*DefaultAPI* | [**DefaultAPI_editStoryPost**](docs/DefaultAPI.md#DefaultAPI_editStoryPost) | **POST** /editStory | 
*DefaultAPI* | [**DefaultAPI_editUserStarSubscriptionPost**](docs/DefaultAPI.md#DefaultAPI_editUserStarSubscriptionPost) | **POST** /editUserStarSubscription | 
*DefaultAPI* | [**DefaultAPI_exportChatInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_exportChatInviteLinkPost) | **POST** /exportChatInviteLink | 
*DefaultAPI* | [**DefaultAPI_forwardMessagePost**](docs/DefaultAPI.md#DefaultAPI_forwardMessagePost) | **POST** /forwardMessage | 
*DefaultAPI* | [**DefaultAPI_forwardMessagesPost**](docs/DefaultAPI.md#DefaultAPI_forwardMessagesPost) | **POST** /forwardMessages | 
*DefaultAPI* | [**DefaultAPI_getAvailableGiftsPost**](docs/DefaultAPI.md#DefaultAPI_getAvailableGiftsPost) | **POST** /getAvailableGifts | 
*DefaultAPI* | [**DefaultAPI_getBusinessAccountGiftsPost**](docs/DefaultAPI.md#DefaultAPI_getBusinessAccountGiftsPost) | **POST** /getBusinessAccountGifts | 
*DefaultAPI* | [**DefaultAPI_getBusinessAccountStarBalancePost**](docs/DefaultAPI.md#DefaultAPI_getBusinessAccountStarBalancePost) | **POST** /getBusinessAccountStarBalance | 
*DefaultAPI* | [**DefaultAPI_getBusinessConnectionPost**](docs/DefaultAPI.md#DefaultAPI_getBusinessConnectionPost) | **POST** /getBusinessConnection | 
*DefaultAPI* | [**DefaultAPI_getChatAdministratorsPost**](docs/DefaultAPI.md#DefaultAPI_getChatAdministratorsPost) | **POST** /getChatAdministrators | 
*DefaultAPI* | [**DefaultAPI_getChatMemberCountPost**](docs/DefaultAPI.md#DefaultAPI_getChatMemberCountPost) | **POST** /getChatMemberCount | 
*DefaultAPI* | [**DefaultAPI_getChatMemberPost**](docs/DefaultAPI.md#DefaultAPI_getChatMemberPost) | **POST** /getChatMember | 
*DefaultAPI* | [**DefaultAPI_getChatMenuButtonPost**](docs/DefaultAPI.md#DefaultAPI_getChatMenuButtonPost) | **POST** /getChatMenuButton | 
*DefaultAPI* | [**DefaultAPI_getChatPost**](docs/DefaultAPI.md#DefaultAPI_getChatPost) | **POST** /getChat | 
*DefaultAPI* | [**DefaultAPI_getCustomEmojiStickersPost**](docs/DefaultAPI.md#DefaultAPI_getCustomEmojiStickersPost) | **POST** /getCustomEmojiStickers | 
*DefaultAPI* | [**DefaultAPI_getFilePost**](docs/DefaultAPI.md#DefaultAPI_getFilePost) | **POST** /getFile | 
*DefaultAPI* | [**DefaultAPI_getForumTopicIconStickersPost**](docs/DefaultAPI.md#DefaultAPI_getForumTopicIconStickersPost) | **POST** /getForumTopicIconStickers | 
*DefaultAPI* | [**DefaultAPI_getGameHighScoresPost**](docs/DefaultAPI.md#DefaultAPI_getGameHighScoresPost) | **POST** /getGameHighScores | 
*DefaultAPI* | [**DefaultAPI_getMePost**](docs/DefaultAPI.md#DefaultAPI_getMePost) | **POST** /getMe | 
*DefaultAPI* | [**DefaultAPI_getMyCommandsPost**](docs/DefaultAPI.md#DefaultAPI_getMyCommandsPost) | **POST** /getMyCommands | 
*DefaultAPI* | [**DefaultAPI_getMyDefaultAdministratorRightsPost**](docs/DefaultAPI.md#DefaultAPI_getMyDefaultAdministratorRightsPost) | **POST** /getMyDefaultAdministratorRights | 
*DefaultAPI* | [**DefaultAPI_getMyDescriptionPost**](docs/DefaultAPI.md#DefaultAPI_getMyDescriptionPost) | **POST** /getMyDescription | 
*DefaultAPI* | [**DefaultAPI_getMyNamePost**](docs/DefaultAPI.md#DefaultAPI_getMyNamePost) | **POST** /getMyName | 
*DefaultAPI* | [**DefaultAPI_getMyShortDescriptionPost**](docs/DefaultAPI.md#DefaultAPI_getMyShortDescriptionPost) | **POST** /getMyShortDescription | 
*DefaultAPI* | [**DefaultAPI_getStarTransactionsPost**](docs/DefaultAPI.md#DefaultAPI_getStarTransactionsPost) | **POST** /getStarTransactions | 
*DefaultAPI* | [**DefaultAPI_getStickerSetPost**](docs/DefaultAPI.md#DefaultAPI_getStickerSetPost) | **POST** /getStickerSet | 
*DefaultAPI* | [**DefaultAPI_getUpdatesPost**](docs/DefaultAPI.md#DefaultAPI_getUpdatesPost) | **POST** /getUpdates | 
*DefaultAPI* | [**DefaultAPI_getUserChatBoostsPost**](docs/DefaultAPI.md#DefaultAPI_getUserChatBoostsPost) | **POST** /getUserChatBoosts | 
*DefaultAPI* | [**DefaultAPI_getUserProfilePhotosPost**](docs/DefaultAPI.md#DefaultAPI_getUserProfilePhotosPost) | **POST** /getUserProfilePhotos | 
*DefaultAPI* | [**DefaultAPI_getWebhookInfoPost**](docs/DefaultAPI.md#DefaultAPI_getWebhookInfoPost) | **POST** /getWebhookInfo | 
*DefaultAPI* | [**DefaultAPI_giftPremiumSubscriptionPost**](docs/DefaultAPI.md#DefaultAPI_giftPremiumSubscriptionPost) | **POST** /giftPremiumSubscription | 
*DefaultAPI* | [**DefaultAPI_hideGeneralForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_hideGeneralForumTopicPost) | **POST** /hideGeneralForumTopic | 
*DefaultAPI* | [**DefaultAPI_leaveChatPost**](docs/DefaultAPI.md#DefaultAPI_leaveChatPost) | **POST** /leaveChat | 
*DefaultAPI* | [**DefaultAPI_logOutPost**](docs/DefaultAPI.md#DefaultAPI_logOutPost) | **POST** /logOut | 
*DefaultAPI* | [**DefaultAPI_pinChatMessagePost**](docs/DefaultAPI.md#DefaultAPI_pinChatMessagePost) | **POST** /pinChatMessage | 
*DefaultAPI* | [**DefaultAPI_postStoryPost**](docs/DefaultAPI.md#DefaultAPI_postStoryPost) | **POST** /postStory | 
*DefaultAPI* | [**DefaultAPI_promoteChatMemberPost**](docs/DefaultAPI.md#DefaultAPI_promoteChatMemberPost) | **POST** /promoteChatMember | 
*DefaultAPI* | [**DefaultAPI_readBusinessMessagePost**](docs/DefaultAPI.md#DefaultAPI_readBusinessMessagePost) | **POST** /readBusinessMessage | 
*DefaultAPI* | [**DefaultAPI_refundStarPaymentPost**](docs/DefaultAPI.md#DefaultAPI_refundStarPaymentPost) | **POST** /refundStarPayment | 
*DefaultAPI* | [**DefaultAPI_removeBusinessAccountProfilePhotoPost**](docs/DefaultAPI.md#DefaultAPI_removeBusinessAccountProfilePhotoPost) | **POST** /removeBusinessAccountProfilePhoto | 
*DefaultAPI* | [**DefaultAPI_removeChatVerificationPost**](docs/DefaultAPI.md#DefaultAPI_removeChatVerificationPost) | **POST** /removeChatVerification | 
*DefaultAPI* | [**DefaultAPI_removeUserVerificationPost**](docs/DefaultAPI.md#DefaultAPI_removeUserVerificationPost) | **POST** /removeUserVerification | 
*DefaultAPI* | [**DefaultAPI_reopenForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_reopenForumTopicPost) | **POST** /reopenForumTopic | 
*DefaultAPI* | [**DefaultAPI_reopenGeneralForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_reopenGeneralForumTopicPost) | **POST** /reopenGeneralForumTopic | 
*DefaultAPI* | [**DefaultAPI_replaceStickerInSetPost**](docs/DefaultAPI.md#DefaultAPI_replaceStickerInSetPost) | **POST** /replaceStickerInSet | 
*DefaultAPI* | [**DefaultAPI_restrictChatMemberPost**](docs/DefaultAPI.md#DefaultAPI_restrictChatMemberPost) | **POST** /restrictChatMember | 
*DefaultAPI* | [**DefaultAPI_revokeChatInviteLinkPost**](docs/DefaultAPI.md#DefaultAPI_revokeChatInviteLinkPost) | **POST** /revokeChatInviteLink | 
*DefaultAPI* | [**DefaultAPI_savePreparedInlineMessagePost**](docs/DefaultAPI.md#DefaultAPI_savePreparedInlineMessagePost) | **POST** /savePreparedInlineMessage | 
*DefaultAPI* | [**DefaultAPI_sendAnimationPost**](docs/DefaultAPI.md#DefaultAPI_sendAnimationPost) | **POST** /sendAnimation | 
*DefaultAPI* | [**DefaultAPI_sendAudioPost**](docs/DefaultAPI.md#DefaultAPI_sendAudioPost) | **POST** /sendAudio | 
*DefaultAPI* | [**DefaultAPI_sendChatActionPost**](docs/DefaultAPI.md#DefaultAPI_sendChatActionPost) | **POST** /sendChatAction | 
*DefaultAPI* | [**DefaultAPI_sendContactPost**](docs/DefaultAPI.md#DefaultAPI_sendContactPost) | **POST** /sendContact | 
*DefaultAPI* | [**DefaultAPI_sendDicePost**](docs/DefaultAPI.md#DefaultAPI_sendDicePost) | **POST** /sendDice | 
*DefaultAPI* | [**DefaultAPI_sendDocumentPost**](docs/DefaultAPI.md#DefaultAPI_sendDocumentPost) | **POST** /sendDocument | 
*DefaultAPI* | [**DefaultAPI_sendGamePost**](docs/DefaultAPI.md#DefaultAPI_sendGamePost) | **POST** /sendGame | 
*DefaultAPI* | [**DefaultAPI_sendGiftPost**](docs/DefaultAPI.md#DefaultAPI_sendGiftPost) | **POST** /sendGift | 
*DefaultAPI* | [**DefaultAPI_sendInvoicePost**](docs/DefaultAPI.md#DefaultAPI_sendInvoicePost) | **POST** /sendInvoice | 
*DefaultAPI* | [**DefaultAPI_sendLocationPost**](docs/DefaultAPI.md#DefaultAPI_sendLocationPost) | **POST** /sendLocation | 
*DefaultAPI* | [**DefaultAPI_sendMediaGroupPost**](docs/DefaultAPI.md#DefaultAPI_sendMediaGroupPost) | **POST** /sendMediaGroup | 
*DefaultAPI* | [**DefaultAPI_sendMessagePost**](docs/DefaultAPI.md#DefaultAPI_sendMessagePost) | **POST** /sendMessage | 
*DefaultAPI* | [**DefaultAPI_sendPaidMediaPost**](docs/DefaultAPI.md#DefaultAPI_sendPaidMediaPost) | **POST** /sendPaidMedia | 
*DefaultAPI* | [**DefaultAPI_sendPhotoPost**](docs/DefaultAPI.md#DefaultAPI_sendPhotoPost) | **POST** /sendPhoto | 
*DefaultAPI* | [**DefaultAPI_sendPollPost**](docs/DefaultAPI.md#DefaultAPI_sendPollPost) | **POST** /sendPoll | 
*DefaultAPI* | [**DefaultAPI_sendStickerPost**](docs/DefaultAPI.md#DefaultAPI_sendStickerPost) | **POST** /sendSticker | 
*DefaultAPI* | [**DefaultAPI_sendVenuePost**](docs/DefaultAPI.md#DefaultAPI_sendVenuePost) | **POST** /sendVenue | 
*DefaultAPI* | [**DefaultAPI_sendVideoNotePost**](docs/DefaultAPI.md#DefaultAPI_sendVideoNotePost) | **POST** /sendVideoNote | 
*DefaultAPI* | [**DefaultAPI_sendVideoPost**](docs/DefaultAPI.md#DefaultAPI_sendVideoPost) | **POST** /sendVideo | 
*DefaultAPI* | [**DefaultAPI_sendVoicePost**](docs/DefaultAPI.md#DefaultAPI_sendVoicePost) | **POST** /sendVoice | 
*DefaultAPI* | [**DefaultAPI_setBusinessAccountBioPost**](docs/DefaultAPI.md#DefaultAPI_setBusinessAccountBioPost) | **POST** /setBusinessAccountBio | 
*DefaultAPI* | [**DefaultAPI_setBusinessAccountGiftSettingsPost**](docs/DefaultAPI.md#DefaultAPI_setBusinessAccountGiftSettingsPost) | **POST** /setBusinessAccountGiftSettings | 
*DefaultAPI* | [**DefaultAPI_setBusinessAccountNamePost**](docs/DefaultAPI.md#DefaultAPI_setBusinessAccountNamePost) | **POST** /setBusinessAccountName | 
*DefaultAPI* | [**DefaultAPI_setBusinessAccountProfilePhotoPost**](docs/DefaultAPI.md#DefaultAPI_setBusinessAccountProfilePhotoPost) | **POST** /setBusinessAccountProfilePhoto | 
*DefaultAPI* | [**DefaultAPI_setBusinessAccountUsernamePost**](docs/DefaultAPI.md#DefaultAPI_setBusinessAccountUsernamePost) | **POST** /setBusinessAccountUsername | 
*DefaultAPI* | [**DefaultAPI_setChatAdministratorCustomTitlePost**](docs/DefaultAPI.md#DefaultAPI_setChatAdministratorCustomTitlePost) | **POST** /setChatAdministratorCustomTitle | 
*DefaultAPI* | [**DefaultAPI_setChatDescriptionPost**](docs/DefaultAPI.md#DefaultAPI_setChatDescriptionPost) | **POST** /setChatDescription | 
*DefaultAPI* | [**DefaultAPI_setChatMenuButtonPost**](docs/DefaultAPI.md#DefaultAPI_setChatMenuButtonPost) | **POST** /setChatMenuButton | 
*DefaultAPI* | [**DefaultAPI_setChatPermissionsPost**](docs/DefaultAPI.md#DefaultAPI_setChatPermissionsPost) | **POST** /setChatPermissions | 
*DefaultAPI* | [**DefaultAPI_setChatPhotoPost**](docs/DefaultAPI.md#DefaultAPI_setChatPhotoPost) | **POST** /setChatPhoto | 
*DefaultAPI* | [**DefaultAPI_setChatStickerSetPost**](docs/DefaultAPI.md#DefaultAPI_setChatStickerSetPost) | **POST** /setChatStickerSet | 
*DefaultAPI* | [**DefaultAPI_setChatTitlePost**](docs/DefaultAPI.md#DefaultAPI_setChatTitlePost) | **POST** /setChatTitle | 
*DefaultAPI* | [**DefaultAPI_setCustomEmojiStickerSetThumbnailPost**](docs/DefaultAPI.md#DefaultAPI_setCustomEmojiStickerSetThumbnailPost) | **POST** /setCustomEmojiStickerSetThumbnail | 
*DefaultAPI* | [**DefaultAPI_setGameScorePost**](docs/DefaultAPI.md#DefaultAPI_setGameScorePost) | **POST** /setGameScore | 
*DefaultAPI* | [**DefaultAPI_setMessageReactionPost**](docs/DefaultAPI.md#DefaultAPI_setMessageReactionPost) | **POST** /setMessageReaction | 
*DefaultAPI* | [**DefaultAPI_setMyCommandsPost**](docs/DefaultAPI.md#DefaultAPI_setMyCommandsPost) | **POST** /setMyCommands | 
*DefaultAPI* | [**DefaultAPI_setMyDefaultAdministratorRightsPost**](docs/DefaultAPI.md#DefaultAPI_setMyDefaultAdministratorRightsPost) | **POST** /setMyDefaultAdministratorRights | 
*DefaultAPI* | [**DefaultAPI_setMyDescriptionPost**](docs/DefaultAPI.md#DefaultAPI_setMyDescriptionPost) | **POST** /setMyDescription | 
*DefaultAPI* | [**DefaultAPI_setMyNamePost**](docs/DefaultAPI.md#DefaultAPI_setMyNamePost) | **POST** /setMyName | 
*DefaultAPI* | [**DefaultAPI_setMyShortDescriptionPost**](docs/DefaultAPI.md#DefaultAPI_setMyShortDescriptionPost) | **POST** /setMyShortDescription | 
*DefaultAPI* | [**DefaultAPI_setPassportDataErrorsPost**](docs/DefaultAPI.md#DefaultAPI_setPassportDataErrorsPost) | **POST** /setPassportDataErrors | 
*DefaultAPI* | [**DefaultAPI_setStickerEmojiListPost**](docs/DefaultAPI.md#DefaultAPI_setStickerEmojiListPost) | **POST** /setStickerEmojiList | 
*DefaultAPI* | [**DefaultAPI_setStickerKeywordsPost**](docs/DefaultAPI.md#DefaultAPI_setStickerKeywordsPost) | **POST** /setStickerKeywords | 
*DefaultAPI* | [**DefaultAPI_setStickerMaskPositionPost**](docs/DefaultAPI.md#DefaultAPI_setStickerMaskPositionPost) | **POST** /setStickerMaskPosition | 
*DefaultAPI* | [**DefaultAPI_setStickerPositionInSetPost**](docs/DefaultAPI.md#DefaultAPI_setStickerPositionInSetPost) | **POST** /setStickerPositionInSet | 
*DefaultAPI* | [**DefaultAPI_setStickerSetThumbnailPost**](docs/DefaultAPI.md#DefaultAPI_setStickerSetThumbnailPost) | **POST** /setStickerSetThumbnail | 
*DefaultAPI* | [**DefaultAPI_setStickerSetTitlePost**](docs/DefaultAPI.md#DefaultAPI_setStickerSetTitlePost) | **POST** /setStickerSetTitle | 
*DefaultAPI* | [**DefaultAPI_setUserEmojiStatusPost**](docs/DefaultAPI.md#DefaultAPI_setUserEmojiStatusPost) | **POST** /setUserEmojiStatus | 
*DefaultAPI* | [**DefaultAPI_setWebhookPost**](docs/DefaultAPI.md#DefaultAPI_setWebhookPost) | **POST** /setWebhook | 
*DefaultAPI* | [**DefaultAPI_stopMessageLiveLocationPost**](docs/DefaultAPI.md#DefaultAPI_stopMessageLiveLocationPost) | **POST** /stopMessageLiveLocation | 
*DefaultAPI* | [**DefaultAPI_stopPollPost**](docs/DefaultAPI.md#DefaultAPI_stopPollPost) | **POST** /stopPoll | 
*DefaultAPI* | [**DefaultAPI_transferBusinessAccountStarsPost**](docs/DefaultAPI.md#DefaultAPI_transferBusinessAccountStarsPost) | **POST** /transferBusinessAccountStars | 
*DefaultAPI* | [**DefaultAPI_transferGiftPost**](docs/DefaultAPI.md#DefaultAPI_transferGiftPost) | **POST** /transferGift | 
*DefaultAPI* | [**DefaultAPI_unbanChatMemberPost**](docs/DefaultAPI.md#DefaultAPI_unbanChatMemberPost) | **POST** /unbanChatMember | 
*DefaultAPI* | [**DefaultAPI_unbanChatSenderChatPost**](docs/DefaultAPI.md#DefaultAPI_unbanChatSenderChatPost) | **POST** /unbanChatSenderChat | 
*DefaultAPI* | [**DefaultAPI_unhideGeneralForumTopicPost**](docs/DefaultAPI.md#DefaultAPI_unhideGeneralForumTopicPost) | **POST** /unhideGeneralForumTopic | 
*DefaultAPI* | [**DefaultAPI_unpinAllChatMessagesPost**](docs/DefaultAPI.md#DefaultAPI_unpinAllChatMessagesPost) | **POST** /unpinAllChatMessages | 
*DefaultAPI* | [**DefaultAPI_unpinAllForumTopicMessagesPost**](docs/DefaultAPI.md#DefaultAPI_unpinAllForumTopicMessagesPost) | **POST** /unpinAllForumTopicMessages | 
*DefaultAPI* | [**DefaultAPI_unpinAllGeneralForumTopicMessagesPost**](docs/DefaultAPI.md#DefaultAPI_unpinAllGeneralForumTopicMessagesPost) | **POST** /unpinAllGeneralForumTopicMessages | 
*DefaultAPI* | [**DefaultAPI_unpinChatMessagePost**](docs/DefaultAPI.md#DefaultAPI_unpinChatMessagePost) | **POST** /unpinChatMessage | 
*DefaultAPI* | [**DefaultAPI_upgradeGiftPost**](docs/DefaultAPI.md#DefaultAPI_upgradeGiftPost) | **POST** /upgradeGift | 
*DefaultAPI* | [**DefaultAPI_uploadStickerFilePost**](docs/DefaultAPI.md#DefaultAPI_uploadStickerFilePost) | **POST** /uploadStickerFile | 
*DefaultAPI* | [**DefaultAPI_verifyChatPost**](docs/DefaultAPI.md#DefaultAPI_verifyChatPost) | **POST** /verifyChat | 
*DefaultAPI* | [**DefaultAPI_verifyUserPost**](docs/DefaultAPI.md#DefaultAPI_verifyUserPost) | **POST** /verifyUser | 


## Documentation for Models

 - [_answer_callback_query_post_request_t](docs/_answer_callback_query_post_request.md)
 - [_answer_inline_query_post_request_t](docs/_answer_inline_query_post_request.md)
 - [_answer_pre_checkout_query_post_request_t](docs/_answer_pre_checkout_query_post_request.md)
 - [_answer_shipping_query_post_request_t](docs/_answer_shipping_query_post_request.md)
 - [_answer_web_app_query_post_200_response_t](docs/_answer_web_app_query_post_200_response.md)
 - [_answer_web_app_query_post_request_t](docs/_answer_web_app_query_post_request.md)
 - [_approve_chat_join_request_post_request_t](docs/_approve_chat_join_request_post_request.md)
 - [_ban_chat_member_post_request_t](docs/_ban_chat_member_post_request.md)
 - [_ban_chat_member_post_request_chat_id_t](docs/_ban_chat_member_post_request_chat_id.md)
 - [_ban_chat_sender_chat_post_request_t](docs/_ban_chat_sender_chat_post_request.md)
 - [_close_forum_topic_post_request_t](docs/_close_forum_topic_post_request.md)
 - [_convert_gift_to_stars_post_request_t](docs/_convert_gift_to_stars_post_request.md)
 - [_copy_message_post_200_response_t](docs/_copy_message_post_200_response.md)
 - [_copy_message_post_request_t](docs/_copy_message_post_request.md)
 - [_copy_messages_post_request_t](docs/_copy_messages_post_request.md)
 - [_create_chat_invite_link_post_200_response_t](docs/_create_chat_invite_link_post_200_response.md)
 - [_create_chat_invite_link_post_request_t](docs/_create_chat_invite_link_post_request.md)
 - [_create_chat_subscription_invite_link_post_request_t](docs/_create_chat_subscription_invite_link_post_request.md)
 - [_create_chat_subscription_invite_link_post_request_chat_id_t](docs/_create_chat_subscription_invite_link_post_request_chat_id.md)
 - [_create_forum_topic_post_200_response_t](docs/_create_forum_topic_post_200_response.md)
 - [_create_forum_topic_post_request_t](docs/_create_forum_topic_post_request.md)
 - [_create_invoice_link_post_request_t](docs/_create_invoice_link_post_request.md)
 - [_delete_business_messages_post_request_t](docs/_delete_business_messages_post_request.md)
 - [_delete_chat_sticker_set_post_request_t](docs/_delete_chat_sticker_set_post_request.md)
 - [_delete_message_post_request_t](docs/_delete_message_post_request.md)
 - [_delete_messages_post_request_t](docs/_delete_messages_post_request.md)
 - [_delete_my_commands_post_request_t](docs/_delete_my_commands_post_request.md)
 - [_delete_sticker_from_set_post_request_t](docs/_delete_sticker_from_set_post_request.md)
 - [_delete_sticker_set_post_request_t](docs/_delete_sticker_set_post_request.md)
 - [_delete_story_post_request_t](docs/_delete_story_post_request.md)
 - [_delete_webhook_post_request_t](docs/_delete_webhook_post_request.md)
 - [_edit_chat_invite_link_post_request_t](docs/_edit_chat_invite_link_post_request.md)
 - [_edit_chat_subscription_invite_link_post_request_t](docs/_edit_chat_subscription_invite_link_post_request.md)
 - [_edit_forum_topic_post_request_t](docs/_edit_forum_topic_post_request.md)
 - [_edit_general_forum_topic_post_request_t](docs/_edit_general_forum_topic_post_request.md)
 - [_edit_message_caption_post_request_t](docs/_edit_message_caption_post_request.md)
 - [_edit_message_live_location_post_request_t](docs/_edit_message_live_location_post_request.md)
 - [_edit_message_reply_markup_post_request_t](docs/_edit_message_reply_markup_post_request.md)
 - [_edit_message_text_post_200_response_t](docs/_edit_message_text_post_200_response.md)
 - [_edit_message_text_post_200_response_result_t](docs/_edit_message_text_post_200_response_result.md)
 - [_edit_message_text_post_request_t](docs/_edit_message_text_post_request.md)
 - [_edit_message_text_post_request_chat_id_t](docs/_edit_message_text_post_request_chat_id.md)
 - [_edit_user_star_subscription_post_request_t](docs/_edit_user_star_subscription_post_request.md)
 - [_export_chat_invite_link_post_200_response_t](docs/_export_chat_invite_link_post_200_response.md)
 - [_export_chat_invite_link_post_request_t](docs/_export_chat_invite_link_post_request.md)
 - [_forward_message_post_request_t](docs/_forward_message_post_request.md)
 - [_forward_message_post_request_from_chat_id_t](docs/_forward_message_post_request_from_chat_id.md)
 - [_forward_messages_post_200_response_t](docs/_forward_messages_post_200_response.md)
 - [_forward_messages_post_request_t](docs/_forward_messages_post_request.md)
 - [_forward_messages_post_request_from_chat_id_t](docs/_forward_messages_post_request_from_chat_id.md)
 - [_get_available_gifts_post_200_response_t](docs/_get_available_gifts_post_200_response.md)
 - [_get_business_account_gifts_post_200_response_t](docs/_get_business_account_gifts_post_200_response.md)
 - [_get_business_account_gifts_post_request_t](docs/_get_business_account_gifts_post_request.md)
 - [_get_business_account_star_balance_post_200_response_t](docs/_get_business_account_star_balance_post_200_response.md)
 - [_get_business_connection_post_200_response_t](docs/_get_business_connection_post_200_response.md)
 - [_get_business_connection_post_request_t](docs/_get_business_connection_post_request.md)
 - [_get_chat_administrators_post_200_response_t](docs/_get_chat_administrators_post_200_response.md)
 - [_get_chat_member_count_post_200_response_t](docs/_get_chat_member_count_post_200_response.md)
 - [_get_chat_member_post_200_response_t](docs/_get_chat_member_post_200_response.md)
 - [_get_chat_member_post_request_t](docs/_get_chat_member_post_request.md)
 - [_get_chat_menu_button_post_200_response_t](docs/_get_chat_menu_button_post_200_response.md)
 - [_get_chat_menu_button_post_request_t](docs/_get_chat_menu_button_post_request.md)
 - [_get_chat_post_200_response_t](docs/_get_chat_post_200_response.md)
 - [_get_custom_emoji_stickers_post_request_t](docs/_get_custom_emoji_stickers_post_request.md)
 - [_get_file_post_200_response_t](docs/_get_file_post_200_response.md)
 - [_get_file_post_request_t](docs/_get_file_post_request.md)
 - [_get_forum_topic_icon_stickers_post_200_response_t](docs/_get_forum_topic_icon_stickers_post_200_response.md)
 - [_get_game_high_scores_post_200_response_t](docs/_get_game_high_scores_post_200_response.md)
 - [_get_game_high_scores_post_request_t](docs/_get_game_high_scores_post_request.md)
 - [_get_me_post_200_response_t](docs/_get_me_post_200_response.md)
 - [_get_my_commands_post_200_response_t](docs/_get_my_commands_post_200_response.md)
 - [_get_my_commands_post_request_t](docs/_get_my_commands_post_request.md)
 - [_get_my_default_administrator_rights_post_200_response_t](docs/_get_my_default_administrator_rights_post_200_response.md)
 - [_get_my_default_administrator_rights_post_request_t](docs/_get_my_default_administrator_rights_post_request.md)
 - [_get_my_description_post_200_response_t](docs/_get_my_description_post_200_response.md)
 - [_get_my_name_post_200_response_t](docs/_get_my_name_post_200_response.md)
 - [_get_my_name_post_request_t](docs/_get_my_name_post_request.md)
 - [_get_my_short_description_post_200_response_t](docs/_get_my_short_description_post_200_response.md)
 - [_get_star_transactions_post_200_response_t](docs/_get_star_transactions_post_200_response.md)
 - [_get_star_transactions_post_request_t](docs/_get_star_transactions_post_request.md)
 - [_get_sticker_set_post_200_response_t](docs/_get_sticker_set_post_200_response.md)
 - [_get_sticker_set_post_request_t](docs/_get_sticker_set_post_request.md)
 - [_get_updates_post_200_response_t](docs/_get_updates_post_200_response.md)
 - [_get_updates_post_request_t](docs/_get_updates_post_request.md)
 - [_get_user_chat_boosts_post_200_response_t](docs/_get_user_chat_boosts_post_200_response.md)
 - [_get_user_chat_boosts_post_request_t](docs/_get_user_chat_boosts_post_request.md)
 - [_get_user_chat_boosts_post_request_chat_id_t](docs/_get_user_chat_boosts_post_request_chat_id.md)
 - [_get_user_profile_photos_post_200_response_t](docs/_get_user_profile_photos_post_200_response.md)
 - [_get_user_profile_photos_post_request_t](docs/_get_user_profile_photos_post_request.md)
 - [_get_webhook_info_post_200_response_t](docs/_get_webhook_info_post_200_response.md)
 - [_gift_premium_subscription_post_request_t](docs/_gift_premium_subscription_post_request.md)
 - [_leave_chat_post_request_t](docs/_leave_chat_post_request.md)
 - [_leave_chat_post_request_chat_id_t](docs/_leave_chat_post_request_chat_id.md)
 - [_pin_chat_message_post_request_t](docs/_pin_chat_message_post_request.md)
 - [_post_story_post_200_response_t](docs/_post_story_post_200_response.md)
 - [_promote_chat_member_post_request_t](docs/_promote_chat_member_post_request.md)
 - [_read_business_message_post_request_t](docs/_read_business_message_post_request.md)
 - [_refund_star_payment_post_request_t](docs/_refund_star_payment_post_request.md)
 - [_remove_business_account_profile_photo_post_request_t](docs/_remove_business_account_profile_photo_post_request.md)
 - [_remove_user_verification_post_request_t](docs/_remove_user_verification_post_request.md)
 - [_restrict_chat_member_post_request_t](docs/_restrict_chat_member_post_request.md)
 - [_restrict_chat_member_post_request_chat_id_t](docs/_restrict_chat_member_post_request_chat_id.md)
 - [_revoke_chat_invite_link_post_request_t](docs/_revoke_chat_invite_link_post_request.md)
 - [_revoke_chat_invite_link_post_request_chat_id_t](docs/_revoke_chat_invite_link_post_request_chat_id.md)
 - [_save_prepared_inline_message_post_200_response_t](docs/_save_prepared_inline_message_post_200_response.md)
 - [_save_prepared_inline_message_post_request_t](docs/_save_prepared_inline_message_post_request.md)
 - [_send_animation_post_request_animation_t](docs/_send_animation_post_request_animation.md)
 - [_send_audio_post_request_audio_t](docs/_send_audio_post_request_audio.md)
 - [_send_audio_post_request_thumbnail_t](docs/_send_audio_post_request_thumbnail.md)
 - [_send_chat_action_post_request_t](docs/_send_chat_action_post_request.md)
 - [_send_contact_post_request_t](docs/_send_contact_post_request.md)
 - [_send_dice_post_request_t](docs/_send_dice_post_request.md)
 - [_send_document_post_request_document_t](docs/_send_document_post_request_document.md)
 - [_send_game_post_request_t](docs/_send_game_post_request.md)
 - [_send_gift_post_request_t](docs/_send_gift_post_request.md)
 - [_send_gift_post_request_chat_id_t](docs/_send_gift_post_request_chat_id.md)
 - [_send_invoice_post_request_t](docs/_send_invoice_post_request.md)
 - [_send_location_post_request_t](docs/_send_location_post_request.md)
 - [_send_media_group_post_200_response_t](docs/_send_media_group_post_200_response.md)
 - [_send_media_group_post_request_media_inner_t](docs/_send_media_group_post_request_media_inner.md)
 - [_send_message_post_200_response_t](docs/_send_message_post_200_response.md)
 - [_send_message_post_request_t](docs/_send_message_post_request.md)
 - [_send_message_post_request_chat_id_t](docs/_send_message_post_request_chat_id.md)
 - [_send_message_post_request_reply_markup_t](docs/_send_message_post_request_reply_markup.md)
 - [_send_paid_media_post_request_chat_id_t](docs/_send_paid_media_post_request_chat_id.md)
 - [_send_photo_post_request_photo_t](docs/_send_photo_post_request_photo.md)
 - [_send_poll_post_request_t](docs/_send_poll_post_request.md)
 - [_send_sticker_post_request_sticker_t](docs/_send_sticker_post_request_sticker.md)
 - [_send_venue_post_request_t](docs/_send_venue_post_request.md)
 - [_send_video_note_post_request_video_note_t](docs/_send_video_note_post_request_video_note.md)
 - [_send_video_post_request_cover_t](docs/_send_video_post_request_cover.md)
 - [_send_video_post_request_video_t](docs/_send_video_post_request_video.md)
 - [_send_voice_post_request_voice_t](docs/_send_voice_post_request_voice.md)
 - [_set_business_account_bio_post_request_t](docs/_set_business_account_bio_post_request.md)
 - [_set_business_account_gift_settings_post_request_t](docs/_set_business_account_gift_settings_post_request.md)
 - [_set_business_account_name_post_request_t](docs/_set_business_account_name_post_request.md)
 - [_set_business_account_username_post_request_t](docs/_set_business_account_username_post_request.md)
 - [_set_chat_administrator_custom_title_post_request_t](docs/_set_chat_administrator_custom_title_post_request.md)
 - [_set_chat_description_post_request_t](docs/_set_chat_description_post_request.md)
 - [_set_chat_menu_button_post_request_t](docs/_set_chat_menu_button_post_request.md)
 - [_set_chat_permissions_post_request_t](docs/_set_chat_permissions_post_request.md)
 - [_set_chat_sticker_set_post_request_t](docs/_set_chat_sticker_set_post_request.md)
 - [_set_chat_title_post_request_t](docs/_set_chat_title_post_request.md)
 - [_set_custom_emoji_sticker_set_thumbnail_post_request_t](docs/_set_custom_emoji_sticker_set_thumbnail_post_request.md)
 - [_set_game_score_post_request_t](docs/_set_game_score_post_request.md)
 - [_set_message_reaction_post_request_t](docs/_set_message_reaction_post_request.md)
 - [_set_my_commands_post_request_t](docs/_set_my_commands_post_request.md)
 - [_set_my_default_administrator_rights_post_request_t](docs/_set_my_default_administrator_rights_post_request.md)
 - [_set_my_description_post_request_t](docs/_set_my_description_post_request.md)
 - [_set_my_name_post_request_t](docs/_set_my_name_post_request.md)
 - [_set_my_short_description_post_request_t](docs/_set_my_short_description_post_request.md)
 - [_set_passport_data_errors_post_request_t](docs/_set_passport_data_errors_post_request.md)
 - [_set_sticker_emoji_list_post_request_t](docs/_set_sticker_emoji_list_post_request.md)
 - [_set_sticker_keywords_post_request_t](docs/_set_sticker_keywords_post_request.md)
 - [_set_sticker_mask_position_post_request_t](docs/_set_sticker_mask_position_post_request.md)
 - [_set_sticker_position_in_set_post_request_t](docs/_set_sticker_position_in_set_post_request.md)
 - [_set_sticker_set_thumbnail_post_request_thumbnail_t](docs/_set_sticker_set_thumbnail_post_request_thumbnail.md)
 - [_set_sticker_set_title_post_request_t](docs/_set_sticker_set_title_post_request.md)
 - [_set_user_emoji_status_post_request_t](docs/_set_user_emoji_status_post_request.md)
 - [_set_webhook_post_200_response_t](docs/_set_webhook_post_200_response.md)
 - [_stop_message_live_location_post_request_t](docs/_stop_message_live_location_post_request.md)
 - [_stop_poll_post_200_response_t](docs/_stop_poll_post_200_response.md)
 - [_stop_poll_post_request_t](docs/_stop_poll_post_request.md)
 - [_transfer_business_account_stars_post_request_t](docs/_transfer_business_account_stars_post_request.md)
 - [_transfer_gift_post_request_t](docs/_transfer_gift_post_request.md)
 - [_unban_chat_member_post_request_t](docs/_unban_chat_member_post_request.md)
 - [_unpin_chat_message_post_request_t](docs/_unpin_chat_message_post_request.md)
 - [_upgrade_gift_post_request_t](docs/_upgrade_gift_post_request.md)
 - [_verify_chat_post_request_t](docs/_verify_chat_post_request.md)
 - [_verify_user_post_request_t](docs/_verify_user_post_request.md)
 - [accepted_gift_types_t](docs/accepted_gift_types.md)
 - [affiliate_info_t](docs/affiliate_info.md)
 - [animation_t](docs/animation.md)
 - [audio_t](docs/audio.md)
 - [background_fill_t](docs/background_fill.md)
 - [background_fill_freeform_gradient_t](docs/background_fill_freeform_gradient.md)
 - [background_fill_gradient_t](docs/background_fill_gradient.md)
 - [background_fill_solid_t](docs/background_fill_solid.md)
 - [background_type_t](docs/background_type.md)
 - [background_type_chat_theme_t](docs/background_type_chat_theme.md)
 - [background_type_fill_t](docs/background_type_fill.md)
 - [background_type_pattern_t](docs/background_type_pattern.md)
 - [background_type_wallpaper_t](docs/background_type_wallpaper.md)
 - [birthdate_t](docs/birthdate.md)
 - [bot_command_t](docs/bot_command.md)
 - [bot_command_scope_t](docs/bot_command_scope.md)
 - [bot_command_scope_all_chat_administrators_t](docs/bot_command_scope_all_chat_administrators.md)
 - [bot_command_scope_all_group_chats_t](docs/bot_command_scope_all_group_chats.md)
 - [bot_command_scope_all_private_chats_t](docs/bot_command_scope_all_private_chats.md)
 - [bot_command_scope_chat_t](docs/bot_command_scope_chat.md)
 - [bot_command_scope_chat_administrators_t](docs/bot_command_scope_chat_administrators.md)
 - [bot_command_scope_chat_member_t](docs/bot_command_scope_chat_member.md)
 - [bot_command_scope_default_t](docs/bot_command_scope_default.md)
 - [bot_description_t](docs/bot_description.md)
 - [bot_name_t](docs/bot_name.md)
 - [bot_short_description_t](docs/bot_short_description.md)
 - [business_bot_rights_t](docs/business_bot_rights.md)
 - [business_connection_t](docs/business_connection.md)
 - [business_intro_t](docs/business_intro.md)
 - [business_location_t](docs/business_location.md)
 - [business_messages_deleted_t](docs/business_messages_deleted.md)
 - [business_opening_hours_t](docs/business_opening_hours.md)
 - [business_opening_hours_interval_t](docs/business_opening_hours_interval.md)
 - [callback_query_t](docs/callback_query.md)
 - [chat_t](docs/chat.md)
 - [chat_administrator_rights_t](docs/chat_administrator_rights.md)
 - [chat_background_t](docs/chat_background.md)
 - [chat_boost_t](docs/chat_boost.md)
 - [chat_boost_added_t](docs/chat_boost_added.md)
 - [chat_boost_removed_t](docs/chat_boost_removed.md)
 - [chat_boost_source_t](docs/chat_boost_source.md)
 - [chat_boost_source_gift_code_t](docs/chat_boost_source_gift_code.md)
 - [chat_boost_source_giveaway_t](docs/chat_boost_source_giveaway.md)
 - [chat_boost_source_premium_t](docs/chat_boost_source_premium.md)
 - [chat_boost_updated_t](docs/chat_boost_updated.md)
 - [chat_full_info_t](docs/chat_full_info.md)
 - [chat_invite_link_t](docs/chat_invite_link.md)
 - [chat_join_request_t](docs/chat_join_request.md)
 - [chat_location_t](docs/chat_location.md)
 - [chat_member_t](docs/chat_member.md)
 - [chat_member_administrator_t](docs/chat_member_administrator.md)
 - [chat_member_banned_t](docs/chat_member_banned.md)
 - [chat_member_left_t](docs/chat_member_left.md)
 - [chat_member_member_t](docs/chat_member_member.md)
 - [chat_member_owner_t](docs/chat_member_owner.md)
 - [chat_member_restricted_t](docs/chat_member_restricted.md)
 - [chat_member_updated_t](docs/chat_member_updated.md)
 - [chat_permissions_t](docs/chat_permissions.md)
 - [chat_photo_t](docs/chat_photo.md)
 - [chat_shared_t](docs/chat_shared.md)
 - [chosen_inline_result_t](docs/chosen_inline_result.md)
 - [contact_t](docs/contact.md)
 - [copy_text_button_t](docs/copy_text_button.md)
 - [dice_t](docs/dice.md)
 - [document_t](docs/document.md)
 - [encrypted_credentials_t](docs/encrypted_credentials.md)
 - [encrypted_passport_element_t](docs/encrypted_passport_element.md)
 - [error_t](docs/error.md)
 - [external_reply_info_t](docs/external_reply_info.md)
 - [file_t](docs/file.md)
 - [force_reply_t](docs/force_reply.md)
 - [forum_topic_t](docs/forum_topic.md)
 - [forum_topic_created_t](docs/forum_topic_created.md)
 - [forum_topic_edited_t](docs/forum_topic_edited.md)
 - [game_t](docs/game.md)
 - [game_high_score_t](docs/game_high_score.md)
 - [gift_t](docs/gift.md)
 - [gift_info_t](docs/gift_info.md)
 - [gifts_t](docs/gifts.md)
 - [giveaway_t](docs/giveaway.md)
 - [giveaway_completed_t](docs/giveaway_completed.md)
 - [giveaway_created_t](docs/giveaway_created.md)
 - [giveaway_winners_t](docs/giveaway_winners.md)
 - [inaccessible_message_t](docs/inaccessible_message.md)
 - [inline_keyboard_button_t](docs/inline_keyboard_button.md)
 - [inline_keyboard_markup_t](docs/inline_keyboard_markup.md)
 - [inline_query_t](docs/inline_query.md)
 - [inline_query_result_t](docs/inline_query_result.md)
 - [inline_query_result_article_t](docs/inline_query_result_article.md)
 - [inline_query_result_audio_t](docs/inline_query_result_audio.md)
 - [inline_query_result_cached_audio_t](docs/inline_query_result_cached_audio.md)
 - [inline_query_result_cached_document_t](docs/inline_query_result_cached_document.md)
 - [inline_query_result_cached_gif_t](docs/inline_query_result_cached_gif.md)
 - [inline_query_result_cached_mpeg4_gif_t](docs/inline_query_result_cached_mpeg4_gif.md)
 - [inline_query_result_cached_photo_t](docs/inline_query_result_cached_photo.md)
 - [inline_query_result_cached_sticker_t](docs/inline_query_result_cached_sticker.md)
 - [inline_query_result_cached_video_t](docs/inline_query_result_cached_video.md)
 - [inline_query_result_cached_voice_t](docs/inline_query_result_cached_voice.md)
 - [inline_query_result_contact_t](docs/inline_query_result_contact.md)
 - [inline_query_result_document_t](docs/inline_query_result_document.md)
 - [inline_query_result_game_t](docs/inline_query_result_game.md)
 - [inline_query_result_gif_t](docs/inline_query_result_gif.md)
 - [inline_query_result_location_t](docs/inline_query_result_location.md)
 - [inline_query_result_mpeg4_gif_t](docs/inline_query_result_mpeg4_gif.md)
 - [inline_query_result_photo_t](docs/inline_query_result_photo.md)
 - [inline_query_result_venue_t](docs/inline_query_result_venue.md)
 - [inline_query_result_video_t](docs/inline_query_result_video.md)
 - [inline_query_result_voice_t](docs/inline_query_result_voice.md)
 - [inline_query_results_button_t](docs/inline_query_results_button.md)
 - [input_contact_message_content_t](docs/input_contact_message_content.md)
 - [input_invoice_message_content_t](docs/input_invoice_message_content.md)
 - [input_location_message_content_t](docs/input_location_message_content.md)
 - [input_media_t](docs/input_media.md)
 - [input_media_animation_t](docs/input_media_animation.md)
 - [input_media_audio_t](docs/input_media_audio.md)
 - [input_media_document_t](docs/input_media_document.md)
 - [input_media_photo_t](docs/input_media_photo.md)
 - [input_media_video_t](docs/input_media_video.md)
 - [input_message_content_t](docs/input_message_content.md)
 - [input_paid_media_t](docs/input_paid_media.md)
 - [input_paid_media_photo_t](docs/input_paid_media_photo.md)
 - [input_paid_media_video_t](docs/input_paid_media_video.md)
 - [input_poll_option_t](docs/input_poll_option.md)
 - [input_profile_photo_t](docs/input_profile_photo.md)
 - [input_profile_photo_animated_t](docs/input_profile_photo_animated.md)
 - [input_profile_photo_static_t](docs/input_profile_photo_static.md)
 - [input_sticker_t](docs/input_sticker.md)
 - [input_story_content_t](docs/input_story_content.md)
 - [input_story_content_photo_t](docs/input_story_content_photo.md)
 - [input_story_content_video_t](docs/input_story_content_video.md)
 - [input_text_message_content_t](docs/input_text_message_content.md)
 - [input_venue_message_content_t](docs/input_venue_message_content.md)
 - [invoice_t](docs/invoice.md)
 - [keyboard_button_t](docs/keyboard_button.md)
 - [keyboard_button_poll_type_t](docs/keyboard_button_poll_type.md)
 - [keyboard_button_request_chat_t](docs/keyboard_button_request_chat.md)
 - [keyboard_button_request_users_t](docs/keyboard_button_request_users.md)
 - [labeled_price_t](docs/labeled_price.md)
 - [link_preview_options_t](docs/link_preview_options.md)
 - [location_t](docs/location.md)
 - [location_address_t](docs/location_address.md)
 - [login_url_t](docs/login_url.md)
 - [mask_position_t](docs/mask_position.md)
 - [maybe_inaccessible_message_t](docs/maybe_inaccessible_message.md)
 - [menu_button_t](docs/menu_button.md)
 - [menu_button_commands_t](docs/menu_button_commands.md)
 - [menu_button_default_t](docs/menu_button_default.md)
 - [menu_button_web_app_t](docs/menu_button_web_app.md)
 - [message_t](docs/message.md)
 - [message_auto_delete_timer_changed_t](docs/message_auto_delete_timer_changed.md)
 - [message_entity_t](docs/message_entity.md)
 - [message_id_t](docs/message_id.md)
 - [message_origin_t](docs/message_origin.md)
 - [message_origin_channel_t](docs/message_origin_channel.md)
 - [message_origin_chat_t](docs/message_origin_chat.md)
 - [message_origin_hidden_user_t](docs/message_origin_hidden_user.md)
 - [message_origin_user_t](docs/message_origin_user.md)
 - [message_reaction_count_updated_t](docs/message_reaction_count_updated.md)
 - [message_reaction_updated_t](docs/message_reaction_updated.md)
 - [order_info_t](docs/order_info.md)
 - [owned_gift_t](docs/owned_gift.md)
 - [owned_gift_regular_t](docs/owned_gift_regular.md)
 - [owned_gift_unique_t](docs/owned_gift_unique.md)
 - [owned_gifts_t](docs/owned_gifts.md)
 - [paid_media_t](docs/paid_media.md)
 - [paid_media_info_t](docs/paid_media_info.md)
 - [paid_media_photo_t](docs/paid_media_photo.md)
 - [paid_media_preview_t](docs/paid_media_preview.md)
 - [paid_media_purchased_t](docs/paid_media_purchased.md)
 - [paid_media_video_t](docs/paid_media_video.md)
 - [paid_message_price_changed_t](docs/paid_message_price_changed.md)
 - [passport_data_t](docs/passport_data.md)
 - [passport_element_error_t](docs/passport_element_error.md)
 - [passport_element_error_data_field_t](docs/passport_element_error_data_field.md)
 - [passport_element_error_file_t](docs/passport_element_error_file.md)
 - [passport_element_error_files_t](docs/passport_element_error_files.md)
 - [passport_element_error_front_side_t](docs/passport_element_error_front_side.md)
 - [passport_element_error_reverse_side_t](docs/passport_element_error_reverse_side.md)
 - [passport_element_error_selfie_t](docs/passport_element_error_selfie.md)
 - [passport_element_error_translation_file_t](docs/passport_element_error_translation_file.md)
 - [passport_element_error_translation_files_t](docs/passport_element_error_translation_files.md)
 - [passport_element_error_unspecified_t](docs/passport_element_error_unspecified.md)
 - [passport_file_t](docs/passport_file.md)
 - [photo_size_t](docs/photo_size.md)
 - [poll_t](docs/poll.md)
 - [poll_answer_t](docs/poll_answer.md)
 - [poll_option_t](docs/poll_option.md)
 - [pre_checkout_query_t](docs/pre_checkout_query.md)
 - [prepared_inline_message_t](docs/prepared_inline_message.md)
 - [proximity_alert_triggered_t](docs/proximity_alert_triggered.md)
 - [reaction_count_t](docs/reaction_count.md)
 - [reaction_type_t](docs/reaction_type.md)
 - [reaction_type_custom_emoji_t](docs/reaction_type_custom_emoji.md)
 - [reaction_type_emoji_t](docs/reaction_type_emoji.md)
 - [reaction_type_paid_t](docs/reaction_type_paid.md)
 - [refunded_payment_t](docs/refunded_payment.md)
 - [reply_keyboard_markup_t](docs/reply_keyboard_markup.md)
 - [reply_keyboard_remove_t](docs/reply_keyboard_remove.md)
 - [reply_parameters_t](docs/reply_parameters.md)
 - [reply_parameters_chat_id_t](docs/reply_parameters_chat_id.md)
 - [response_parameters_t](docs/response_parameters.md)
 - [revenue_withdrawal_state_t](docs/revenue_withdrawal_state.md)
 - [revenue_withdrawal_state_failed_t](docs/revenue_withdrawal_state_failed.md)
 - [revenue_withdrawal_state_pending_t](docs/revenue_withdrawal_state_pending.md)
 - [revenue_withdrawal_state_succeeded_t](docs/revenue_withdrawal_state_succeeded.md)
 - [sent_web_app_message_t](docs/sent_web_app_message.md)
 - [shared_user_t](docs/shared_user.md)
 - [shipping_address_t](docs/shipping_address.md)
 - [shipping_option_t](docs/shipping_option.md)
 - [shipping_query_t](docs/shipping_query.md)
 - [star_amount_t](docs/star_amount.md)
 - [star_transaction_t](docs/star_transaction.md)
 - [star_transactions_t](docs/star_transactions.md)
 - [sticker_t](docs/sticker.md)
 - [sticker_set_t](docs/sticker_set.md)
 - [story_t](docs/story.md)
 - [story_area_t](docs/story_area.md)
 - [story_area_position_t](docs/story_area_position.md)
 - [story_area_type_t](docs/story_area_type.md)
 - [story_area_type_link_t](docs/story_area_type_link.md)
 - [story_area_type_location_t](docs/story_area_type_location.md)
 - [story_area_type_suggested_reaction_t](docs/story_area_type_suggested_reaction.md)
 - [story_area_type_unique_gift_t](docs/story_area_type_unique_gift.md)
 - [story_area_type_weather_t](docs/story_area_type_weather.md)
 - [successful_payment_t](docs/successful_payment.md)
 - [switch_inline_query_chosen_chat_t](docs/switch_inline_query_chosen_chat.md)
 - [text_quote_t](docs/text_quote.md)
 - [transaction_partner_t](docs/transaction_partner.md)
 - [transaction_partner_affiliate_program_t](docs/transaction_partner_affiliate_program.md)
 - [transaction_partner_chat_t](docs/transaction_partner_chat.md)
 - [transaction_partner_fragment_t](docs/transaction_partner_fragment.md)
 - [transaction_partner_other_t](docs/transaction_partner_other.md)
 - [transaction_partner_telegram_ads_t](docs/transaction_partner_telegram_ads.md)
 - [transaction_partner_telegram_api_t](docs/transaction_partner_telegram_api.md)
 - [transaction_partner_user_t](docs/transaction_partner_user.md)
 - [unique_gift_t](docs/unique_gift.md)
 - [unique_gift_backdrop_t](docs/unique_gift_backdrop.md)
 - [unique_gift_backdrop_colors_t](docs/unique_gift_backdrop_colors.md)
 - [unique_gift_info_t](docs/unique_gift_info.md)
 - [unique_gift_model_t](docs/unique_gift_model.md)
 - [unique_gift_symbol_t](docs/unique_gift_symbol.md)
 - [update_t](docs/update.md)
 - [user_t](docs/user.md)
 - [user_chat_boosts_t](docs/user_chat_boosts.md)
 - [user_profile_photos_t](docs/user_profile_photos.md)
 - [users_shared_t](docs/users_shared.md)
 - [venue_t](docs/venue.md)
 - [video_t](docs/video.md)
 - [video_chat_ended_t](docs/video_chat_ended.md)
 - [video_chat_participants_invited_t](docs/video_chat_participants_invited.md)
 - [video_chat_scheduled_t](docs/video_chat_scheduled.md)
 - [video_note_t](docs/video_note.md)
 - [voice_t](docs/voice.md)
 - [web_app_data_t](docs/web_app_data.md)
 - [web_app_info_t](docs/web_app_info.md)
 - [webhook_info_t](docs/webhook_info.md)
 - [write_access_allowed_t](docs/write_access_allowed.md)


## Documentation for Authorization

Endpoints do not require authorization.


## Author



