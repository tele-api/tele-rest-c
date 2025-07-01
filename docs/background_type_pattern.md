# background_type_pattern_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the background, always “pattern” | [default to 'pattern']
**document** | [**document_t**](document.md) \* |  | 
**fill** | [**background_fill_t**](background_fill.md) \* |  | 
**intensity** | **int** | Intensity of the pattern when it is shown above the filled background; 0-100 | 
**is_inverted** | **int** | *Optional*. *True*, if the background fill must be applied only to the pattern itself. All other pixels are black in this case. For dark themes only | [optional] [default to true]
**is_moving** | **int** | *Optional*. *True*, if the background moves slightly when the device is tilted | [optional] [default to true]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


