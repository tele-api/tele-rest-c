#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "chat_location.h"



static chat_location_t *chat_location_create_internal(
    location_t *location,
    char *address
    ) {
    chat_location_t *chat_location_local_var = malloc(sizeof(chat_location_t));
    if (!chat_location_local_var) {
        return NULL;
    }
    chat_location_local_var->location = location;
    chat_location_local_var->address = address;

    chat_location_local_var->_library_owned = 1;
    return chat_location_local_var;
}

__attribute__((deprecated)) chat_location_t *chat_location_create(
    location_t *location,
    char *address
    ) {
    return chat_location_create_internal (
        location,
        address
        );
}

void chat_location_free(chat_location_t *chat_location) {
    if(NULL == chat_location){
        return ;
    }
    if(chat_location->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "chat_location_free");
        return ;
    }
    listEntry_t *listEntry;
    if (chat_location->location) {
        location_free(chat_location->location);
        chat_location->location = NULL;
    }
    if (chat_location->address) {
        free(chat_location->address);
        chat_location->address = NULL;
    }
    free(chat_location);
}

cJSON *chat_location_convertToJSON(chat_location_t *chat_location) {
    cJSON *item = cJSON_CreateObject();

    // chat_location->location
    if (!chat_location->location) {
        goto fail;
    }
    cJSON *location_local_JSON = location_convertToJSON(chat_location->location);
    if(location_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "location", location_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // chat_location->address
    if (!chat_location->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", chat_location->address) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

chat_location_t *chat_location_parseFromJSON(cJSON *chat_locationJSON){

    chat_location_t *chat_location_local_var = NULL;

    // define the local variable for chat_location->location
    location_t *location_local_nonprim = NULL;

    // chat_location->location
    cJSON *location = cJSON_GetObjectItemCaseSensitive(chat_locationJSON, "location");
    if (cJSON_IsNull(location)) {
        location = NULL;
    }
    if (!location) {
        goto end;
    }

    
    location_local_nonprim = location_parseFromJSON(location); //nonprimitive

    // chat_location->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(chat_locationJSON, "address");
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


    chat_location_local_var = chat_location_create_internal (
        location_local_nonprim,
        strdup(address->valuestring)
        );

    return chat_location_local_var;
end:
    if (location_local_nonprim) {
        location_free(location_local_nonprim);
        location_local_nonprim = NULL;
    }
    return NULL;

}
