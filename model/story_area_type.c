#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type.h"



static story_area_type_t *story_area_type_create_internal(
    char *type,
    double latitude,
    double longitude,
    reaction_type_t *reaction_type,
    char *url,
    double temperature,
    char *emoji,
    int background_color,
    char *name,
    location_address_t *address,
    int is_dark,
    int is_flipped
    ) {
    story_area_type_t *story_area_type_local_var = malloc(sizeof(story_area_type_t));
    if (!story_area_type_local_var) {
        return NULL;
    }
    story_area_type_local_var->type = type;
    story_area_type_local_var->latitude = latitude;
    story_area_type_local_var->longitude = longitude;
    story_area_type_local_var->reaction_type = reaction_type;
    story_area_type_local_var->url = url;
    story_area_type_local_var->temperature = temperature;
    story_area_type_local_var->emoji = emoji;
    story_area_type_local_var->background_color = background_color;
    story_area_type_local_var->name = name;
    story_area_type_local_var->address = address;
    story_area_type_local_var->is_dark = is_dark;
    story_area_type_local_var->is_flipped = is_flipped;

    story_area_type_local_var->_library_owned = 1;
    return story_area_type_local_var;
}

__attribute__((deprecated)) story_area_type_t *story_area_type_create(
    char *type,
    double latitude,
    double longitude,
    reaction_type_t *reaction_type,
    char *url,
    double temperature,
    char *emoji,
    int background_color,
    char *name,
    location_address_t *address,
    int is_dark,
    int is_flipped
    ) {
    return story_area_type_create_internal (
        type,
        latitude,
        longitude,
        reaction_type,
        url,
        temperature,
        emoji,
        background_color,
        name,
        address,
        is_dark,
        is_flipped
        );
}

void story_area_type_free(story_area_type_t *story_area_type) {
    if(NULL == story_area_type){
        return ;
    }
    if(story_area_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type->type) {
        free(story_area_type->type);
        story_area_type->type = NULL;
    }
    if (story_area_type->reaction_type) {
        reaction_type_free(story_area_type->reaction_type);
        story_area_type->reaction_type = NULL;
    }
    if (story_area_type->url) {
        free(story_area_type->url);
        story_area_type->url = NULL;
    }
    if (story_area_type->emoji) {
        free(story_area_type->emoji);
        story_area_type->emoji = NULL;
    }
    if (story_area_type->name) {
        free(story_area_type->name);
        story_area_type->name = NULL;
    }
    if (story_area_type->address) {
        location_address_free(story_area_type->address);
        story_area_type->address = NULL;
    }
    free(story_area_type);
}

cJSON *story_area_type_convertToJSON(story_area_type_t *story_area_type) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type->type
    if (!story_area_type->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type->type) == NULL) {
    goto fail; //String
    }


    // story_area_type->latitude
    if (!story_area_type->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", story_area_type->latitude) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type->longitude
    if (!story_area_type->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", story_area_type->longitude) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type->reaction_type
    if (!story_area_type->reaction_type) {
        goto fail;
    }
    cJSON *reaction_type_local_JSON = reaction_type_convertToJSON(story_area_type->reaction_type);
    if(reaction_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "reaction_type", reaction_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // story_area_type->url
    if (!story_area_type->url) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "url", story_area_type->url) == NULL) {
    goto fail; //String
    }


    // story_area_type->temperature
    if (!story_area_type->temperature) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "temperature", story_area_type->temperature) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type->emoji
    if (!story_area_type->emoji) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "emoji", story_area_type->emoji) == NULL) {
    goto fail; //String
    }


    // story_area_type->background_color
    if (!story_area_type->background_color) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "background_color", story_area_type->background_color) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type->name
    if (!story_area_type->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", story_area_type->name) == NULL) {
    goto fail; //String
    }


    // story_area_type->address
    if(story_area_type->address) {
    cJSON *address_local_JSON = location_address_convertToJSON(story_area_type->address);
    if(address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // story_area_type->is_dark
    if(story_area_type->is_dark) {
    if(cJSON_AddBoolToObject(item, "is_dark", story_area_type->is_dark) == NULL) {
    goto fail; //Bool
    }
    }


    // story_area_type->is_flipped
    if(story_area_type->is_flipped) {
    if(cJSON_AddBoolToObject(item, "is_flipped", story_area_type->is_flipped) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_type_t *story_area_type_parseFromJSON(cJSON *story_area_typeJSON){

    story_area_type_t *story_area_type_local_var = NULL;

    // define the local variable for story_area_type->reaction_type
    reaction_type_t *reaction_type_local_nonprim = NULL;

    // define the local variable for story_area_type->address
    location_address_t *address_local_nonprim = NULL;

    // story_area_type->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "type");
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

    // story_area_type->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "latitude");
    if (cJSON_IsNull(latitude)) {
        latitude = NULL;
    }
    if (!latitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(latitude))
    {
    goto end; //Numeric
    }

    // story_area_type->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "longitude");
    if (cJSON_IsNull(longitude)) {
        longitude = NULL;
    }
    if (!longitude) {
        goto end;
    }

    
    if(!cJSON_IsNumber(longitude))
    {
    goto end; //Numeric
    }

    // story_area_type->reaction_type
    cJSON *reaction_type = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "reaction_type");
    if (cJSON_IsNull(reaction_type)) {
        reaction_type = NULL;
    }
    if (!reaction_type) {
        goto end;
    }

    
    reaction_type_local_nonprim = reaction_type_parseFromJSON(reaction_type); //nonprimitive

    // story_area_type->url
    cJSON *url = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "url");
    if (cJSON_IsNull(url)) {
        url = NULL;
    }
    if (!url) {
        goto end;
    }

    
    if(!cJSON_IsString(url))
    {
    goto end; //String
    }

    // story_area_type->temperature
    cJSON *temperature = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "temperature");
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

    // story_area_type->emoji
    cJSON *emoji = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "emoji");
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

    // story_area_type->background_color
    cJSON *background_color = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "background_color");
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

    // story_area_type->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // story_area_type->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = location_address_parseFromJSON(address); //nonprimitive
    }

    // story_area_type->is_dark
    cJSON *is_dark = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "is_dark");
    if (cJSON_IsNull(is_dark)) {
        is_dark = NULL;
    }
    if (is_dark) { 
    if(!cJSON_IsBool(is_dark))
    {
    goto end; //Bool
    }
    }

    // story_area_type->is_flipped
    cJSON *is_flipped = cJSON_GetObjectItemCaseSensitive(story_area_typeJSON, "is_flipped");
    if (cJSON_IsNull(is_flipped)) {
        is_flipped = NULL;
    }
    if (is_flipped) { 
    if(!cJSON_IsBool(is_flipped))
    {
    goto end; //Bool
    }
    }


    story_area_type_local_var = story_area_type_create_internal (
        strdup(type->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        reaction_type_local_nonprim,
        strdup(url->valuestring),
        temperature->valuedouble,
        strdup(emoji->valuestring),
        background_color->valuedouble,
        strdup(name->valuestring),
        address ? address_local_nonprim : NULL,
        is_dark ? is_dark->valueint : 0,
        is_flipped ? is_flipped->valueint : 0
        );

    return story_area_type_local_var;
end:
    if (reaction_type_local_nonprim) {
        reaction_type_free(reaction_type_local_nonprim);
        reaction_type_local_nonprim = NULL;
    }
    if (address_local_nonprim) {
        location_address_free(address_local_nonprim);
        address_local_nonprim = NULL;
    }
    return NULL;

}
