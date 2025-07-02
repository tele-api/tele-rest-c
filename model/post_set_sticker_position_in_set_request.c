#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_position_in_set_request.h"



static post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request_create_internal(
    char *sticker,
    int position
    ) {
    post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request_local_var = malloc(sizeof(post_set_sticker_position_in_set_request_t));
    if (!post_set_sticker_position_in_set_request_local_var) {
        return NULL;
    }
    post_set_sticker_position_in_set_request_local_var->sticker = sticker;
    post_set_sticker_position_in_set_request_local_var->position = position;

    post_set_sticker_position_in_set_request_local_var->_library_owned = 1;
    return post_set_sticker_position_in_set_request_local_var;
}

__attribute__((deprecated)) post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request_create(
    char *sticker,
    int position
    ) {
    return post_set_sticker_position_in_set_request_create_internal (
        sticker,
        position
        );
}

void post_set_sticker_position_in_set_request_free(post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request) {
    if(NULL == post_set_sticker_position_in_set_request){
        return ;
    }
    if(post_set_sticker_position_in_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_position_in_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_sticker_position_in_set_request->sticker) {
        free(post_set_sticker_position_in_set_request->sticker);
        post_set_sticker_position_in_set_request->sticker = NULL;
    }
    free(post_set_sticker_position_in_set_request);
}

cJSON *post_set_sticker_position_in_set_request_convertToJSON(post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_sticker_position_in_set_request->sticker
    if (!post_set_sticker_position_in_set_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", post_set_sticker_position_in_set_request->sticker) == NULL) {
    goto fail; //String
    }


    // post_set_sticker_position_in_set_request->position
    if (!post_set_sticker_position_in_set_request->position) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "position", post_set_sticker_position_in_set_request->position) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request_parseFromJSON(cJSON *post_set_sticker_position_in_set_requestJSON){

    post_set_sticker_position_in_set_request_t *post_set_sticker_position_in_set_request_local_var = NULL;

    // post_set_sticker_position_in_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(post_set_sticker_position_in_set_requestJSON, "sticker");
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

    // post_set_sticker_position_in_set_request->position
    cJSON *position = cJSON_GetObjectItemCaseSensitive(post_set_sticker_position_in_set_requestJSON, "position");
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


    post_set_sticker_position_in_set_request_local_var = post_set_sticker_position_in_set_request_create_internal (
        strdup(sticker->valuestring),
        position->valuedouble
        );

    return post_set_sticker_position_in_set_request_local_var;
end:
    return NULL;

}
