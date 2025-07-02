# C API client for telegram_bot_api

## Overview

- API version: 9.0.0
- Package version: 
- Build date: 2025-07-02T09:17:25.696462313Z[Etc/UTC]
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
*DefaultAPI* | [**DefaultAPI_postAddStickerToSet**](docs/DefaultAPI.md#DefaultAPI_postAddStickerToSet) | **POST** /addStickerToSet | addStickerToSet
*DefaultAPI* | [**DefaultAPI_postAnswerCallbackQuery**](docs/DefaultAPI.md#DefaultAPI_postAnswerCallbackQuery) | **POST** /answerCallbackQuery | answerCallbackQuery
*DefaultAPI* | [**DefaultAPI_postAnswerInlineQuery**](docs/DefaultAPI.md#DefaultAPI_postAnswerInlineQuery) | **POST** /answerInlineQuery | answerInlineQuery
*DefaultAPI* | [**DefaultAPI_postAnswerPreCheckoutQuery**](docs/DefaultAPI.md#DefaultAPI_postAnswerPreCheckoutQuery) | **POST** /answerPreCheckoutQuery | answerPreCheckoutQuery
*DefaultAPI* | [**DefaultAPI_postAnswerShippingQuery**](docs/DefaultAPI.md#DefaultAPI_postAnswerShippingQuery) | **POST** /answerShippingQuery | answerShippingQuery
*DefaultAPI* | [**DefaultAPI_postAnswerWebAppQuery**](docs/DefaultAPI.md#DefaultAPI_postAnswerWebAppQuery) | **POST** /answerWebAppQuery | answerWebAppQuery
*DefaultAPI* | [**DefaultAPI_postApproveChatJoinRequest**](docs/DefaultAPI.md#DefaultAPI_postApproveChatJoinRequest) | **POST** /approveChatJoinRequest | approveChatJoinRequest
*DefaultAPI* | [**DefaultAPI_postBanChatMember**](docs/DefaultAPI.md#DefaultAPI_postBanChatMember) | **POST** /banChatMember | banChatMember
*DefaultAPI* | [**DefaultAPI_postBanChatSenderChat**](docs/DefaultAPI.md#DefaultAPI_postBanChatSenderChat) | **POST** /banChatSenderChat | banChatSenderChat
*DefaultAPI* | [**DefaultAPI_postClose**](docs/DefaultAPI.md#DefaultAPI_postClose) | **POST** /close | close
*DefaultAPI* | [**DefaultAPI_postCloseForumTopic**](docs/DefaultAPI.md#DefaultAPI_postCloseForumTopic) | **POST** /closeForumTopic | closeForumTopic
*DefaultAPI* | [**DefaultAPI_postCloseGeneralForumTopic**](docs/DefaultAPI.md#DefaultAPI_postCloseGeneralForumTopic) | **POST** /closeGeneralForumTopic | closeGeneralForumTopic
*DefaultAPI* | [**DefaultAPI_postConvertGiftToStars**](docs/DefaultAPI.md#DefaultAPI_postConvertGiftToStars) | **POST** /convertGiftToStars | convertGiftToStars
*DefaultAPI* | [**DefaultAPI_postCopyMessage**](docs/DefaultAPI.md#DefaultAPI_postCopyMessage) | **POST** /copyMessage | copyMessage
*DefaultAPI* | [**DefaultAPI_postCopyMessages**](docs/DefaultAPI.md#DefaultAPI_postCopyMessages) | **POST** /copyMessages | copyMessages
*DefaultAPI* | [**DefaultAPI_postCreateChatInviteLink**](docs/DefaultAPI.md#DefaultAPI_postCreateChatInviteLink) | **POST** /createChatInviteLink | createChatInviteLink
*DefaultAPI* | [**DefaultAPI_postCreateChatSubscriptionInviteLink**](docs/DefaultAPI.md#DefaultAPI_postCreateChatSubscriptionInviteLink) | **POST** /createChatSubscriptionInviteLink | createChatSubscriptionInviteLink
*DefaultAPI* | [**DefaultAPI_postCreateForumTopic**](docs/DefaultAPI.md#DefaultAPI_postCreateForumTopic) | **POST** /createForumTopic | createForumTopic
*DefaultAPI* | [**DefaultAPI_postCreateInvoiceLink**](docs/DefaultAPI.md#DefaultAPI_postCreateInvoiceLink) | **POST** /createInvoiceLink | createInvoiceLink
*DefaultAPI* | [**DefaultAPI_postCreateNewStickerSet**](docs/DefaultAPI.md#DefaultAPI_postCreateNewStickerSet) | **POST** /createNewStickerSet | createNewStickerSet
*DefaultAPI* | [**DefaultAPI_postDeclineChatJoinRequest**](docs/DefaultAPI.md#DefaultAPI_postDeclineChatJoinRequest) | **POST** /declineChatJoinRequest | declineChatJoinRequest
*DefaultAPI* | [**DefaultAPI_postDeleteBusinessMessages**](docs/DefaultAPI.md#DefaultAPI_postDeleteBusinessMessages) | **POST** /deleteBusinessMessages | deleteBusinessMessages
*DefaultAPI* | [**DefaultAPI_postDeleteChatPhoto**](docs/DefaultAPI.md#DefaultAPI_postDeleteChatPhoto) | **POST** /deleteChatPhoto | deleteChatPhoto
*DefaultAPI* | [**DefaultAPI_postDeleteChatStickerSet**](docs/DefaultAPI.md#DefaultAPI_postDeleteChatStickerSet) | **POST** /deleteChatStickerSet | deleteChatStickerSet
*DefaultAPI* | [**DefaultAPI_postDeleteForumTopic**](docs/DefaultAPI.md#DefaultAPI_postDeleteForumTopic) | **POST** /deleteForumTopic | deleteForumTopic
*DefaultAPI* | [**DefaultAPI_postDeleteMessage**](docs/DefaultAPI.md#DefaultAPI_postDeleteMessage) | **POST** /deleteMessage | deleteMessage
*DefaultAPI* | [**DefaultAPI_postDeleteMessages**](docs/DefaultAPI.md#DefaultAPI_postDeleteMessages) | **POST** /deleteMessages | deleteMessages
*DefaultAPI* | [**DefaultAPI_postDeleteMyCommands**](docs/DefaultAPI.md#DefaultAPI_postDeleteMyCommands) | **POST** /deleteMyCommands | deleteMyCommands
*DefaultAPI* | [**DefaultAPI_postDeleteStickerFromSet**](docs/DefaultAPI.md#DefaultAPI_postDeleteStickerFromSet) | **POST** /deleteStickerFromSet | deleteStickerFromSet
*DefaultAPI* | [**DefaultAPI_postDeleteStickerSet**](docs/DefaultAPI.md#DefaultAPI_postDeleteStickerSet) | **POST** /deleteStickerSet | deleteStickerSet
*DefaultAPI* | [**DefaultAPI_postDeleteStory**](docs/DefaultAPI.md#DefaultAPI_postDeleteStory) | **POST** /deleteStory | deleteStory
*DefaultAPI* | [**DefaultAPI_postDeleteWebhook**](docs/DefaultAPI.md#DefaultAPI_postDeleteWebhook) | **POST** /deleteWebhook | deleteWebhook
*DefaultAPI* | [**DefaultAPI_postEditChatInviteLink**](docs/DefaultAPI.md#DefaultAPI_postEditChatInviteLink) | **POST** /editChatInviteLink | editChatInviteLink
*DefaultAPI* | [**DefaultAPI_postEditChatSubscriptionInviteLink**](docs/DefaultAPI.md#DefaultAPI_postEditChatSubscriptionInviteLink) | **POST** /editChatSubscriptionInviteLink | editChatSubscriptionInviteLink
*DefaultAPI* | [**DefaultAPI_postEditForumTopic**](docs/DefaultAPI.md#DefaultAPI_postEditForumTopic) | **POST** /editForumTopic | editForumTopic
*DefaultAPI* | [**DefaultAPI_postEditGeneralForumTopic**](docs/DefaultAPI.md#DefaultAPI_postEditGeneralForumTopic) | **POST** /editGeneralForumTopic | editGeneralForumTopic
*DefaultAPI* | [**DefaultAPI_postEditMessageCaption**](docs/DefaultAPI.md#DefaultAPI_postEditMessageCaption) | **POST** /editMessageCaption | editMessageCaption
*DefaultAPI* | [**DefaultAPI_postEditMessageLiveLocation**](docs/DefaultAPI.md#DefaultAPI_postEditMessageLiveLocation) | **POST** /editMessageLiveLocation | editMessageLiveLocation
*DefaultAPI* | [**DefaultAPI_postEditMessageMedia**](docs/DefaultAPI.md#DefaultAPI_postEditMessageMedia) | **POST** /editMessageMedia | editMessageMedia
*DefaultAPI* | [**DefaultAPI_postEditMessageReplyMarkup**](docs/DefaultAPI.md#DefaultAPI_postEditMessageReplyMarkup) | **POST** /editMessageReplyMarkup | editMessageReplyMarkup
*DefaultAPI* | [**DefaultAPI_postEditMessageText**](docs/DefaultAPI.md#DefaultAPI_postEditMessageText) | **POST** /editMessageText | editMessageText
*DefaultAPI* | [**DefaultAPI_postEditStory**](docs/DefaultAPI.md#DefaultAPI_postEditStory) | **POST** /editStory | editStory
*DefaultAPI* | [**DefaultAPI_postEditUserStarSubscription**](docs/DefaultAPI.md#DefaultAPI_postEditUserStarSubscription) | **POST** /editUserStarSubscription | editUserStarSubscription
*DefaultAPI* | [**DefaultAPI_postExportChatInviteLink**](docs/DefaultAPI.md#DefaultAPI_postExportChatInviteLink) | **POST** /exportChatInviteLink | exportChatInviteLink
*DefaultAPI* | [**DefaultAPI_postForwardMessage**](docs/DefaultAPI.md#DefaultAPI_postForwardMessage) | **POST** /forwardMessage | forwardMessage
*DefaultAPI* | [**DefaultAPI_postForwardMessages**](docs/DefaultAPI.md#DefaultAPI_postForwardMessages) | **POST** /forwardMessages | forwardMessages
*DefaultAPI* | [**DefaultAPI_postGetAvailableGifts**](docs/DefaultAPI.md#DefaultAPI_postGetAvailableGifts) | **POST** /getAvailableGifts | getAvailableGifts
*DefaultAPI* | [**DefaultAPI_postGetBusinessAccountGifts**](docs/DefaultAPI.md#DefaultAPI_postGetBusinessAccountGifts) | **POST** /getBusinessAccountGifts | getBusinessAccountGifts
*DefaultAPI* | [**DefaultAPI_postGetBusinessAccountStarBalance**](docs/DefaultAPI.md#DefaultAPI_postGetBusinessAccountStarBalance) | **POST** /getBusinessAccountStarBalance | getBusinessAccountStarBalance
*DefaultAPI* | [**DefaultAPI_postGetBusinessConnection**](docs/DefaultAPI.md#DefaultAPI_postGetBusinessConnection) | **POST** /getBusinessConnection | getBusinessConnection
*DefaultAPI* | [**DefaultAPI_postGetChat**](docs/DefaultAPI.md#DefaultAPI_postGetChat) | **POST** /getChat | getChat
*DefaultAPI* | [**DefaultAPI_postGetChatAdministrators**](docs/DefaultAPI.md#DefaultAPI_postGetChatAdministrators) | **POST** /getChatAdministrators | getChatAdministrators
*DefaultAPI* | [**DefaultAPI_postGetChatMember**](docs/DefaultAPI.md#DefaultAPI_postGetChatMember) | **POST** /getChatMember | getChatMember
*DefaultAPI* | [**DefaultAPI_postGetChatMemberCount**](docs/DefaultAPI.md#DefaultAPI_postGetChatMemberCount) | **POST** /getChatMemberCount | getChatMemberCount
*DefaultAPI* | [**DefaultAPI_postGetChatMenuButton**](docs/DefaultAPI.md#DefaultAPI_postGetChatMenuButton) | **POST** /getChatMenuButton | getChatMenuButton
*DefaultAPI* | [**DefaultAPI_postGetCustomEmojiStickers**](docs/DefaultAPI.md#DefaultAPI_postGetCustomEmojiStickers) | **POST** /getCustomEmojiStickers | getCustomEmojiStickers
*DefaultAPI* | [**DefaultAPI_postGetFile**](docs/DefaultAPI.md#DefaultAPI_postGetFile) | **POST** /getFile | getFile
*DefaultAPI* | [**DefaultAPI_postGetForumTopicIconStickers**](docs/DefaultAPI.md#DefaultAPI_postGetForumTopicIconStickers) | **POST** /getForumTopicIconStickers | getForumTopicIconStickers
*DefaultAPI* | [**DefaultAPI_postGetGameHighScores**](docs/DefaultAPI.md#DefaultAPI_postGetGameHighScores) | **POST** /getGameHighScores | getGameHighScores
*DefaultAPI* | [**DefaultAPI_postGetMe**](docs/DefaultAPI.md#DefaultAPI_postGetMe) | **POST** /getMe | getMe
*DefaultAPI* | [**DefaultAPI_postGetMyCommands**](docs/DefaultAPI.md#DefaultAPI_postGetMyCommands) | **POST** /getMyCommands | getMyCommands
*DefaultAPI* | [**DefaultAPI_postGetMyDefaultAdministratorRights**](docs/DefaultAPI.md#DefaultAPI_postGetMyDefaultAdministratorRights) | **POST** /getMyDefaultAdministratorRights | getMyDefaultAdministratorRights
*DefaultAPI* | [**DefaultAPI_postGetMyDescription**](docs/DefaultAPI.md#DefaultAPI_postGetMyDescription) | **POST** /getMyDescription | getMyDescription
*DefaultAPI* | [**DefaultAPI_postGetMyName**](docs/DefaultAPI.md#DefaultAPI_postGetMyName) | **POST** /getMyName | getMyName
*DefaultAPI* | [**DefaultAPI_postGetMyShortDescription**](docs/DefaultAPI.md#DefaultAPI_postGetMyShortDescription) | **POST** /getMyShortDescription | getMyShortDescription
*DefaultAPI* | [**DefaultAPI_postGetStarTransactions**](docs/DefaultAPI.md#DefaultAPI_postGetStarTransactions) | **POST** /getStarTransactions | getStarTransactions
*DefaultAPI* | [**DefaultAPI_postGetStickerSet**](docs/DefaultAPI.md#DefaultAPI_postGetStickerSet) | **POST** /getStickerSet | getStickerSet
*DefaultAPI* | [**DefaultAPI_postGetUpdates**](docs/DefaultAPI.md#DefaultAPI_postGetUpdates) | **POST** /getUpdates | getUpdates
*DefaultAPI* | [**DefaultAPI_postGetUserChatBoosts**](docs/DefaultAPI.md#DefaultAPI_postGetUserChatBoosts) | **POST** /getUserChatBoosts | getUserChatBoosts
*DefaultAPI* | [**DefaultAPI_postGetUserProfilePhotos**](docs/DefaultAPI.md#DefaultAPI_postGetUserProfilePhotos) | **POST** /getUserProfilePhotos | getUserProfilePhotos
*DefaultAPI* | [**DefaultAPI_postGetWebhookInfo**](docs/DefaultAPI.md#DefaultAPI_postGetWebhookInfo) | **POST** /getWebhookInfo | getWebhookInfo
*DefaultAPI* | [**DefaultAPI_postGiftPremiumSubscription**](docs/DefaultAPI.md#DefaultAPI_postGiftPremiumSubscription) | **POST** /giftPremiumSubscription | giftPremiumSubscription
*DefaultAPI* | [**DefaultAPI_postHideGeneralForumTopic**](docs/DefaultAPI.md#DefaultAPI_postHideGeneralForumTopic) | **POST** /hideGeneralForumTopic | hideGeneralForumTopic
*DefaultAPI* | [**DefaultAPI_postLeaveChat**](docs/DefaultAPI.md#DefaultAPI_postLeaveChat) | **POST** /leaveChat | leaveChat
*DefaultAPI* | [**DefaultAPI_postLogOut**](docs/DefaultAPI.md#DefaultAPI_postLogOut) | **POST** /logOut | logOut
*DefaultAPI* | [**DefaultAPI_postPinChatMessage**](docs/DefaultAPI.md#DefaultAPI_postPinChatMessage) | **POST** /pinChatMessage | pinChatMessage
*DefaultAPI* | [**DefaultAPI_postPostStory**](docs/DefaultAPI.md#DefaultAPI_postPostStory) | **POST** /postStory | postStory
*DefaultAPI* | [**DefaultAPI_postPromoteChatMember**](docs/DefaultAPI.md#DefaultAPI_postPromoteChatMember) | **POST** /promoteChatMember | promoteChatMember
*DefaultAPI* | [**DefaultAPI_postReadBusinessMessage**](docs/DefaultAPI.md#DefaultAPI_postReadBusinessMessage) | **POST** /readBusinessMessage | readBusinessMessage
*DefaultAPI* | [**DefaultAPI_postRefundStarPayment**](docs/DefaultAPI.md#DefaultAPI_postRefundStarPayment) | **POST** /refundStarPayment | refundStarPayment
*DefaultAPI* | [**DefaultAPI_postRemoveBusinessAccountProfilePhoto**](docs/DefaultAPI.md#DefaultAPI_postRemoveBusinessAccountProfilePhoto) | **POST** /removeBusinessAccountProfilePhoto | removeBusinessAccountProfilePhoto
*DefaultAPI* | [**DefaultAPI_postRemoveChatVerification**](docs/DefaultAPI.md#DefaultAPI_postRemoveChatVerification) | **POST** /removeChatVerification | removeChatVerification
*DefaultAPI* | [**DefaultAPI_postRemoveUserVerification**](docs/DefaultAPI.md#DefaultAPI_postRemoveUserVerification) | **POST** /removeUserVerification | removeUserVerification
*DefaultAPI* | [**DefaultAPI_postReopenForumTopic**](docs/DefaultAPI.md#DefaultAPI_postReopenForumTopic) | **POST** /reopenForumTopic | reopenForumTopic
*DefaultAPI* | [**DefaultAPI_postReopenGeneralForumTopic**](docs/DefaultAPI.md#DefaultAPI_postReopenGeneralForumTopic) | **POST** /reopenGeneralForumTopic | reopenGeneralForumTopic
*DefaultAPI* | [**DefaultAPI_postReplaceStickerInSet**](docs/DefaultAPI.md#DefaultAPI_postReplaceStickerInSet) | **POST** /replaceStickerInSet | replaceStickerInSet
*DefaultAPI* | [**DefaultAPI_postRestrictChatMember**](docs/DefaultAPI.md#DefaultAPI_postRestrictChatMember) | **POST** /restrictChatMember | restrictChatMember
*DefaultAPI* | [**DefaultAPI_postRevokeChatInviteLink**](docs/DefaultAPI.md#DefaultAPI_postRevokeChatInviteLink) | **POST** /revokeChatInviteLink | revokeChatInviteLink
*DefaultAPI* | [**DefaultAPI_postSavePreparedInlineMessage**](docs/DefaultAPI.md#DefaultAPI_postSavePreparedInlineMessage) | **POST** /savePreparedInlineMessage | savePreparedInlineMessage
*DefaultAPI* | [**DefaultAPI_postSendAnimation**](docs/DefaultAPI.md#DefaultAPI_postSendAnimation) | **POST** /sendAnimation | sendAnimation
*DefaultAPI* | [**DefaultAPI_postSendAudio**](docs/DefaultAPI.md#DefaultAPI_postSendAudio) | **POST** /sendAudio | sendAudio
*DefaultAPI* | [**DefaultAPI_postSendChatAction**](docs/DefaultAPI.md#DefaultAPI_postSendChatAction) | **POST** /sendChatAction | sendChatAction
*DefaultAPI* | [**DefaultAPI_postSendContact**](docs/DefaultAPI.md#DefaultAPI_postSendContact) | **POST** /sendContact | sendContact
*DefaultAPI* | [**DefaultAPI_postSendDice**](docs/DefaultAPI.md#DefaultAPI_postSendDice) | **POST** /sendDice | sendDice
*DefaultAPI* | [**DefaultAPI_postSendDocument**](docs/DefaultAPI.md#DefaultAPI_postSendDocument) | **POST** /sendDocument | sendDocument
*DefaultAPI* | [**DefaultAPI_postSendGame**](docs/DefaultAPI.md#DefaultAPI_postSendGame) | **POST** /sendGame | sendGame
*DefaultAPI* | [**DefaultAPI_postSendGift**](docs/DefaultAPI.md#DefaultAPI_postSendGift) | **POST** /sendGift | sendGift
*DefaultAPI* | [**DefaultAPI_postSendInvoice**](docs/DefaultAPI.md#DefaultAPI_postSendInvoice) | **POST** /sendInvoice | sendInvoice
*DefaultAPI* | [**DefaultAPI_postSendLocation**](docs/DefaultAPI.md#DefaultAPI_postSendLocation) | **POST** /sendLocation | sendLocation
*DefaultAPI* | [**DefaultAPI_postSendMediaGroup**](docs/DefaultAPI.md#DefaultAPI_postSendMediaGroup) | **POST** /sendMediaGroup | sendMediaGroup
*DefaultAPI* | [**DefaultAPI_postSendMessage**](docs/DefaultAPI.md#DefaultAPI_postSendMessage) | **POST** /sendMessage | sendMessage
*DefaultAPI* | [**DefaultAPI_postSendPaidMedia**](docs/DefaultAPI.md#DefaultAPI_postSendPaidMedia) | **POST** /sendPaidMedia | sendPaidMedia
*DefaultAPI* | [**DefaultAPI_postSendPhoto**](docs/DefaultAPI.md#DefaultAPI_postSendPhoto) | **POST** /sendPhoto | sendPhoto
*DefaultAPI* | [**DefaultAPI_postSendPoll**](docs/DefaultAPI.md#DefaultAPI_postSendPoll) | **POST** /sendPoll | sendPoll
*DefaultAPI* | [**DefaultAPI_postSendSticker**](docs/DefaultAPI.md#DefaultAPI_postSendSticker) | **POST** /sendSticker | sendSticker
*DefaultAPI* | [**DefaultAPI_postSendVenue**](docs/DefaultAPI.md#DefaultAPI_postSendVenue) | **POST** /sendVenue | sendVenue
*DefaultAPI* | [**DefaultAPI_postSendVideo**](docs/DefaultAPI.md#DefaultAPI_postSendVideo) | **POST** /sendVideo | sendVideo
*DefaultAPI* | [**DefaultAPI_postSendVideoNote**](docs/DefaultAPI.md#DefaultAPI_postSendVideoNote) | **POST** /sendVideoNote | sendVideoNote
*DefaultAPI* | [**DefaultAPI_postSendVoice**](docs/DefaultAPI.md#DefaultAPI_postSendVoice) | **POST** /sendVoice | sendVoice
*DefaultAPI* | [**DefaultAPI_postSetBusinessAccountBio**](docs/DefaultAPI.md#DefaultAPI_postSetBusinessAccountBio) | **POST** /setBusinessAccountBio | setBusinessAccountBio
*DefaultAPI* | [**DefaultAPI_postSetBusinessAccountGiftSettings**](docs/DefaultAPI.md#DefaultAPI_postSetBusinessAccountGiftSettings) | **POST** /setBusinessAccountGiftSettings | setBusinessAccountGiftSettings
*DefaultAPI* | [**DefaultAPI_postSetBusinessAccountName**](docs/DefaultAPI.md#DefaultAPI_postSetBusinessAccountName) | **POST** /setBusinessAccountName | setBusinessAccountName
*DefaultAPI* | [**DefaultAPI_postSetBusinessAccountProfilePhoto**](docs/DefaultAPI.md#DefaultAPI_postSetBusinessAccountProfilePhoto) | **POST** /setBusinessAccountProfilePhoto | setBusinessAccountProfilePhoto
*DefaultAPI* | [**DefaultAPI_postSetBusinessAccountUsername**](docs/DefaultAPI.md#DefaultAPI_postSetBusinessAccountUsername) | **POST** /setBusinessAccountUsername | setBusinessAccountUsername
*DefaultAPI* | [**DefaultAPI_postSetChatAdministratorCustomTitle**](docs/DefaultAPI.md#DefaultAPI_postSetChatAdministratorCustomTitle) | **POST** /setChatAdministratorCustomTitle | setChatAdministratorCustomTitle
*DefaultAPI* | [**DefaultAPI_postSetChatDescription**](docs/DefaultAPI.md#DefaultAPI_postSetChatDescription) | **POST** /setChatDescription | setChatDescription
*DefaultAPI* | [**DefaultAPI_postSetChatMenuButton**](docs/DefaultAPI.md#DefaultAPI_postSetChatMenuButton) | **POST** /setChatMenuButton | setChatMenuButton
*DefaultAPI* | [**DefaultAPI_postSetChatPermissions**](docs/DefaultAPI.md#DefaultAPI_postSetChatPermissions) | **POST** /setChatPermissions | setChatPermissions
*DefaultAPI* | [**DefaultAPI_postSetChatPhoto**](docs/DefaultAPI.md#DefaultAPI_postSetChatPhoto) | **POST** /setChatPhoto | setChatPhoto
*DefaultAPI* | [**DefaultAPI_postSetChatStickerSet**](docs/DefaultAPI.md#DefaultAPI_postSetChatStickerSet) | **POST** /setChatStickerSet | setChatStickerSet
*DefaultAPI* | [**DefaultAPI_postSetChatTitle**](docs/DefaultAPI.md#DefaultAPI_postSetChatTitle) | **POST** /setChatTitle | setChatTitle
*DefaultAPI* | [**DefaultAPI_postSetCustomEmojiStickerSetThumbnail**](docs/DefaultAPI.md#DefaultAPI_postSetCustomEmojiStickerSetThumbnail) | **POST** /setCustomEmojiStickerSetThumbnail | setCustomEmojiStickerSetThumbnail
*DefaultAPI* | [**DefaultAPI_postSetGameScore**](docs/DefaultAPI.md#DefaultAPI_postSetGameScore) | **POST** /setGameScore | setGameScore
*DefaultAPI* | [**DefaultAPI_postSetMessageReaction**](docs/DefaultAPI.md#DefaultAPI_postSetMessageReaction) | **POST** /setMessageReaction | setMessageReaction
*DefaultAPI* | [**DefaultAPI_postSetMyCommands**](docs/DefaultAPI.md#DefaultAPI_postSetMyCommands) | **POST** /setMyCommands | setMyCommands
*DefaultAPI* | [**DefaultAPI_postSetMyDefaultAdministratorRights**](docs/DefaultAPI.md#DefaultAPI_postSetMyDefaultAdministratorRights) | **POST** /setMyDefaultAdministratorRights | setMyDefaultAdministratorRights
*DefaultAPI* | [**DefaultAPI_postSetMyDescription**](docs/DefaultAPI.md#DefaultAPI_postSetMyDescription) | **POST** /setMyDescription | setMyDescription
*DefaultAPI* | [**DefaultAPI_postSetMyName**](docs/DefaultAPI.md#DefaultAPI_postSetMyName) | **POST** /setMyName | setMyName
*DefaultAPI* | [**DefaultAPI_postSetMyShortDescription**](docs/DefaultAPI.md#DefaultAPI_postSetMyShortDescription) | **POST** /setMyShortDescription | setMyShortDescription
*DefaultAPI* | [**DefaultAPI_postSetPassportDataErrors**](docs/DefaultAPI.md#DefaultAPI_postSetPassportDataErrors) | **POST** /setPassportDataErrors | setPassportDataErrors
*DefaultAPI* | [**DefaultAPI_postSetStickerEmojiList**](docs/DefaultAPI.md#DefaultAPI_postSetStickerEmojiList) | **POST** /setStickerEmojiList | setStickerEmojiList
*DefaultAPI* | [**DefaultAPI_postSetStickerKeywords**](docs/DefaultAPI.md#DefaultAPI_postSetStickerKeywords) | **POST** /setStickerKeywords | setStickerKeywords
*DefaultAPI* | [**DefaultAPI_postSetStickerMaskPosition**](docs/DefaultAPI.md#DefaultAPI_postSetStickerMaskPosition) | **POST** /setStickerMaskPosition | setStickerMaskPosition
*DefaultAPI* | [**DefaultAPI_postSetStickerPositionInSet**](docs/DefaultAPI.md#DefaultAPI_postSetStickerPositionInSet) | **POST** /setStickerPositionInSet | setStickerPositionInSet
*DefaultAPI* | [**DefaultAPI_postSetStickerSetThumbnail**](docs/DefaultAPI.md#DefaultAPI_postSetStickerSetThumbnail) | **POST** /setStickerSetThumbnail | setStickerSetThumbnail
*DefaultAPI* | [**DefaultAPI_postSetStickerSetTitle**](docs/DefaultAPI.md#DefaultAPI_postSetStickerSetTitle) | **POST** /setStickerSetTitle | setStickerSetTitle
*DefaultAPI* | [**DefaultAPI_postSetUserEmojiStatus**](docs/DefaultAPI.md#DefaultAPI_postSetUserEmojiStatus) | **POST** /setUserEmojiStatus | setUserEmojiStatus
*DefaultAPI* | [**DefaultAPI_postSetWebhook**](docs/DefaultAPI.md#DefaultAPI_postSetWebhook) | **POST** /setWebhook | setWebhook
*DefaultAPI* | [**DefaultAPI_postStopMessageLiveLocation**](docs/DefaultAPI.md#DefaultAPI_postStopMessageLiveLocation) | **POST** /stopMessageLiveLocation | stopMessageLiveLocation
*DefaultAPI* | [**DefaultAPI_postStopPoll**](docs/DefaultAPI.md#DefaultAPI_postStopPoll) | **POST** /stopPoll | stopPoll
*DefaultAPI* | [**DefaultAPI_postTransferBusinessAccountStars**](docs/DefaultAPI.md#DefaultAPI_postTransferBusinessAccountStars) | **POST** /transferBusinessAccountStars | transferBusinessAccountStars
*DefaultAPI* | [**DefaultAPI_postTransferGift**](docs/DefaultAPI.md#DefaultAPI_postTransferGift) | **POST** /transferGift | transferGift
*DefaultAPI* | [**DefaultAPI_postUnbanChatMember**](docs/DefaultAPI.md#DefaultAPI_postUnbanChatMember) | **POST** /unbanChatMember | unbanChatMember
*DefaultAPI* | [**DefaultAPI_postUnbanChatSenderChat**](docs/DefaultAPI.md#DefaultAPI_postUnbanChatSenderChat) | **POST** /unbanChatSenderChat | unbanChatSenderChat
*DefaultAPI* | [**DefaultAPI_postUnhideGeneralForumTopic**](docs/DefaultAPI.md#DefaultAPI_postUnhideGeneralForumTopic) | **POST** /unhideGeneralForumTopic | unhideGeneralForumTopic
*DefaultAPI* | [**DefaultAPI_postUnpinAllChatMessages**](docs/DefaultAPI.md#DefaultAPI_postUnpinAllChatMessages) | **POST** /unpinAllChatMessages | unpinAllChatMessages
*DefaultAPI* | [**DefaultAPI_postUnpinAllForumTopicMessages**](docs/DefaultAPI.md#DefaultAPI_postUnpinAllForumTopicMessages) | **POST** /unpinAllForumTopicMessages | unpinAllForumTopicMessages
*DefaultAPI* | [**DefaultAPI_postUnpinAllGeneralForumTopicMessages**](docs/DefaultAPI.md#DefaultAPI_postUnpinAllGeneralForumTopicMessages) | **POST** /unpinAllGeneralForumTopicMessages | unpinAllGeneralForumTopicMessages
*DefaultAPI* | [**DefaultAPI_postUnpinChatMessage**](docs/DefaultAPI.md#DefaultAPI_postUnpinChatMessage) | **POST** /unpinChatMessage | unpinChatMessage
*DefaultAPI* | [**DefaultAPI_postUpgradeGift**](docs/DefaultAPI.md#DefaultAPI_postUpgradeGift) | **POST** /upgradeGift | upgradeGift
*DefaultAPI* | [**DefaultAPI_postUploadStickerFile**](docs/DefaultAPI.md#DefaultAPI_postUploadStickerFile) | **POST** /uploadStickerFile | uploadStickerFile
*DefaultAPI* | [**DefaultAPI_postVerifyChat**](docs/DefaultAPI.md#DefaultAPI_postVerifyChat) | **POST** /verifyChat | verifyChat
*DefaultAPI* | [**DefaultAPI_postVerifyUser**](docs/DefaultAPI.md#DefaultAPI_postVerifyUser) | **POST** /verifyUser | verifyUser


## Documentation for Models

 - [accepted_gift_types_t](docs/accepted_gift_types.md)
 - [add_sticker_to_set_request_t](docs/add_sticker_to_set_request.md)
 - [add_sticker_to_set_response_t](docs/add_sticker_to_set_response.md)
 - [affiliate_info_t](docs/affiliate_info.md)
 - [animation_t](docs/animation.md)
 - [answer_callback_query_request_t](docs/answer_callback_query_request.md)
 - [answer_callback_query_response_t](docs/answer_callback_query_response.md)
 - [answer_inline_query_request_t](docs/answer_inline_query_request.md)
 - [answer_inline_query_response_t](docs/answer_inline_query_response.md)
 - [answer_pre_checkout_query_request_t](docs/answer_pre_checkout_query_request.md)
 - [answer_pre_checkout_query_response_t](docs/answer_pre_checkout_query_response.md)
 - [answer_shipping_query_request_t](docs/answer_shipping_query_request.md)
 - [answer_shipping_query_response_t](docs/answer_shipping_query_response.md)
 - [answer_web_app_query_request_t](docs/answer_web_app_query_request.md)
 - [answer_web_app_query_response_t](docs/answer_web_app_query_response.md)
 - [approve_chat_join_request_request_t](docs/approve_chat_join_request_request.md)
 - [approve_chat_join_request_response_t](docs/approve_chat_join_request_response.md)
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
 - [ban_chat_member_request_t](docs/ban_chat_member_request.md)
 - [ban_chat_member_request_chat_id_t](docs/ban_chat_member_request_chat_id.md)
 - [ban_chat_member_response_t](docs/ban_chat_member_response.md)
 - [ban_chat_sender_chat_request_t](docs/ban_chat_sender_chat_request.md)
 - [ban_chat_sender_chat_response_t](docs/ban_chat_sender_chat_response.md)
 - [birthdate_t](docs/birthdate.md)
 - [bot_command_t](docs/bot_command.md)
 - [bot_command_scope_t](docs/bot_command_scope.md)
 - [bot_command_scope_all_chat_administrators_t](docs/bot_command_scope_all_chat_administrators.md)
 - [bot_command_scope_all_group_chats_t](docs/bot_command_scope_all_group_chats.md)
 - [bot_command_scope_all_private_chats_t](docs/bot_command_scope_all_private_chats.md)
 - [bot_command_scope_chat_t](docs/bot_command_scope_chat.md)
 - [bot_command_scope_chat_administrators_t](docs/bot_command_scope_chat_administrators.md)
 - [bot_command_scope_chat_chat_id_t](docs/bot_command_scope_chat_chat_id.md)
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
 - [close_forum_topic_request_t](docs/close_forum_topic_request.md)
 - [close_forum_topic_response_t](docs/close_forum_topic_response.md)
 - [close_general_forum_topic_request_t](docs/close_general_forum_topic_request.md)
 - [close_general_forum_topic_response_t](docs/close_general_forum_topic_response.md)
 - [close_response_t](docs/close_response.md)
 - [contact_t](docs/contact.md)
 - [convert_gift_to_stars_request_t](docs/convert_gift_to_stars_request.md)
 - [convert_gift_to_stars_response_t](docs/convert_gift_to_stars_response.md)
 - [copy_message_request_t](docs/copy_message_request.md)
 - [copy_message_response_t](docs/copy_message_response.md)
 - [copy_messages_request_t](docs/copy_messages_request.md)
 - [copy_messages_response_t](docs/copy_messages_response.md)
 - [copy_text_button_t](docs/copy_text_button.md)
 - [create_chat_invite_link_request_t](docs/create_chat_invite_link_request.md)
 - [create_chat_invite_link_response_t](docs/create_chat_invite_link_response.md)
 - [create_chat_subscription_invite_link_request_t](docs/create_chat_subscription_invite_link_request.md)
 - [create_chat_subscription_invite_link_request_chat_id_t](docs/create_chat_subscription_invite_link_request_chat_id.md)
 - [create_chat_subscription_invite_link_response_t](docs/create_chat_subscription_invite_link_response.md)
 - [create_forum_topic_request_t](docs/create_forum_topic_request.md)
 - [create_forum_topic_response_t](docs/create_forum_topic_response.md)
 - [create_invoice_link_request_t](docs/create_invoice_link_request.md)
 - [create_invoice_link_response_t](docs/create_invoice_link_response.md)
 - [create_new_sticker_set_request_t](docs/create_new_sticker_set_request.md)
 - [create_new_sticker_set_response_t](docs/create_new_sticker_set_response.md)
 - [decline_chat_join_request_request_t](docs/decline_chat_join_request_request.md)
 - [decline_chat_join_request_response_t](docs/decline_chat_join_request_response.md)
 - [delete_business_messages_request_t](docs/delete_business_messages_request.md)
 - [delete_business_messages_response_t](docs/delete_business_messages_response.md)
 - [delete_chat_photo_request_t](docs/delete_chat_photo_request.md)
 - [delete_chat_photo_response_t](docs/delete_chat_photo_response.md)
 - [delete_chat_sticker_set_request_t](docs/delete_chat_sticker_set_request.md)
 - [delete_chat_sticker_set_response_t](docs/delete_chat_sticker_set_response.md)
 - [delete_forum_topic_request_t](docs/delete_forum_topic_request.md)
 - [delete_forum_topic_response_t](docs/delete_forum_topic_response.md)
 - [delete_message_request_t](docs/delete_message_request.md)
 - [delete_message_response_t](docs/delete_message_response.md)
 - [delete_messages_request_t](docs/delete_messages_request.md)
 - [delete_messages_response_t](docs/delete_messages_response.md)
 - [delete_my_commands_request_t](docs/delete_my_commands_request.md)
 - [delete_my_commands_response_t](docs/delete_my_commands_response.md)
 - [delete_sticker_from_set_request_t](docs/delete_sticker_from_set_request.md)
 - [delete_sticker_from_set_response_t](docs/delete_sticker_from_set_response.md)
 - [delete_sticker_set_request_t](docs/delete_sticker_set_request.md)
 - [delete_sticker_set_response_t](docs/delete_sticker_set_response.md)
 - [delete_story_request_t](docs/delete_story_request.md)
 - [delete_story_response_t](docs/delete_story_response.md)
 - [delete_webhook_request_t](docs/delete_webhook_request.md)
 - [delete_webhook_response_t](docs/delete_webhook_response.md)
 - [dice_t](docs/dice.md)
 - [document_t](docs/document.md)
 - [edit_chat_invite_link_request_t](docs/edit_chat_invite_link_request.md)
 - [edit_chat_invite_link_response_t](docs/edit_chat_invite_link_response.md)
 - [edit_chat_subscription_invite_link_request_t](docs/edit_chat_subscription_invite_link_request.md)
 - [edit_chat_subscription_invite_link_response_t](docs/edit_chat_subscription_invite_link_response.md)
 - [edit_forum_topic_request_t](docs/edit_forum_topic_request.md)
 - [edit_forum_topic_response_t](docs/edit_forum_topic_response.md)
 - [edit_general_forum_topic_request_t](docs/edit_general_forum_topic_request.md)
 - [edit_general_forum_topic_response_t](docs/edit_general_forum_topic_response.md)
 - [edit_message_caption_request_t](docs/edit_message_caption_request.md)
 - [edit_message_caption_response_t](docs/edit_message_caption_response.md)
 - [edit_message_live_location_request_t](docs/edit_message_live_location_request.md)
 - [edit_message_live_location_response_t](docs/edit_message_live_location_response.md)
 - [edit_message_media_request_t](docs/edit_message_media_request.md)
 - [edit_message_media_response_t](docs/edit_message_media_response.md)
 - [edit_message_reply_markup_request_t](docs/edit_message_reply_markup_request.md)
 - [edit_message_reply_markup_response_t](docs/edit_message_reply_markup_response.md)
 - [edit_message_text_request_t](docs/edit_message_text_request.md)
 - [edit_message_text_request_chat_id_t](docs/edit_message_text_request_chat_id.md)
 - [edit_message_text_response_t](docs/edit_message_text_response.md)
 - [edit_message_text_response_result_t](docs/edit_message_text_response_result.md)
 - [edit_story_request_t](docs/edit_story_request.md)
 - [edit_story_response_t](docs/edit_story_response.md)
 - [edit_user_star_subscription_request_t](docs/edit_user_star_subscription_request.md)
 - [edit_user_star_subscription_response_t](docs/edit_user_star_subscription_response.md)
 - [encrypted_credentials_t](docs/encrypted_credentials.md)
 - [encrypted_passport_element_t](docs/encrypted_passport_element.md)
 - [error_t](docs/error.md)
 - [export_chat_invite_link_request_t](docs/export_chat_invite_link_request.md)
 - [export_chat_invite_link_response_t](docs/export_chat_invite_link_response.md)
 - [external_reply_info_t](docs/external_reply_info.md)
 - [file_t](docs/file.md)
 - [force_reply_t](docs/force_reply.md)
 - [forum_topic_t](docs/forum_topic.md)
 - [forum_topic_created_t](docs/forum_topic_created.md)
 - [forum_topic_edited_t](docs/forum_topic_edited.md)
 - [forward_message_request_t](docs/forward_message_request.md)
 - [forward_message_request_from_chat_id_t](docs/forward_message_request_from_chat_id.md)
 - [forward_message_response_t](docs/forward_message_response.md)
 - [forward_messages_request_t](docs/forward_messages_request.md)
 - [forward_messages_request_from_chat_id_t](docs/forward_messages_request_from_chat_id.md)
 - [forward_messages_response_t](docs/forward_messages_response.md)
 - [game_t](docs/game.md)
 - [game_high_score_t](docs/game_high_score.md)
 - [get_available_gifts_response_t](docs/get_available_gifts_response.md)
 - [get_business_account_gifts_request_t](docs/get_business_account_gifts_request.md)
 - [get_business_account_gifts_response_t](docs/get_business_account_gifts_response.md)
 - [get_business_account_star_balance_request_t](docs/get_business_account_star_balance_request.md)
 - [get_business_account_star_balance_response_t](docs/get_business_account_star_balance_response.md)
 - [get_business_connection_request_t](docs/get_business_connection_request.md)
 - [get_business_connection_response_t](docs/get_business_connection_response.md)
 - [get_chat_administrators_request_t](docs/get_chat_administrators_request.md)
 - [get_chat_administrators_response_t](docs/get_chat_administrators_response.md)
 - [get_chat_member_count_request_t](docs/get_chat_member_count_request.md)
 - [get_chat_member_count_response_t](docs/get_chat_member_count_response.md)
 - [get_chat_member_request_t](docs/get_chat_member_request.md)
 - [get_chat_member_response_t](docs/get_chat_member_response.md)
 - [get_chat_menu_button_request_t](docs/get_chat_menu_button_request.md)
 - [get_chat_menu_button_response_t](docs/get_chat_menu_button_response.md)
 - [get_chat_request_t](docs/get_chat_request.md)
 - [get_chat_response_t](docs/get_chat_response.md)
 - [get_custom_emoji_stickers_request_t](docs/get_custom_emoji_stickers_request.md)
 - [get_custom_emoji_stickers_response_t](docs/get_custom_emoji_stickers_response.md)
 - [get_file_request_t](docs/get_file_request.md)
 - [get_file_response_t](docs/get_file_response.md)
 - [get_forum_topic_icon_stickers_response_t](docs/get_forum_topic_icon_stickers_response.md)
 - [get_game_high_scores_request_t](docs/get_game_high_scores_request.md)
 - [get_game_high_scores_response_t](docs/get_game_high_scores_response.md)
 - [get_me_response_t](docs/get_me_response.md)
 - [get_my_commands_request_t](docs/get_my_commands_request.md)
 - [get_my_commands_response_t](docs/get_my_commands_response.md)
 - [get_my_default_administrator_rights_request_t](docs/get_my_default_administrator_rights_request.md)
 - [get_my_default_administrator_rights_response_t](docs/get_my_default_administrator_rights_response.md)
 - [get_my_description_request_t](docs/get_my_description_request.md)
 - [get_my_description_response_t](docs/get_my_description_response.md)
 - [get_my_name_request_t](docs/get_my_name_request.md)
 - [get_my_name_response_t](docs/get_my_name_response.md)
 - [get_my_short_description_request_t](docs/get_my_short_description_request.md)
 - [get_my_short_description_response_t](docs/get_my_short_description_response.md)
 - [get_star_transactions_request_t](docs/get_star_transactions_request.md)
 - [get_star_transactions_response_t](docs/get_star_transactions_response.md)
 - [get_sticker_set_request_t](docs/get_sticker_set_request.md)
 - [get_sticker_set_response_t](docs/get_sticker_set_response.md)
 - [get_updates_request_t](docs/get_updates_request.md)
 - [get_updates_response_t](docs/get_updates_response.md)
 - [get_user_chat_boosts_request_t](docs/get_user_chat_boosts_request.md)
 - [get_user_chat_boosts_request_chat_id_t](docs/get_user_chat_boosts_request_chat_id.md)
 - [get_user_chat_boosts_response_t](docs/get_user_chat_boosts_response.md)
 - [get_user_profile_photos_request_t](docs/get_user_profile_photos_request.md)
 - [get_user_profile_photos_response_t](docs/get_user_profile_photos_response.md)
 - [get_webhook_info_response_t](docs/get_webhook_info_response.md)
 - [gift_t](docs/gift.md)
 - [gift_info_t](docs/gift_info.md)
 - [gift_premium_subscription_request_t](docs/gift_premium_subscription_request.md)
 - [gift_premium_subscription_response_t](docs/gift_premium_subscription_response.md)
 - [gifts_t](docs/gifts.md)
 - [giveaway_t](docs/giveaway.md)
 - [giveaway_completed_t](docs/giveaway_completed.md)
 - [giveaway_created_t](docs/giveaway_created.md)
 - [giveaway_winners_t](docs/giveaway_winners.md)
 - [hide_general_forum_topic_request_t](docs/hide_general_forum_topic_request.md)
 - [hide_general_forum_topic_response_t](docs/hide_general_forum_topic_response.md)
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
 - [leave_chat_request_t](docs/leave_chat_request.md)
 - [leave_chat_request_chat_id_t](docs/leave_chat_request_chat_id.md)
 - [leave_chat_response_t](docs/leave_chat_response.md)
 - [link_preview_options_t](docs/link_preview_options.md)
 - [location_t](docs/location.md)
 - [location_address_t](docs/location_address.md)
 - [log_out_response_t](docs/log_out_response.md)
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
 - [pin_chat_message_request_t](docs/pin_chat_message_request.md)
 - [pin_chat_message_response_t](docs/pin_chat_message_response.md)
 - [poll_t](docs/poll.md)
 - [poll_answer_t](docs/poll_answer.md)
 - [poll_option_t](docs/poll_option.md)
 - [post_story_request_t](docs/post_story_request.md)
 - [post_story_response_t](docs/post_story_response.md)
 - [pre_checkout_query_t](docs/pre_checkout_query.md)
 - [prepared_inline_message_t](docs/prepared_inline_message.md)
 - [promote_chat_member_request_t](docs/promote_chat_member_request.md)
 - [promote_chat_member_response_t](docs/promote_chat_member_response.md)
 - [proximity_alert_triggered_t](docs/proximity_alert_triggered.md)
 - [reaction_count_t](docs/reaction_count.md)
 - [reaction_type_t](docs/reaction_type.md)
 - [reaction_type_custom_emoji_t](docs/reaction_type_custom_emoji.md)
 - [reaction_type_emoji_t](docs/reaction_type_emoji.md)
 - [reaction_type_paid_t](docs/reaction_type_paid.md)
 - [read_business_message_request_t](docs/read_business_message_request.md)
 - [read_business_message_response_t](docs/read_business_message_response.md)
 - [refund_star_payment_request_t](docs/refund_star_payment_request.md)
 - [refund_star_payment_response_t](docs/refund_star_payment_response.md)
 - [refunded_payment_t](docs/refunded_payment.md)
 - [remove_business_account_profile_photo_request_t](docs/remove_business_account_profile_photo_request.md)
 - [remove_business_account_profile_photo_response_t](docs/remove_business_account_profile_photo_response.md)
 - [remove_chat_verification_request_t](docs/remove_chat_verification_request.md)
 - [remove_chat_verification_response_t](docs/remove_chat_verification_response.md)
 - [remove_user_verification_request_t](docs/remove_user_verification_request.md)
 - [remove_user_verification_response_t](docs/remove_user_verification_response.md)
 - [reopen_forum_topic_request_t](docs/reopen_forum_topic_request.md)
 - [reopen_forum_topic_response_t](docs/reopen_forum_topic_response.md)
 - [reopen_general_forum_topic_request_t](docs/reopen_general_forum_topic_request.md)
 - [reopen_general_forum_topic_response_t](docs/reopen_general_forum_topic_response.md)
 - [replace_sticker_in_set_request_t](docs/replace_sticker_in_set_request.md)
 - [replace_sticker_in_set_response_t](docs/replace_sticker_in_set_response.md)
 - [reply_keyboard_markup_t](docs/reply_keyboard_markup.md)
 - [reply_keyboard_remove_t](docs/reply_keyboard_remove.md)
 - [reply_parameters_t](docs/reply_parameters.md)
 - [reply_parameters_chat_id_t](docs/reply_parameters_chat_id.md)
 - [response_parameters_t](docs/response_parameters.md)
 - [restrict_chat_member_request_t](docs/restrict_chat_member_request.md)
 - [restrict_chat_member_response_t](docs/restrict_chat_member_response.md)
 - [revenue_withdrawal_state_t](docs/revenue_withdrawal_state.md)
 - [revenue_withdrawal_state_failed_t](docs/revenue_withdrawal_state_failed.md)
 - [revenue_withdrawal_state_pending_t](docs/revenue_withdrawal_state_pending.md)
 - [revenue_withdrawal_state_succeeded_t](docs/revenue_withdrawal_state_succeeded.md)
 - [revoke_chat_invite_link_request_t](docs/revoke_chat_invite_link_request.md)
 - [revoke_chat_invite_link_request_chat_id_t](docs/revoke_chat_invite_link_request_chat_id.md)
 - [revoke_chat_invite_link_response_t](docs/revoke_chat_invite_link_response.md)
 - [save_prepared_inline_message_request_t](docs/save_prepared_inline_message_request.md)
 - [save_prepared_inline_message_response_t](docs/save_prepared_inline_message_response.md)
 - [send_animation_request_t](docs/send_animation_request.md)
 - [send_animation_response_t](docs/send_animation_response.md)
 - [send_audio_request_t](docs/send_audio_request.md)
 - [send_audio_response_t](docs/send_audio_response.md)
 - [send_chat_action_request_t](docs/send_chat_action_request.md)
 - [send_chat_action_response_t](docs/send_chat_action_response.md)
 - [send_contact_request_t](docs/send_contact_request.md)
 - [send_contact_response_t](docs/send_contact_response.md)
 - [send_dice_request_t](docs/send_dice_request.md)
 - [send_dice_response_t](docs/send_dice_response.md)
 - [send_document_request_t](docs/send_document_request.md)
 - [send_document_response_t](docs/send_document_response.md)
 - [send_game_request_t](docs/send_game_request.md)
 - [send_game_response_t](docs/send_game_response.md)
 - [send_gift_request_t](docs/send_gift_request.md)
 - [send_gift_request_chat_id_t](docs/send_gift_request_chat_id.md)
 - [send_gift_response_t](docs/send_gift_response.md)
 - [send_invoice_request_t](docs/send_invoice_request.md)
 - [send_invoice_response_t](docs/send_invoice_response.md)
 - [send_location_request_t](docs/send_location_request.md)
 - [send_location_response_t](docs/send_location_response.md)
 - [send_media_group_request_t](docs/send_media_group_request.md)
 - [send_media_group_request_media_inner_t](docs/send_media_group_request_media_inner.md)
 - [send_media_group_response_t](docs/send_media_group_response.md)
 - [send_message_request_t](docs/send_message_request.md)
 - [send_message_request_chat_id_t](docs/send_message_request_chat_id.md)
 - [send_message_request_reply_markup_t](docs/send_message_request_reply_markup.md)
 - [send_message_response_t](docs/send_message_response.md)
 - [send_paid_media_request_t](docs/send_paid_media_request.md)
 - [send_paid_media_request_chat_id_t](docs/send_paid_media_request_chat_id.md)
 - [send_paid_media_response_t](docs/send_paid_media_response.md)
 - [send_photo_request_t](docs/send_photo_request.md)
 - [send_photo_response_t](docs/send_photo_response.md)
 - [send_poll_request_t](docs/send_poll_request.md)
 - [send_poll_response_t](docs/send_poll_response.md)
 - [send_sticker_request_t](docs/send_sticker_request.md)
 - [send_sticker_response_t](docs/send_sticker_response.md)
 - [send_venue_request_t](docs/send_venue_request.md)
 - [send_venue_response_t](docs/send_venue_response.md)
 - [send_video_note_request_t](docs/send_video_note_request.md)
 - [send_video_note_response_t](docs/send_video_note_response.md)
 - [send_video_request_t](docs/send_video_request.md)
 - [send_video_response_t](docs/send_video_response.md)
 - [send_voice_request_t](docs/send_voice_request.md)
 - [send_voice_response_t](docs/send_voice_response.md)
 - [sent_web_app_message_t](docs/sent_web_app_message.md)
 - [set_business_account_bio_request_t](docs/set_business_account_bio_request.md)
 - [set_business_account_bio_response_t](docs/set_business_account_bio_response.md)
 - [set_business_account_gift_settings_request_t](docs/set_business_account_gift_settings_request.md)
 - [set_business_account_gift_settings_response_t](docs/set_business_account_gift_settings_response.md)
 - [set_business_account_name_request_t](docs/set_business_account_name_request.md)
 - [set_business_account_name_response_t](docs/set_business_account_name_response.md)
 - [set_business_account_profile_photo_request_t](docs/set_business_account_profile_photo_request.md)
 - [set_business_account_profile_photo_response_t](docs/set_business_account_profile_photo_response.md)
 - [set_business_account_username_request_t](docs/set_business_account_username_request.md)
 - [set_business_account_username_response_t](docs/set_business_account_username_response.md)
 - [set_chat_administrator_custom_title_request_t](docs/set_chat_administrator_custom_title_request.md)
 - [set_chat_administrator_custom_title_response_t](docs/set_chat_administrator_custom_title_response.md)
 - [set_chat_description_request_t](docs/set_chat_description_request.md)
 - [set_chat_description_response_t](docs/set_chat_description_response.md)
 - [set_chat_menu_button_request_t](docs/set_chat_menu_button_request.md)
 - [set_chat_menu_button_response_t](docs/set_chat_menu_button_response.md)
 - [set_chat_permissions_request_t](docs/set_chat_permissions_request.md)
 - [set_chat_permissions_response_t](docs/set_chat_permissions_response.md)
 - [set_chat_photo_request_t](docs/set_chat_photo_request.md)
 - [set_chat_photo_response_t](docs/set_chat_photo_response.md)
 - [set_chat_sticker_set_request_t](docs/set_chat_sticker_set_request.md)
 - [set_chat_sticker_set_response_t](docs/set_chat_sticker_set_response.md)
 - [set_chat_title_request_t](docs/set_chat_title_request.md)
 - [set_chat_title_response_t](docs/set_chat_title_response.md)
 - [set_custom_emoji_sticker_set_thumbnail_request_t](docs/set_custom_emoji_sticker_set_thumbnail_request.md)
 - [set_custom_emoji_sticker_set_thumbnail_response_t](docs/set_custom_emoji_sticker_set_thumbnail_response.md)
 - [set_game_score_request_t](docs/set_game_score_request.md)
 - [set_game_score_response_t](docs/set_game_score_response.md)
 - [set_message_reaction_request_t](docs/set_message_reaction_request.md)
 - [set_message_reaction_response_t](docs/set_message_reaction_response.md)
 - [set_my_commands_request_t](docs/set_my_commands_request.md)
 - [set_my_commands_response_t](docs/set_my_commands_response.md)
 - [set_my_default_administrator_rights_request_t](docs/set_my_default_administrator_rights_request.md)
 - [set_my_default_administrator_rights_response_t](docs/set_my_default_administrator_rights_response.md)
 - [set_my_description_request_t](docs/set_my_description_request.md)
 - [set_my_description_response_t](docs/set_my_description_response.md)
 - [set_my_name_request_t](docs/set_my_name_request.md)
 - [set_my_name_response_t](docs/set_my_name_response.md)
 - [set_my_short_description_request_t](docs/set_my_short_description_request.md)
 - [set_my_short_description_response_t](docs/set_my_short_description_response.md)
 - [set_passport_data_errors_request_t](docs/set_passport_data_errors_request.md)
 - [set_passport_data_errors_response_t](docs/set_passport_data_errors_response.md)
 - [set_sticker_emoji_list_request_t](docs/set_sticker_emoji_list_request.md)
 - [set_sticker_emoji_list_response_t](docs/set_sticker_emoji_list_response.md)
 - [set_sticker_keywords_request_t](docs/set_sticker_keywords_request.md)
 - [set_sticker_keywords_response_t](docs/set_sticker_keywords_response.md)
 - [set_sticker_mask_position_request_t](docs/set_sticker_mask_position_request.md)
 - [set_sticker_mask_position_response_t](docs/set_sticker_mask_position_response.md)
 - [set_sticker_position_in_set_request_t](docs/set_sticker_position_in_set_request.md)
 - [set_sticker_position_in_set_response_t](docs/set_sticker_position_in_set_response.md)
 - [set_sticker_set_thumbnail_request_t](docs/set_sticker_set_thumbnail_request.md)
 - [set_sticker_set_thumbnail_response_t](docs/set_sticker_set_thumbnail_response.md)
 - [set_sticker_set_title_request_t](docs/set_sticker_set_title_request.md)
 - [set_sticker_set_title_response_t](docs/set_sticker_set_title_response.md)
 - [set_user_emoji_status_request_t](docs/set_user_emoji_status_request.md)
 - [set_user_emoji_status_response_t](docs/set_user_emoji_status_response.md)
 - [set_webhook_request_t](docs/set_webhook_request.md)
 - [set_webhook_response_t](docs/set_webhook_response.md)
 - [shared_user_t](docs/shared_user.md)
 - [shipping_address_t](docs/shipping_address.md)
 - [shipping_option_t](docs/shipping_option.md)
 - [shipping_query_t](docs/shipping_query.md)
 - [star_amount_t](docs/star_amount.md)
 - [star_transaction_t](docs/star_transaction.md)
 - [star_transactions_t](docs/star_transactions.md)
 - [sticker_t](docs/sticker.md)
 - [sticker_set_t](docs/sticker_set.md)
 - [stop_message_live_location_request_t](docs/stop_message_live_location_request.md)
 - [stop_message_live_location_response_t](docs/stop_message_live_location_response.md)
 - [stop_poll_request_t](docs/stop_poll_request.md)
 - [stop_poll_response_t](docs/stop_poll_response.md)
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
 - [transfer_business_account_stars_request_t](docs/transfer_business_account_stars_request.md)
 - [transfer_business_account_stars_response_t](docs/transfer_business_account_stars_response.md)
 - [transfer_gift_request_t](docs/transfer_gift_request.md)
 - [transfer_gift_response_t](docs/transfer_gift_response.md)
 - [unban_chat_member_request_t](docs/unban_chat_member_request.md)
 - [unban_chat_member_response_t](docs/unban_chat_member_response.md)
 - [unban_chat_sender_chat_request_t](docs/unban_chat_sender_chat_request.md)
 - [unban_chat_sender_chat_response_t](docs/unban_chat_sender_chat_response.md)
 - [unhide_general_forum_topic_request_t](docs/unhide_general_forum_topic_request.md)
 - [unhide_general_forum_topic_response_t](docs/unhide_general_forum_topic_response.md)
 - [unique_gift_t](docs/unique_gift.md)
 - [unique_gift_backdrop_t](docs/unique_gift_backdrop.md)
 - [unique_gift_backdrop_colors_t](docs/unique_gift_backdrop_colors.md)
 - [unique_gift_info_t](docs/unique_gift_info.md)
 - [unique_gift_model_t](docs/unique_gift_model.md)
 - [unique_gift_symbol_t](docs/unique_gift_symbol.md)
 - [unpin_all_chat_messages_request_t](docs/unpin_all_chat_messages_request.md)
 - [unpin_all_chat_messages_response_t](docs/unpin_all_chat_messages_response.md)
 - [unpin_all_forum_topic_messages_request_t](docs/unpin_all_forum_topic_messages_request.md)
 - [unpin_all_forum_topic_messages_response_t](docs/unpin_all_forum_topic_messages_response.md)
 - [unpin_all_general_forum_topic_messages_request_t](docs/unpin_all_general_forum_topic_messages_request.md)
 - [unpin_all_general_forum_topic_messages_response_t](docs/unpin_all_general_forum_topic_messages_response.md)
 - [unpin_chat_message_request_t](docs/unpin_chat_message_request.md)
 - [unpin_chat_message_response_t](docs/unpin_chat_message_response.md)
 - [update_t](docs/update.md)
 - [upgrade_gift_request_t](docs/upgrade_gift_request.md)
 - [upgrade_gift_response_t](docs/upgrade_gift_response.md)
 - [upload_sticker_file_request_t](docs/upload_sticker_file_request.md)
 - [upload_sticker_file_response_t](docs/upload_sticker_file_response.md)
 - [user_t](docs/user.md)
 - [user_chat_boosts_t](docs/user_chat_boosts.md)
 - [user_profile_photos_t](docs/user_profile_photos.md)
 - [users_shared_t](docs/users_shared.md)
 - [venue_t](docs/venue.md)
 - [verify_chat_request_t](docs/verify_chat_request.md)
 - [verify_chat_response_t](docs/verify_chat_response.md)
 - [verify_user_request_t](docs/verify_user_request.md)
 - [verify_user_response_t](docs/verify_user_response.md)
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

gitctrlx@gmail.com

