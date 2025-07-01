# text_quote_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**text** | **char \*** | Text of the quoted part of a message that is replied to by the given message | 
**position** | **int** | Approximate quote position in the original message in UTF-16 code units as specified by the sender | 
**entities** | [**list_t**](message_entity.md) \* | *Optional*. Special entities that appear in the quote. Currently, only *bold*, *italic*, *underline*, *strikethrough*, *spoiler*, and *custom\\_emoji* entities are kept in quotes. | [optional] 
**is_manual** | **int** | *Optional*. True, if the quote was chosen manually by the message sender. Otherwise, the quote was added automatically by the server. | [optional] [default to true]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


