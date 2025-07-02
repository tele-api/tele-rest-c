#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "convert_gift_to_stars_request.h"



static convert_gift_to_stars_request_t *convert_gift_to_stars_request_create_internal(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    convert_gift_to_stars_request_t *convert_gift_to_stars_request_local_var = malloc(sizeof(convert_gift_to_stars_request_t));
    if (!convert_gift_to_stars_request_local_var) {
        return NULL;
    }
    convert_gift_to_stars_request_local_var->business_connection_id = business_connection_id;
    convert_gift_to_stars_request_local_var->owned_gift_id = owned_gift_id;

    convert_gift_to_stars_request_local_var->_library_owned = 1;
    return convert_gift_to_stars_request_local_var;
}

__attribute__((deprecated)) convert_gift_to_stars_request_t *convert_gift_to_stars_request_create(
    char *business_connection_id,
    char *owned_gift_id
    ) {
    return convert_gift_to_stars_request_create_internal (
        business_connection_id,
        owned_gift_id
        );
}

void convert_gift_to_stars_request_free(convert_gift_to_stars_request_t *convert_gift_to_stars_request) {
    if(NULL == convert_gift_to_stars_request){
        return ;
    }
    if(convert_gift_to_stars_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "convert_gift_to_stars_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (convert_gift_to_stars_request->business_connection_id) {
        free(convert_gift_to_stars_request->business_connection_id);
        convert_gift_to_stars_request->business_connection_id = NULL;
    }
    if (convert_gift_to_stars_request->owned_gift_id) {
        free(convert_gift_to_stars_request->owned_gift_id);
        convert_gift_to_stars_request->owned_gift_id = NULL;
    }
    free(convert_gift_to_stars_request);
}

cJSON *convert_gift_to_stars_request_convertToJSON(convert_gift_to_stars_request_t *convert_gift_to_stars_request) {
    cJSON *item = cJSON_CreateObject();

    // convert_gift_to_stars_request->business_connection_id
    if (!convert_gift_to_stars_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", convert_gift_to_stars_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // convert_gift_to_stars_request->owned_gift_id
    if (!convert_gift_to_stars_request->owned_gift_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "owned_gift_id", convert_gift_to_stars_request->owned_gift_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

convert_gift_to_stars_request_t *convert_gift_to_stars_request_parseFromJSON(cJSON *convert_gift_to_stars_requestJSON){

    convert_gift_to_stars_request_t *convert_gift_to_stars_request_local_var = NULL;

    // convert_gift_to_stars_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(convert_gift_to_stars_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // convert_gift_to_stars_request->owned_gift_id
    cJSON *owned_gift_id = cJSON_GetObjectItemCaseSensitive(convert_gift_to_stars_requestJSON, "owned_gift_id");
    if (cJSON_IsNull(owned_gift_id)) {
        owned_gift_id = NULL;
    }
    if (!owned_gift_id) {
        goto end;
    }

    
    if(!cJSON_IsString(owned_gift_id))
    {
    goto end; //String
    }


    convert_gift_to_stars_request_local_var = convert_gift_to_stars_request_create_internal (
        strdup(business_connection_id->valuestring),
        strdup(owned_gift_id->valuestring)
        );

    return convert_gift_to_stars_request_local_var;
end:
    return NULL;

}
