# encrypted_credentials_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**data** | **char \*** | Base64-encoded encrypted JSON-serialized data with unique user&#39;s payload, data hashes and secrets required for [EncryptedPassportElement](https://core.telegram.org/bots/api/#encryptedpassportelement) decryption and authentication | 
**hash** | **char \*** | Base64-encoded data hash for data authentication | 
**secret** | **char \*** | Base64-encoded secret, encrypted with the bot&#39;s public RSA key, required for data decryption | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


