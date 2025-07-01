#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "story_area_type_location.h"



static story_area_type_location_t *story_area_type_location_create_internal(
    char *type,
    double latitude,
    double longitude,
    location_address_t *address
    ) {
    story_area_type_location_t *story_area_type_location_local_var = malloc(sizeof(story_area_type_location_t));
    if (!story_area_type_location_local_var) {
        return NULL;
    }
    story_area_type_location_local_var->type = type;
    story_area_type_location_local_var->latitude = latitude;
    story_area_type_location_local_var->longitude = longitude;
    story_area_type_location_local_var->address = address;

    story_area_type_location_local_var->_library_owned = 1;
    return story_area_type_location_local_var;
}

__attribute__((deprecated)) story_area_type_location_t *story_area_type_location_create(
    char *type,
    double latitude,
    double longitude,
    location_address_t *address
    ) {
    return story_area_type_location_create_internal (
        type,
        latitude,
        longitude,
        address
        );
}

void story_area_type_location_free(story_area_type_location_t *story_area_type_location) {
    if(NULL == story_area_type_location){
        return ;
    }
    if(story_area_type_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "story_area_type_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (story_area_type_location->type) {
        free(story_area_type_location->type);
        story_area_type_location->type = NULL;
    }
    if (story_area_type_location->address) {
        location_address_free(story_area_type_location->address);
        story_area_type_location->address = NULL;
    }
    free(story_area_type_location);
}

cJSON *story_area_type_location_convertToJSON(story_area_type_location_t *story_area_type_location) {
    cJSON *item = cJSON_CreateObject();

    // story_area_type_location->type
    if (!story_area_type_location->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", story_area_type_location->type) == NULL) {
    goto fail; //String
    }


    // story_area_type_location->latitude
    if (!story_area_type_location->latitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "latitude", story_area_type_location->latitude) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type_location->longitude
    if (!story_area_type_location->longitude) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "longitude", story_area_type_location->longitude) == NULL) {
    goto fail; //Numeric
    }


    // story_area_type_location->address
    if(story_area_type_location->address) {
    cJSON *address_local_JSON = location_address_convertToJSON(story_area_type_location->address);
    if(address_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "address", address_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

story_area_type_location_t *story_area_type_location_parseFromJSON(cJSON *story_area_type_locationJSON){

    story_area_type_location_t *story_area_type_location_local_var = NULL;

    // define the local variable for story_area_type_location->address
    location_address_t *address_local_nonprim = NULL;

    // story_area_type_location->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(story_area_type_locationJSON, "type");
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

    // story_area_type_location->latitude
    cJSON *latitude = cJSON_GetObjectItemCaseSensitive(story_area_type_locationJSON, "latitude");
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

    // story_area_type_location->longitude
    cJSON *longitude = cJSON_GetObjectItemCaseSensitive(story_area_type_locationJSON, "longitude");
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

    // story_area_type_location->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(story_area_type_locationJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (address) { 
    address_local_nonprim = location_address_parseFromJSON(address); //nonprimitive
    }


    story_area_type_location_local_var = story_area_type_location_create_internal (
        strdup(type->valuestring),
        latitude->valuedouble,
        longitude->valuedouble,
        address ? address_local_nonprim : NULL
        );

    return story_area_type_location_local_var;
end:
    if (address_local_nonprim) {
        location_address_free(address_local_nonprim);
        address_local_nonprim = NULL;
    }
    return NULL;

}
