# input_poll_option_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | **char \*** | Option text, 1-100 characters | 
**text_parse_mode** | **char \*** | *Optional*. Mode for parsing entities in the text. See [formatting options](https://core.telegram.org/bots/api/#formatting-options) for more details. Currently, only custom emoji entities are allowed | [optional] 
**text_entities** | [**list_t**](message_entity.md) \* | *Optional*. A JSON-serialized list of special entities that appear in the poll option text. It can be specified instead of *text\\_parse\\_mode* | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


