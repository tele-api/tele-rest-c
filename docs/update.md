# update_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**update_id** | **int** | The update&#39;s unique identifier. Update identifiers start from a certain positive number and increase sequentially. This identifier becomes especially handy if you&#39;re using [webhooks](https://core.telegram.org/bots/api/#setwebhook), since it allows you to ignore repeated updates or to restore the correct update sequence, should they get out of order. If there are no new updates for at least a week, then identifier of the next update will be chosen randomly instead of sequentially. | 
**message** | [**message_t**](message.md) \* |  | [optional] 
**edited_message** | [**message_t**](message.md) \* |  | [optional] 
**channel_post** | [**message_t**](message.md) \* |  | [optional] 
**edited_channel_post** | [**message_t**](message.md) \* |  | [optional] 
**business_connection** | [**business_connection_t**](business_connection.md) \* |  | [optional] 
**business_message** | [**message_t**](message.md) \* |  | [optional] 
**edited_business_message** | [**message_t**](message.md) \* |  | [optional] 
**deleted_business_messages** | [**business_messages_deleted_t**](business_messages_deleted.md) \* |  | [optional] 
**message_reaction** | [**message_reaction_updated_t**](message_reaction_updated.md) \* |  | [optional] 
**message_reaction_count** | [**message_reaction_count_updated_t**](message_reaction_count_updated.md) \* |  | [optional] 
**inline_query** | [**inline_query_t**](inline_query.md) \* |  | [optional] 
**chosen_inline_result** | [**chosen_inline_result_t**](chosen_inline_result.md) \* |  | [optional] 
**callback_query** | [**callback_query_t**](callback_query.md) \* |  | [optional] 
**shipping_query** | [**shipping_query_t**](shipping_query.md) \* |  | [optional] 
**pre_checkout_query** | [**pre_checkout_query_t**](pre_checkout_query.md) \* |  | [optional] 
**purchased_paid_media** | [**paid_media_purchased_t**](paid_media_purchased.md) \* |  | [optional] 
**poll** | [**poll_t**](poll.md) \* |  | [optional] 
**poll_answer** | [**poll_answer_t**](poll_answer.md) \* |  | [optional] 
**my_chat_member** | [**chat_member_updated_t**](chat_member_updated.md) \* |  | [optional] 
**chat_member** | [**chat_member_updated_t**](chat_member_updated.md) \* |  | [optional] 
**chat_join_request** | [**chat_join_request_t**](chat_join_request.md) \* |  | [optional] 
**chat_boost** | [**chat_boost_updated_t**](chat_boost_updated.md) \* |  | [optional] 
**removed_chat_boost** | [**chat_boost_removed_t**](chat_boost_removed.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


