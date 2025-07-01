# encrypted_passport_element_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **telegram_bot_api_encrypted_passport_element_TYPE_e** | Element type. One of “personal\\_details”, “passport”, “driver\\_license”, “identity\\_card”, “internal\\_passport”, “address”, “utility\\_bill”, “bank\\_statement”, “rental\\_agreement”, “passport\\_registration”, “temporary\\_registration”, “phone\\_number”, “email”. | 
**hash** | **char \*** | Base64-encoded element hash for using in [PassportElementErrorUnspecified](https://core.telegram.org/bots/api/#passportelementerrorunspecified) | 
**data** | **char \*** | *Optional*. Base64-encoded encrypted Telegram Passport element data provided by the user; available only for “personal\\_details”, “passport”, “driver\\_license”, “identity\\_card”, “internal\\_passport” and “address” types. Can be decrypted and verified using the accompanying [EncryptedCredentials](https://core.telegram.org/bots/api/#encryptedcredentials). | [optional] 
**phone_number** | **char \*** | *Optional*. User&#39;s verified phone number; available only for “phone\\_number” type | [optional] 
**email** | **char \*** | *Optional*. User&#39;s verified email address; available only for “email” type | [optional] 
**files** | [**list_t**](passport_file.md) \* | *Optional*. Array of encrypted files with documents provided by the user; available only for “utility\\_bill”, “bank\\_statement”, “rental\\_agreement”, “passport\\_registration” and “temporary\\_registration” types. Files can be decrypted and verified using the accompanying [EncryptedCredentials](https://core.telegram.org/bots/api/#encryptedcredentials). | [optional] 
**front_side** | [**passport_file_t**](passport_file.md) \* |  | [optional] 
**reverse_side** | [**passport_file_t**](passport_file.md) \* |  | [optional] 
**selfie** | [**passport_file_t**](passport_file.md) \* |  | [optional] 
**translation** | [**list_t**](passport_file.md) \* | *Optional*. Array of encrypted files with translated versions of documents provided by the user; available if requested for “passport”, “driver\\_license”, “identity\\_card”, “internal\\_passport”, “utility\\_bill”, “bank\\_statement”, “rental\\_agreement”, “passport\\_registration” and “temporary\\_registration” types. Files can be decrypted and verified using the accompanying [EncryptedCredentials](https://core.telegram.org/bots/api/#encryptedcredentials). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


