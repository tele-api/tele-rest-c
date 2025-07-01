# poll_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**id** | **char \*** | Unique poll identifier | 
**question** | **char \*** | Poll question, 1-300 characters | 
**options** | [**list_t**](poll_option.md) \* | List of poll options | 
**total_voter_count** | **int** | Total number of users that voted in the poll | 
**is_closed** | **int** | *True*, if the poll is closed | 
**is_anonymous** | **int** | *True*, if the poll is anonymous | 
**type** | **telegram_bot_api_poll_TYPE_e** | Poll type, currently can be “regular” or “quiz” | 
**allows_multiple_answers** | **int** | *True*, if the poll allows multiple answers | 
**question_entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities that appear in the *question*. Currently, only custom emoji entities are allowed in poll questions | [optional] 
**correct_option_id** | **int** | *Optional*. 0-based identifier of the correct answer option. Available only for polls in the quiz mode, which are closed, or was sent (not forwarded) by the bot or to the private chat with the bot. | [optional] 
**explanation** | **char \*** | *Optional*. Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-200 characters | [optional] 
**explanation_entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities like usernames, URLs, bot commands, etc. that appear in the *explanation* | [optional] 
**open_period** | **int** | *Optional*. Amount of time in seconds the poll will be active after creation | [optional] 
**close_date** | **int** | *Optional*. Point in time (Unix timestamp) when the poll will be automatically closed | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


