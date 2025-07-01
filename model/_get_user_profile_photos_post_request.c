#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_user_profile_photos_post_request.h"



static _get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_create_internal(
    int user_id,
    int offset,
    int limit
    ) {
    _get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_local_var = malloc(sizeof(_get_user_profile_photos_post_request_t));
    if (!_get_user_profile_photos_post_request_local_var) {
        return NULL;
    }
    _get_user_profile_photos_post_request_local_var->user_id = user_id;
    _get_user_profile_photos_post_request_local_var->offset = offset;
    _get_user_profile_photos_post_request_local_var->limit = limit;

    _get_user_profile_photos_post_request_local_var->_library_owned = 1;
    return _get_user_profile_photos_post_request_local_var;
}

__attribute__((deprecated)) _get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_create(
    int user_id,
    int offset,
    int limit
    ) {
    return _get_user_profile_photos_post_request_create_internal (
        user_id,
        offset,
        limit
        );
}

void _get_user_profile_photos_post_request_free(_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request) {
    if(NULL == _get_user_profile_photos_post_request){
        return ;
    }
    if(_get_user_profile_photos_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_user_profile_photos_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_get_user_profile_photos_post_request);
}

cJSON *_get_user_profile_photos_post_request_convertToJSON(_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_user_profile_photos_post_request->user_id
    if (!_get_user_profile_photos_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _get_user_profile_photos_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _get_user_profile_photos_post_request->offset
    if(_get_user_profile_photos_post_request->offset) {
    if(cJSON_AddNumberToObject(item, "offset", _get_user_profile_photos_post_request->offset) == NULL) {
    goto fail; //Numeric
    }
    }


    // _get_user_profile_photos_post_request->limit
    if(_get_user_profile_photos_post_request->limit) {
    if(cJSON_AddNumberToObject(item, "limit", _get_user_profile_photos_post_request->limit) == NULL) {
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

_get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_parseFromJSON(cJSON *_get_user_profile_photos_post_requestJSON){

    _get_user_profile_photos_post_request_t *_get_user_profile_photos_post_request_local_var = NULL;

    // _get_user_profile_photos_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_get_user_profile_photos_post_requestJSON, "user_id");
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

    // _get_user_profile_photos_post_request->offset
    cJSON *offset = cJSON_GetObjectItemCaseSensitive(_get_user_profile_photos_post_requestJSON, "offset");
    if (cJSON_IsNull(offset)) {
        offset = NULL;
    }
    if (offset) { 
    if(!cJSON_IsNumber(offset))
    {
    goto end; //Numeric
    }
    }

    // _get_user_profile_photos_post_request->limit
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(_get_user_profile_photos_post_requestJSON, "limit");
    if (cJSON_IsNull(limit)) {
        limit = NULL;
    }
    if (limit) { 
    if(!cJSON_IsNumber(limit))
    {
    goto end; //Numeric
    }
    }


    _get_user_profile_photos_post_request_local_var = _get_user_profile_photos_post_request_create_internal (
        user_id->valuedouble,
        offset ? offset->valuedouble : 0,
        limit ? limit->valuedouble : 0
        );

    return _get_user_profile_photos_post_request_local_var;
end:
    return NULL;

}
