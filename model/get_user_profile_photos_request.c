#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_user_profile_photos_request.h"



static get_user_profile_photos_request_t *get_user_profile_photos_request_create_internal(
    int user_id,
    int offset,
    int limit
    ) {
    get_user_profile_photos_request_t *get_user_profile_photos_request_local_var = malloc(sizeof(get_user_profile_photos_request_t));
    if (!get_user_profile_photos_request_local_var) {
        return NULL;
    }
    get_user_profile_photos_request_local_var->user_id = user_id;
    get_user_profile_photos_request_local_var->offset = offset;
    get_user_profile_photos_request_local_var->limit = limit;

    get_user_profile_photos_request_local_var->_library_owned = 1;
    return get_user_profile_photos_request_local_var;
}

__attribute__((deprecated)) get_user_profile_photos_request_t *get_user_profile_photos_request_create(
    int user_id,
    int offset,
    int limit
    ) {
    return get_user_profile_photos_request_create_internal (
        user_id,
        offset,
        limit
        );
}

void get_user_profile_photos_request_free(get_user_profile_photos_request_t *get_user_profile_photos_request) {
    if(NULL == get_user_profile_photos_request){
        return ;
    }
    if(get_user_profile_photos_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_user_profile_photos_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(get_user_profile_photos_request);
}

cJSON *get_user_profile_photos_request_convertToJSON(get_user_profile_photos_request_t *get_user_profile_photos_request) {
    cJSON *item = cJSON_CreateObject();

    // get_user_profile_photos_request->user_id
    if (!get_user_profile_photos_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", get_user_profile_photos_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // get_user_profile_photos_request->offset
    if(get_user_profile_photos_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", get_user_profile_photos_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // get_user_profile_photos_request->limit
    if(get_user_profile_photos_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", get_user_profile_photos_request->limit) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_user_profile_photos_request_t *get_user_profile_photos_request_parseFromJSON(cJSON *get_user_profile_photos_requestJSON){

    get_user_profile_photos_request_t *get_user_profile_photos_request_local_var = NULL;

    // get_user_profile_photos_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(get_user_profile_photos_requestJSON, "user_id");
    if (cJSON_IsNull(user_id)) {
        user_id = NULL;
    }
    if (!user_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(user_id))
    {
    goto end; //Numeric
    }

    // get_user_profile_photos_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(get_user_profile_photos_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // get_user_profile_photos_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(get_user_profile_photos_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    get_user_profile_photos_request_local_var = get_user_profile_photos_request_create_internal (
        user_id->valuedouble,
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0
        );

    return get_user_profile_photos_request_local_var;
end:
    return NULL;

}
