#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_remove_user_verification_post_request.h"



static _remove_user_verification_post_request_t *_remove_user_verification_post_request_create_internal(
    int user_id
    ) {
    _remove_user_verification_post_request_t *_remove_user_verification_post_request_local_var = malloc(sizeof(_remove_user_verification_post_request_t));
    if (!_remove_user_verification_post_request_local_var) {
        return NULL;
    }
    _remove_user_verification_post_request_local_var->user_id = user_id;

    _remove_user_verification_post_request_local_var->_library_owned = 1;
    return _remove_user_verification_post_request_local_var;
}

__attribute__((deprecated)) _remove_user_verification_post_request_t *_remove_user_verification_post_request_create(
    int user_id
    ) {
    return _remove_user_verification_post_request_create_internal (
        user_id
        );
}

void _remove_user_verification_post_request_free(_remove_user_verification_post_request_t *_remove_user_verification_post_request) {
    if(NULL == _remove_user_verification_post_request){
        return ;
    }
    if(_remove_user_verification_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_remove_user_verification_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    free(_remove_user_verification_post_request);
}

cJSON *_remove_user_verification_post_request_convertToJSON(_remove_user_verification_post_request_t *_remove_user_verification_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _remove_user_verification_post_request->user_id
    if (!_remove_user_verification_post_request->user_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "user_id", _remove_user_verification_post_request->user_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_remove_user_verification_post_request_t *_remove_user_verification_post_request_parseFromJSON(cJSON *_remove_user_verification_post_requestJSON){

    _remove_user_verification_post_request_t *_remove_user_verification_post_request_local_var = NULL;

    // _remove_user_verification_post_request->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(_remove_user_verification_post_requestJSON, "user_id");
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


    _remove_user_verification_post_request_local_var = _remove_user_verification_post_request_create_internal (
        user_id->valuedouble
        );

    return _remove_user_verification_post_request_local_var;
end:
    return NULL;

}
