#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_sticker_from_set_request.h"



static post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request_create_internal(
    char *sticker
    ) {
    post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request_local_var = malloc(sizeof(post_delete_sticker_from_set_request_t));
    if (!post_delete_sticker_from_set_request_local_var) {
        return NULL;
    }
    post_delete_sticker_from_set_request_local_var->sticker = sticker;

    post_delete_sticker_from_set_request_local_var->_library_owned = 1;
    return post_delete_sticker_from_set_request_local_var;
}

__attribute__((deprecated)) post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request_create(
    char *sticker
    ) {
    return post_delete_sticker_from_set_request_create_internal (
        sticker
        );
}

void post_delete_sticker_from_set_request_free(post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request) {
    if(NULL == post_delete_sticker_from_set_request){
        return ;
    }
    if(post_delete_sticker_from_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_sticker_from_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_sticker_from_set_request->sticker) {
        free(post_delete_sticker_from_set_request->sticker);
        post_delete_sticker_from_set_request->sticker = NULL;
    }
    free(post_delete_sticker_from_set_request);
}

cJSON *post_delete_sticker_from_set_request_convertToJSON(post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_sticker_from_set_request->sticker
    if (!post_delete_sticker_from_set_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", post_delete_sticker_from_set_request->sticker) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request_parseFromJSON(cJSON *post_delete_sticker_from_set_requestJSON){

    post_delete_sticker_from_set_request_t *post_delete_sticker_from_set_request_local_var = NULL;

    // post_delete_sticker_from_set_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(post_delete_sticker_from_set_requestJSON, "sticker");
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


    post_delete_sticker_from_set_request_local_var = post_delete_sticker_from_set_request_create_internal (
        strdup(sticker->valuestring)
        );

    return post_delete_sticker_from_set_request_local_var;
end:
    return NULL;

}
