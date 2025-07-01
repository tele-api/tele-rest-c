#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_my_name_post_request.h"



static _get_my_name_post_request_t *_get_my_name_post_request_create_internal(
    char *language_code
    ) {
    _get_my_name_post_request_t *_get_my_name_post_request_local_var = malloc(sizeof(_get_my_name_post_request_t));
    if (!_get_my_name_post_request_local_var) {
        return NULL;
    }
    _get_my_name_post_request_local_var->language_code = language_code;

    _get_my_name_post_request_local_var->_library_owned = 1;
    return _get_my_name_post_request_local_var;
}

__attribute__((deprecated)) _get_my_name_post_request_t *_get_my_name_post_request_create(
    char *language_code
    ) {
    return _get_my_name_post_request_create_internal (
        language_code
        );
}

void _get_my_name_post_request_free(_get_my_name_post_request_t *_get_my_name_post_request) {
    if(NULL == _get_my_name_post_request){
        return ;
    }
    if(_get_my_name_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_my_name_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_my_name_post_request->language_code) {
        free(_get_my_name_post_request->language_code);
        _get_my_name_post_request->language_code = NULL;
    }
    free(_get_my_name_post_request);
}

cJSON *_get_my_name_post_request_convertToJSON(_get_my_name_post_request_t *_get_my_name_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_my_name_post_request->language_code
    if(_get_my_name_post_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", _get_my_name_post_request->language_code) == NULL) {
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

_get_my_name_post_request_t *_get_my_name_post_request_parseFromJSON(cJSON *_get_my_name_post_requestJSON){

    _get_my_name_post_request_t *_get_my_name_post_request_local_var = NULL;

    // _get_my_name_post_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(_get_my_name_post_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    _get_my_name_post_request_local_var = _get_my_name_post_request_create_internal (
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return _get_my_name_post_request_local_var;
end:
    return NULL;

}
