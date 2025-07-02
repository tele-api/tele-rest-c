#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_mask_position_request.h"



static post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request_create_internal(
    char *sticker,
    mask_position_t *mask_position
    ) {
    post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request_local_var = malloc(sizeof(post_set_sticker_mask_position_request_t));
    if (!post_set_sticker_mask_position_request_local_var) {
        return NULL;
    }
    post_set_sticker_mask_position_request_local_var->sticker = sticker;
    post_set_sticker_mask_position_request_local_var->mask_position = mask_position;

    post_set_sticker_mask_position_request_local_var->_library_owned = 1;
    return post_set_sticker_mask_position_request_local_var;
}

__attribute__((deprecated)) post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request_create(
    char *sticker,
    mask_position_t *mask_position
    ) {
    return post_set_sticker_mask_position_request_create_internal (
        sticker,
        mask_position
        );
}

void post_set_sticker_mask_position_request_free(post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request) {
    if(NULL == post_set_sticker_mask_position_request){
        return ;
    }
    if(post_set_sticker_mask_position_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_mask_position_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_sticker_mask_position_request->sticker) {
        free(post_set_sticker_mask_position_request->sticker);
        post_set_sticker_mask_position_request->sticker = NULL;
    }
    if (post_set_sticker_mask_position_request->mask_position) {
        mask_position_free(post_set_sticker_mask_position_request->mask_position);
        post_set_sticker_mask_position_request->mask_position = NULL;
    }
    free(post_set_sticker_mask_position_request);
}

cJSON *post_set_sticker_mask_position_request_convertToJSON(post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_sticker_mask_position_request->sticker
    if (!post_set_sticker_mask_position_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", post_set_sticker_mask_position_request->sticker) == NULL) {
    goto fail; //String
    }


    // post_set_sticker_mask_position_request->mask_position
    if(post_set_sticker_mask_position_request->mask_position) {
    cJSON *mask_position_local_JSON = mask_position_convertToJSON(post_set_sticker_mask_position_request->mask_position);
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

post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request_parseFromJSON(cJSON *post_set_sticker_mask_position_requestJSON){

    post_set_sticker_mask_position_request_t *post_set_sticker_mask_position_request_local_var = NULL;

    // define the local variable for post_set_sticker_mask_position_request->mask_position
    mask_position_t *mask_position_local_nonprim = NULL;

    // post_set_sticker_mask_position_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(post_set_sticker_mask_position_requestJSON, "sticker");
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

    // post_set_sticker_mask_position_request->mask_position
    cJSON *mask_position = cJSON_GetObjectItemCaseSensitive(post_set_sticker_mask_position_requestJSON, "mask_position");
    if (cJSON_IsNull(mask_position)) {
        mask_position = NULL;
    }
    if (mask_position) { 
    mask_position_local_nonprim = mask_position_parseFromJSON(mask_position); //nonprimitive
    }


    post_set_sticker_mask_position_request_local_var = post_set_sticker_mask_position_request_create_internal (
        strdup(sticker->valuestring),
        mask_position ? mask_position_local_nonprim : NULL
        );

    return post_set_sticker_mask_position_request_local_var;
end:
    if (mask_position_local_nonprim) {
        mask_position_free(mask_position_local_nonprim);
        mask_position_local_nonprim = NULL;
    }
    return NULL;

}
