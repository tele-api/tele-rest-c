#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_mask_position_request.h"



static set_sticker_mask_position_request_t *set_sticker_mask_position_request_create_internal(
    char *sticker,
    mask_position_t *mask_position
    ) {
    set_sticker_mask_position_request_t *set_sticker_mask_position_request_local_var = malloc(sizeof(set_sticker_mask_position_request_t));
    if (!set_sticker_mask_position_request_local_var) {
        return NULL;
    }
    set_sticker_mask_position_request_local_var->sticker = sticker;
    set_sticker_mask_position_request_local_var->mask_position = mask_position;

    set_sticker_mask_position_request_local_var->_library_owned = 1;
    return set_sticker_mask_position_request_local_var;
}

__attribute__((deprecated)) set_sticker_mask_position_request_t *set_sticker_mask_position_request_create(
    char *sticker,
    mask_position_t *mask_position
    ) {
    return set_sticker_mask_position_request_create_internal (
        sticker,
        mask_position
        );
}

void set_sticker_mask_position_request_free(set_sticker_mask_position_request_t *set_sticker_mask_position_request) {
    if(NULL == set_sticker_mask_position_request){
        return ;
    }
    if(set_sticker_mask_position_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_mask_position_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_mask_position_request->sticker) {
        free(set_sticker_mask_position_request->sticker);
        set_sticker_mask_position_request->sticker = NULL;
    }
    if (set_sticker_mask_position_request->mask_position) {
        mask_position_free(set_sticker_mask_position_request->mask_position);
        set_sticker_mask_position_request->mask_position = NULL;
    }
    free(set_sticker_mask_position_request);
}

cJSON *set_sticker_mask_position_request_convertToJSON(set_sticker_mask_position_request_t *set_sticker_mask_position_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_mask_position_request->sticker
    if (!set_sticker_mask_position_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", set_sticker_mask_position_request->sticker) == NULL) {
    goto fail; //String
    }


    // set_sticker_mask_position_request->mask_position
    if(set_sticker_mask_position_request->mask_position) {
    cJSON *mask_position_local_JSON = mask_position_convertToJSON(set_sticker_mask_position_request->mask_position);
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

set_sticker_mask_position_request_t *set_sticker_mask_position_request_parseFromJSON(cJSON *set_sticker_mask_position_requestJSON){

    set_sticker_mask_position_request_t *set_sticker_mask_position_request_local_var = NULL;

    // define the local variable for set_sticker_mask_position_request->mask_position
    mask_position_t *mask_position_local_nonprim = NULL;

    // set_sticker_mask_position_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(set_sticker_mask_position_requestJSON, "sticker");
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

    // set_sticker_mask_position_request->mask_position
    cJSON *mask_position = cJSON_GetObjectItemCaseSensitive(set_sticker_mask_position_requestJSON, "mask_position");
    if (cJSON_IsNull(mask_position)) {
        mask_position = NULL;
    }
    if (mask_position) { 
    mask_position_local_nonprim = mask_position_parseFromJSON(mask_position); //nonprimitive
    }


    set_sticker_mask_position_request_local_var = set_sticker_mask_position_request_create_internal (
        strdup(sticker->valuestring),
        mask_position ? mask_position_local_nonprim : NULL
        );

    return set_sticker_mask_position_request_local_var;
end:
    if (mask_position_local_nonprim) {
        mask_position_free(mask_position_local_nonprim);
        mask_position_local_nonprim = NULL;
    }
    return NULL;

}
