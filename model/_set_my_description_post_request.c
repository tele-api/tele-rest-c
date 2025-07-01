#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_my_description_post_request.h"



static _set_my_description_post_request_t *_set_my_description_post_request_create_internal(
    char *description,
    char *language_code
    ) {
    _set_my_description_post_request_t *_set_my_description_post_request_local_var = malloc(sizeof(_set_my_description_post_request_t));
    if (!_set_my_description_post_request_local_var) {
        return NULL;
    }
    _set_my_description_post_request_local_var->description = description;
    _set_my_description_post_request_local_var->language_code = language_code;

    _set_my_description_post_request_local_var->_library_owned = 1;
    return _set_my_description_post_request_local_var;
}

__attribute__((deprecated)) _set_my_description_post_request_t *_set_my_description_post_request_create(
    char *description,
    char *language_code
    ) {
    return _set_my_description_post_request_create_internal (
        description,
        language_code
        );
}

void _set_my_description_post_request_free(_set_my_description_post_request_t *_set_my_description_post_request) {
    if(NULL == _set_my_description_post_request){
        return ;
    }
    if(_set_my_description_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_my_description_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_my_description_post_request->description) {
        free(_set_my_description_post_request->description);
        _set_my_description_post_request->description = NULL;
    }
    if (_set_my_description_post_request->language_code) {
        free(_set_my_description_post_request->language_code);
        _set_my_description_post_request->language_code = NULL;
    }
    free(_set_my_description_post_request);
}

cJSON *_set_my_description_post_request_convertToJSON(_set_my_description_post_request_t *_set_my_description_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_my_description_post_request->description
    if(_set_my_description_post_request->description) {
    if(cJSON_AddStringToObject(item, "description", _set_my_description_post_request->description) == NULL) {
    goto fail; //String
    }
    }


    // _set_my_description_post_request->language_code
    if(_set_my_description_post_request->language_code) {
    if(cJSON_AddStringToObject(item, "language_code", _set_my_description_post_request->language_code) == NULL) {
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

_set_my_description_post_request_t *_set_my_description_post_request_parseFromJSON(cJSON *_set_my_description_post_requestJSON){

    _set_my_description_post_request_t *_set_my_description_post_request_local_var = NULL;

    // _set_my_description_post_request->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(_set_my_description_post_requestJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // _set_my_description_post_request->language_code
    cJSON *language_code = cJSON_GetObjectItemCaseSensitive(_set_my_description_post_requestJSON, "language_code");
    if (cJSON_IsNull(language_code)) {
        language_code = NULL;
    }
    if (language_code) { 
    if(!cJSON_IsString(language_code) && !cJSON_IsNull(language_code))
    {
    goto end; //String
    }
    }


    _set_my_description_post_request_local_var = _set_my_description_post_request_create_internal (
        description && !cJSON_IsNull(description) ? strdup(description->valuestring) : NULL,
        language_code && !cJSON_IsNull(language_code) ? strdup(language_code->valuestring) : NULL
        );

    return _set_my_description_post_request_local_var;
end:
    return NULL;

}
