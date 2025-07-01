# giveaway_winners_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chat** | [**chat_t**](chat.md) \* |  | 
**giveaway_message_id** | **int** | Identifier of the message with the giveaway in the chat | 
**winners_selection_date** | **int** | Point in time (Unix timestamp) when winners of the giveaway were selected | 
**winner_count** | **int** | Total number of winners in the giveaway | 
**winners** | [**list_t**](user.md) \* | List of up to 100 winners of the giveaway | 
**additional_chat_count** | **int** | *Optional*. The number of other chats the user had to join in order to be eligible for the giveaway | [optional] 
**prize_star_count** | **int** | *Optional*. The number of Telegram Stars that were split between giveaway winners; for Telegram Star giveaways only | [optional] 
**premium_subscription_month_count** | **int** | *Optional*. The number of months the Telegram Premium subscription won from the giveaway will be active for; for Telegram Premium giveaways only | [optional] 
**unclaimed_prize_count** | **int** | *Optional*. Number of undistributed prizes | [optional] 
**only_new_members** | **int** | *Optional*. *True*, if only users who had joined the chats after the giveaway started were eligible to win | [optional] [default to true]
**was_refunded** | **int** | *Optional*. *True*, if the giveaway was canceled because the payment for it was refunded | [optional] [default to true]
**prize_description** | **char \*** | *Optional*. Description of additional giveaway prize | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


