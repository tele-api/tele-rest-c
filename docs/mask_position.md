# mask_position_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**point** | **telegram_bot_api_mask_position_POINT_e** | The part of the face relative to which the mask should be placed. One of “forehead”, “eyes”, “mouth”, or “chin”. | 
**x_shift** | **double** | Shift by X-axis measured in widths of the mask scaled to the face size, from left to right. For example, choosing -1.0 will place mask just to the left of the default mask position. | 
**y_shift** | **double** | Shift by Y-axis measured in heights of the mask scaled to the face size, from top to bottom. For example, 1.0 will place the mask just below the default mask position. | 
**scale** | **double** | Mask scaling coefficient. For example, 2.0 means double size. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


