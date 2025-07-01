# external_reply_info_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**origin** | [**message_origin_t**](message_origin.md) \* |  | 
**chat** | [**chat_t**](chat.md) \* |  | [optional] 
**message_id** | **int** | *Optional*. Unique message identifier inside the original chat. Available only if the original chat is a supergroup or a channel. | [optional] 
**link_preview_options** | [**link_preview_options_t**](link_preview_options.md) \* |  | [optional] 
**animation** | [**animation_t**](animation.md) \* |  | [optional] 
**audio** | [**audio_t**](audio.md) \* |  | [optional] 
**document** | [**document_t**](document.md) \* |  | [optional] 
**paid_media** | [**paid_media_info_t**](paid_media_info.md) \* |  | [optional] 
**photo** | [**list_t**](photo_size.md) \* | *Optional*. Message is a photo, available sizes of the photo | [optional] 
**sticker** | [**sticker_t**](sticker.md) \* |  | [optional] 
**story** | [**story_t**](story.md) \* |  | [optional] 
**video** | [**video_t**](video.md) \* |  | [optional] 
**video_note** | [**video_note_t**](video_note.md) \* |  | [optional] 
**voice** | [**voice_t**](voice.md) \* |  | [optional] 
**has_media_spoiler** | **int** | *Optional*. *True*, if the message media is covered by a spoiler animation | [optional] [default to true]
**contact** | [**contact_t**](contact.md) \* |  | [optional] 
**dice** | [**dice_t**](dice.md) \* |  | [optional] 
**game** | [**game_t**](game.md) \* |  | [optional] 
**giveaway** | [**giveaway_t**](giveaway.md) \* |  | [optional] 
**giveaway_winners** | [**giveaway_winners_t**](giveaway_winners.md) \* |  | [optional] 
**invoice** | [**invoice_t**](invoice.md) \* |  | [optional] 
**location** | [**location_t**](location.md) \* |  | [optional] 
**poll** | [**poll_t**](poll.md) \* |  | [optional] 
**venue** | [**venue_t**](venue.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


