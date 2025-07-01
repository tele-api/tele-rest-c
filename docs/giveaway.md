# giveaway_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**chats** | [**list_t**](chat.md) \* | The list of chats which the user must join to participate in the giveaway | 
**winners_selection_date** | **int** | Point in time (Unix timestamp) when winners of the giveaway will be selected | 
**winner_count** | **int** | The number of users which are supposed to be selected as winners of the giveaway | 
**only_new_members** | **int** | *Optional*. *True*, if only users who join the chats after the giveaway started should be eligible to win | [optional] [default to true]
**has_public_winners** | **int** | *Optional*. *True*, if the list of giveaway winners will be visible to everyone | [optional] [default to true]
**prize_description** | **char \*** | *Optional*. Description of additional giveaway prize | [optional] 
**country_codes** | **list_t \*** | *Optional*. A list of two-letter [ISO 3166-1 alpha-2](https://en.wikipedia.org/wiki/ISO_3166-1_alpha-2) country codes indicating the countries from which eligible users for the giveaway must come. If empty, then all users can participate in the giveaway. Users with a phone number that was bought on Fragment can always participate in giveaways. | [optional] 
**prize_star_count** | **int** | *Optional*. The number of Telegram Stars to be split between giveaway winners; for Telegram Star giveaways only | [optional] 
**premium_subscription_month_count** | **int** | *Optional*. The number of months the Telegram Premium subscription won from the giveaway will be active for; for Telegram Premium giveaways only | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


