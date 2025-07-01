# background_type_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**type** | **char \*** | Type of the background, always “chat\\_theme” | [default to 'chat_theme']
**fill** | [**background_fill_t**](background_fill.md) \* |  | 
**dark_theme_dimming** | **int** | Dimming of the background in dark themes, as a percentage; 0-100 | 
**document** | [**document_t**](document.md) \* |  | 
**intensity** | **int** | Intensity of the pattern when it is shown above the filled background; 0-100 | 
**theme_name** | **char \*** | Name of the chat theme, which is usually an emoji | 
**is_blurred** | **int** | *Optional*. *True*, if the wallpaper is downscaled to fit in a 450x450 square and then box-blurred with radius 12 | [optional] [default to true]
**is_moving** | **int** | *Optional*. *True*, if the background moves slightly when the device is tilted | [optional] [default to true]
**is_inverted** | **int** | *Optional*. *True*, if the background fill must be applied only to the pattern itself. All other pixels are black in this case. For dark themes only | [optional] [default to true]

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


