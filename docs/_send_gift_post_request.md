# _send_gift_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**gift_id** | **char \*** | Identifier of the gift | 
**user_id** | **int** | Required if *chat\\_id* is not specified. Unique identifier of the target user who will receive the gift. | [optional] 
**chat_id** | [**_send_gift_post_request_chat_id_t**](_send_gift_post_request_chat_id.md) \* |  | [optional] 
**pay_for_upgrade** | **int** | Pass *True* to pay for the gift upgrade from the bot&#39;s balance, thereby making the upgrade free for the receiver | [optional] 
**text** | **char \*** | Text that will be shown along with the gift; 0-128 characters | [optional] 
**text_parse_mode** | **char \*** | Mode for parsing entities in the text. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. Entities other than “bold”, “italic”, “underline”, “strikethrough”, “spoiler”, and “custom\\_emoji” are ignored. | [optional] 
**text_entities** | [**list_t**](message_entity.md) \* | A JSON-serialized list of special entities that appear in the gift text. It can be specified instead of *text\\_parse\\_mode*. Entities other than “bold”, “italic”, “underline”, “strikethrough”, “spoiler”, and “custom\\_emoji” are ignored. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


