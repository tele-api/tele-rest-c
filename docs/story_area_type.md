# story_area_type_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the area, always “unique\\_gift” | [default to 'unique_gift']
**latitude** | **double** | Location latitude in degrees | 
**longitude** | **double** | Location longitude in degrees | 
**reaction_type** | [**reaction_type_t**](reaction_type.md) \* |  | 
**url** | **char \*** | HTTP or tg:// URL to be opened when the area is clicked | 
**temperature** | **double** | Temperature, in degree Celsius | 
**emoji** | **char \*** | Emoji representing the weather | 
**background_color** | **int** | A color of the area background in the ARGB format | 
**name** | **char \*** | Unique name of the gift | 
**address** | [**location_address_t**](location_address.md) \* |  | [optional] 
**is_dark** | **int** | *Optional*. Pass *True* if the reaction area has a dark background | [optional] 
**is_flipped** | **int** | *Optional*. Pass *True* if reaction area corner is flipped | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


