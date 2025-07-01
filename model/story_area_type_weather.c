#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type_weather.h"



static story_area_type_weather_t *story_area_type_weather_create_internal(
    char *type,
    double temperature,
    char *emoji,
    int background_color
    ) {
    story_area_type_weather_t *story_area_type_weather_local_var = malloc(sizeof(story_area_type_weather_t));
    if (!story_area_type_weather_local_var) {
        return NULL;
    }
    story_area_type_weather_local_var->type = type;
    story_area_type_weather_local_var->temperature = temperature;
    story_area_type_weather_local_var->emoji = emoji;
    story_area_type_weather_local_var->background_color = background_color;

    story_area_type_weather_local_var->_library_owned = 1;
    return story_area_type_weather_local_var;
}

__attribute__((deprecated)) story_area_type_weather_t *story_area_type_weather_create(
    char *type,
    double temperature,
    char *emoji,
    int background_color
    ) {
    return story_area_type_weather_create_internal (
        type,
        temperature,
        emoji,
        background_color
        );
}

void story_area_type_weather_free(story_area_type_weather_t *story_area_type_weather) {
    if(NULL == story_area_type_weather){
        return ;
    }
    if(story_area_type_weather->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_weather_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type_weather->type) {
        free(story_area_type_weather->type);
        story_area_type_weather->type = NULL;
    }
    if (story_area_type_weather->emoji) {
        free(story_area_type_weather->emoji);
        story_area_type_weather->emoji = NULL;
    }
    free(story_area_type_weather);
}

cJSON *story_area_type_weather_convertToJSON(story_area_type_weather_t *story_area_type_weather) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type_weather->type
    if (!story_area_type_weather->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type_weather->type) == NULL) {
    goto fail; //String
    }


    // story_area_type_weather->temperature
    if (!story_area_type_weather->temperature) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "temperature", story_area_type_weather->temperature) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type_weather->emoji
    if (!story_area_type_weather->emoji) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "emoji", story_area_type_weather->emoji) == NULL) {
    goto fail; //String
    }


    // story_area_type_weather->background_color
    if (!story_area_type_weather->background_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "background_color", story_area_type_weather->background_color) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_type_weather_t *story_area_type_weather_parseFromJSON(cJSON *story_area_type_weatherJSON){

    story_area_type_weather_t *story_area_type_weather_local_var = NULL;

    // story_area_type_weather->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_type_weatherJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // story_area_type_weather->temperature
    cJSON *temperature = cJSON_GetObjectItemCaseSensitive(story_area_type_weatherJSON, "temperature");
    if (cJSON_IsNull(temperature)) {
        temperature = NULL;
    }
    if (!temperature) {
        goto end;
    }

    
    if(!cJSON_IsNumber(temperature))
    {
    goto end; //Numeric
    }

    // story_area_type_weather->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(story_area_type_weatherJSON, "emoji");
    if (cJSON_IsNull(emoji)) {
        emoji = NULL;
    }
    if (!emoji) {
        goto end;
    }

    
    if(!cJSON_IsString(emoji))
    {
    goto end; //String
    }

    // story_area_type_weather->background_color
    cJSON *background_color = cJSON_GetObjectItemCaseSensitive(story_area_type_weatherJSON, "background_color");
    if (cJSON_IsNull(background_color)) {
        background_color = NULL;
    }
    if (!background_color) {
        goto end;
    }

    
    if(!cJSON_IsNumber(background_color))
    {
    goto end; //Numeric
    }


    story_area_type_weather_local_var = story_area_type_weather_create_internal (
        strdup(type->valuestring),
        temperature->valuedouble,
        strdup(emoji->valuestring),
        background_color->valuedouble
        );

    return story_area_type_weather_local_var;
end:
    return NULL;

}
