#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_mask_position_post_request.h"



static _set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_create_internal(
    char *sticker,
    mask_position_t *mask_position
    ) {
    _set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_local_var = malloc(sizeof(_set_sticker_mask_position_post_request_t));
    if (!_set_sticker_mask_position_post_request_local_var) {
        return NULL;
    }
    _set_sticker_mask_position_post_request_local_var->sticker = sticker;
    _set_sticker_mask_position_post_request_local_var->mask_position = mask_position;

    _set_sticker_mask_position_post_request_local_var->_library_owned = 1;
    return _set_sticker_mask_position_post_request_local_var;
}

__attribute__((deprecated)) _set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_create(
    char *sticker,
    mask_position_t *mask_position
    ) {
    return _set_sticker_mask_position_post_request_create_internal (
        sticker,
        mask_position
        );
}

void _set_sticker_mask_position_post_request_free(_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request) {
    if(NULL == _set_sticker_mask_position_post_request){
        return ;
    }
    if(_set_sticker_mask_position_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_mask_position_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_sticker_mask_position_post_request->sticker) {
        free(_set_sticker_mask_position_post_request->sticker);
        _set_sticker_mask_position_post_request->sticker = NULL;
    }
    if (_set_sticker_mask_position_post_request->mask_position) {
        mask_position_free(_set_sticker_mask_position_post_request->mask_position);
        _set_sticker_mask_position_post_request->mask_position = NULL;
    }
    free(_set_sticker_mask_position_post_request);
}

cJSON *_set_sticker_mask_position_post_request_convertToJSON(_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_sticker_mask_position_post_request->sticker
    if (!_set_sticker_mask_position_post_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", _set_sticker_mask_position_post_request->sticker) == NULL) {
    goto fail; //String
    }


    // _set_sticker_mask_position_post_request->mask_position
    if(_set_sticker_mask_position_post_request->mask_position) {
    cJSON *mask_position_local_JSON = mask_position_convertToJSON(_set_sticker_mask_position_post_request->mask_position);
    if(mask_position_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mask_position", mask_position_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

_set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_parseFromJSON(cJSON *_set_sticker_mask_position_post_requestJSON){

    _set_sticker_mask_position_post_request_t *_set_sticker_mask_position_post_request_local_var = NULL;

    // define the local variable for _set_sticker_mask_position_post_request->mask_position
    mask_position_t *mask_position_local_nonprim = NULL;

    // _set_sticker_mask_position_post_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_set_sticker_mask_position_post_requestJSON, "sticker");
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

    // _set_sticker_mask_position_post_request->mask_position
    cJSON *mask_position = cJSON_GetObjectItemCaseSensitive(_set_sticker_mask_position_post_requestJSON, "mask_position");
    if (cJSON_IsNull(mask_position)) {
        mask_position = NULL;
    }
    if (mask_position) { 
    mask_position_local_nonprim = mask_position_parseFromJSON(mask_position); //nonprimitive
    }


    _set_sticker_mask_position_post_request_local_var = _set_sticker_mask_position_post_request_create_internal (
        strdup(sticker->valuestring),
        mask_position ? mask_position_local_nonprim : NULL
        );

    return _set_sticker_mask_position_post_request_local_var;
end:
    if (mask_position_local_nonprim) {
        mask_position_free(mask_position_local_nonprim);
        mask_position_local_nonprim = NULL;
    }
    return NULL;

}
