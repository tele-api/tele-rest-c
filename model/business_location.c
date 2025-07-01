#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_location.h"



static business_location_t *business_location_create_internal(
    char *address,
    location_t *location
    ) {
    business_location_t *business_location_local_var = malloc(sizeof(business_location_t));
    if (!business_location_local_var) {
        return NULL;
    }
    business_location_local_var->address = address;
    business_location_local_var->location = location;

    business_location_local_var->_library_owned = 1;
    return business_location_local_var;
}

__attribute__((deprecated)) business_location_t *business_location_create(
    char *address,
    location_t *location
    ) {
    return business_location_create_internal (
        address,
        location
        );
}

void business_location_free(business_location_t *business_location) {
    if(NULL == business_location){
        return ;
    }
    if(business_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (business_location->address) {
        free(business_location->address);
        business_location->address = NULL;
    }
    if (business_location->location) {
        location_free(business_location->location);
        business_location->location = NULL;
    }
    free(business_location);
}

cJSON *business_location_convertToJSON(business_location_t *business_location) {
    cJSON *item = cJSON_CreateObject();

    // business_location->address
    if (!business_location->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", business_location->address) == NULL) {
    goto fail; //String
    }


    // business_location->location
    if(business_location->location) {
    cJSON *location_local_JSON = location_convertToJSON(business_location->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
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

business_location_t *business_location_parseFromJSON(cJSON *business_locationJSON){

    business_location_t *business_location_local_var = NULL;

    // define the local variable for business_location->location
    location_t *location_local_nonprim = NULL;

    // business_location->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(business_locationJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // business_location->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(business_locationJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (location) { 
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive
    }


    business_location_local_var = business_location_create_internal (
        strdup(address->valuestring),
        location ? location_local_nonprim : NULL
        );

    return business_location_local_var;
end:
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
