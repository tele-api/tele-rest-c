# inline_query_result_contact_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the result, must be *contact* | [default to 'contact']
**id** | **char \*** | Unique identifier for this result, 1-64 Bytes | 
**phone_number** | **char \*** | Contact&#39;s phone number | 
**first_name** | **char \*** | Contact&#39;s first name | 
**last_name** | **char \*** | *Optional*. Contact&#39;s last name | [optional] 
**vcard** | **char \*** | *Optional*. Additional data about the contact in the form of a [vCard](https://en.wikipedia.org/wiki/VCard), 0-2048 bytes | [optional] 
**reply_markup** | [**inline_keyboard_markup_t**](inline_keyboard_markup.md) \* |  | [optional] 
**input_message_content** | [**input_message_content_t**](input_message_content.md) \* |  | [optional] 
**thumbnail_url** | **char \*** | *Optional*. Url of the thumbnail for the result | [optional] 
**thumbnail_width** | **int** | *Optional*. Thumbnail width | [optional] 
**thumbnail_height** | **int** | *Optional*. Thumbnail height | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


