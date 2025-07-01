#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_position_in_set_post_request.h"



static _set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request_create_internal(
    char *sticker,
    int position
    ) {
    _set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request_local_var = malloc(sizeof(_set_sticker_position_in_set_post_request_t));
    if (!_set_sticker_position_in_set_post_request_local_var) {
        return NULL;
    }
    _set_sticker_position_in_set_post_request_local_var->sticker = sticker;
    _set_sticker_position_in_set_post_request_local_var->position = position;

    _set_sticker_position_in_set_post_request_local_var->_library_owned = 1;
    return _set_sticker_position_in_set_post_request_local_var;
}

__attribute__((deprecated)) _set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request_create(
    char *sticker,
    int position
    ) {
    return _set_sticker_position_in_set_post_request_create_internal (
        sticker,
        position
        );
}

void _set_sticker_position_in_set_post_request_free(_set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request) {
    if(NULL == _set_sticker_position_in_set_post_request){
        return ;
    }
    if(_set_sticker_position_in_set_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_position_in_set_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_sticker_position_in_set_post_request->sticker) {
        free(_set_sticker_position_in_set_post_request->sticker);
        _set_sticker_position_in_set_post_request->sticker = NULL;
    }
    free(_set_sticker_position_in_set_post_request);
}

cJSON *_set_sticker_position_in_set_post_request_convertToJSON(_set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_sticker_position_in_set_post_request->sticker
    if (!_set_sticker_position_in_set_post_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", _set_sticker_position_in_set_post_request->sticker) == NULL) {
    goto fail; //String
    }


    // _set_sticker_position_in_set_post_request->position
    if (!_set_sticker_position_in_set_post_request->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", _set_sticker_position_in_set_post_request->position) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request_parseFromJSON(cJSON *_set_sticker_position_in_set_post_requestJSON){

    _set_sticker_position_in_set_post_request_t *_set_sticker_position_in_set_post_request_local_var = NULL;

    // _set_sticker_position_in_set_post_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_set_sticker_position_in_set_post_requestJSON, "sticker");
    if (cJSON_IsNull(sticker)) {
        sticker = NULL;
    }
    if (!sticker) {
        goto end;
    }

    
    if(!cJSON_IsString(sticker))
    {
    goto end; //String
    }

    // _set_sticker_position_in_set_post_request->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(_set_sticker_position_in_set_post_requestJSON, "position");
    if (cJSON_IsNull(position)) {
        position = NULL;
    }
    if (!position) {
        goto end;
    }

    
    if(!cJSON_IsNumber(position))
    {
    goto end; //Numeric
    }


    _set_sticker_position_in_set_post_request_local_var = _set_sticker_position_in_set_post_request_create_internal (
        strdup(sticker->valuestring),
        position->valuedouble
        );

    return _set_sticker_position_in_set_post_request_local_var;
end:
    return NULL;

}
