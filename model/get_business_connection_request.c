#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_business_connection_request.h"



static get_business_connection_request_t *get_business_connection_request_create_internal(
    char *business_connection_id
    ) {
    get_business_connection_request_t *get_business_connection_request_local_var = malloc(sizeof(get_business_connection_request_t));
    if (!get_business_connection_request_local_var) {
        return NULL;
    }
    get_business_connection_request_local_var->business_connection_id = business_connection_id;

    get_business_connection_request_local_var->_library_owned = 1;
    return get_business_connection_request_local_var;
}

__attribute__((deprecated)) get_business_connection_request_t *get_business_connection_request_create(
    char *business_connection_id
    ) {
    return get_business_connection_request_create_internal (
        business_connection_id
        );
}

void get_business_connection_request_free(get_business_connection_request_t *get_business_connection_request) {
    if(NULL == get_business_connection_request){
        return ;
    }
    if(get_business_connection_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_business_connection_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_business_connection_request->business_connection_id) {
        free(get_business_connection_request->business_connection_id);
        get_business_connection_request->business_connection_id = NULL;
    }
    free(get_business_connection_request);
}

cJSON *get_business_connection_request_convertToJSON(get_business_connection_request_t *get_business_connection_request) {
    cJSON *item = cJSON_CreateObject();

    // get_business_connection_request->business_connection_id
    if (!get_business_connection_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", get_business_connection_request->business_connection_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_business_connection_request_t *get_business_connection_request_parseFromJSON(cJSON *get_business_connection_requestJSON){

    get_business_connection_request_t *get_business_connection_request_local_var = NULL;

    // get_business_connection_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(get_business_connection_requestJSON, "business_connection_id");
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


    get_business_connection_request_local_var = get_business_connection_request_create_internal (
        strdup(business_connection_id->valuestring)
        );

    return get_business_connection_request_local_var;
end:
    return NULL;

}
