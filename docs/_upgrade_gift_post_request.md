# _upgrade_gift_post_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**business_connection_id** | **char \*** | Unique identifier of the business connection | 
**owned_gift_id** | **char \*** | Unique identifier of the regular gift that should be upgraded to a unique one | 
**keep_original_details** | **int** | Pass True to keep the original gift text, sender and receiver in the upgraded gift | [optional] 
**star_count** | **int** | The amount of Telegram Stars that will be paid for the upgrade from the business account balance. If &#x60;gift.prepaid_upgrade_star_count &gt; 0&#x60;, then pass 0, otherwise, the *can\\_transfer\\_stars* business bot right is required and &#x60;gift.upgrade_star_count&#x60; must be passed. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


