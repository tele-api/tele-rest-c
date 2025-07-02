#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_sticker_set_request.h"



static post_delete_sticker_set_request_t *post_delete_sticker_set_request_create_internal(
    char *name
    ) {
    post_delete_sticker_set_request_t *post_delete_sticker_set_request_local_var = malloc(sizeof(post_delete_sticker_set_request_t));
    if (!post_delete_sticker_set_request_local_var) {
        return NULL;
    }
    post_delete_sticker_set_request_local_var->name = name;

    post_delete_sticker_set_request_local_var->_library_owned = 1;
    return post_delete_sticker_set_request_local_var;
}

__attribute__((deprecated)) post_delete_sticker_set_request_t *post_delete_sticker_set_request_create(
    char *name
    ) {
    return post_delete_sticker_set_request_create_internal (
        name
        );
}

void post_delete_sticker_set_request_free(post_delete_sticker_set_request_t *post_delete_sticker_set_request) {
    if(NULL == post_delete_sticker_set_request){
        return ;
    }
    if(post_delete_sticker_set_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_sticker_set_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_sticker_set_request->name) {
        free(post_delete_sticker_set_request->name);
        post_delete_sticker_set_request->name = NULL;
    }
    free(post_delete_sticker_set_request);
}

cJSON *post_delete_sticker_set_request_convertToJSON(post_delete_sticker_set_request_t *post_delete_sticker_set_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_sticker_set_request->name
    if (!post_delete_sticker_set_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", post_delete_sticker_set_request->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_delete_sticker_set_request_t *post_delete_sticker_set_request_parseFromJSON(cJSON *post_delete_sticker_set_requestJSON){

    post_delete_sticker_set_request_t *post_delete_sticker_set_request_local_var = NULL;

    // post_delete_sticker_set_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_delete_sticker_set_requestJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    post_delete_sticker_set_request_local_var = post_delete_sticker_set_request_create_internal (
        strdup(name->valuestring)
        );

    return post_delete_sticker_set_request_local_var;
end:
    return NULL;

}
