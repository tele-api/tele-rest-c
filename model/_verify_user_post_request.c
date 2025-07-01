#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_verify_user_post_request.h"



static _verify_user_post_request_t *_verify_user_post_request_create_internal(
    int user_id,
    char *custom_description
    ) {
    _verify_user_post_request_t *_verify_user_post_request_local_var = malloc(sizeof(_verify_user_post_request_t));
    if (!_verify_user_post_request_local_var) {
        return NULL;
    }
    _verify_user_post_request_local_var->user_id = user_id;
    _verify_user_post_request_local_var->custom_description = custom_description;

    _verify_user_post_request_local_var->_library_owned = 1;
    return _verify_user_post_request_local_var;
}

__attribute__((deprecated)) _verify_user_post_request_t *_verify_user_post_request_create(
    int user_id,
    char *custom_description
    ) {
    return _verify_user_post_request_create_internal (
        user_id,
        custom_description
        );
}

void _verify_user_post_request_free(_verify_user_post_request_t *_verify_user_post_request) {
    if(NULL == _verify_user_post_request){
        return ;
    }
    if(_verify_user_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_verify_user_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_verify_user_post_request->custom_description) {
        free(_verify_user_post_request->custom_description);
        _verify_user_post_request->custom_description = NULL;
    }
    free(_verify_user_post_request);
}

cJSON *_verify_user_post_request_convertToJSON(_verify_user_post_request_t *_verify_user_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _verify_user_post_request->user_id
    if (!_verify_user_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _verify_user_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }


    // _verify_user_post_request->custom_description
    if(_verify_user_post_request->custom_description) {
    if(cJSON_AddStringToObject(item, "custom_description", _verify_user_post_request->custom_description) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_verify_user_post_request_t *_verify_user_post_request_parseFromJSON(cJSON *_verify_user_post_requestJSON){

    _verify_user_post_request_t *_verify_user_post_request_local_var = NULL;

    // _verify_user_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_verify_user_post_requestJSON, "user_id");
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

    // _verify_user_post_request->custom_description
    cJSON *custom_description = cJSON_GetObjectItemCaseSensitive(_verify_user_post_requestJSON, "custom_description");
    if (cJSON_IsNull(custom_description)) {
        custom_description = NULL;
    }
    if (custom_description) { 
    if(!cJSON_IsString(custom_description) && !cJSON_IsNull(custom_description))
    {
    goto end; //String
    }
    }


    _verify_user_post_request_local_var = _verify_user_post_request_create_internal (
        user_id->valuedouble,
        custom_description && !cJSON_IsNull(custom_description) ? strdup(custom_description->valuestring) : NULL
        );

    return _verify_user_post_request_local_var;
end:
    return NULL;

}
