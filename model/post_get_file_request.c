#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_file_request.h"



static post_get_file_request_t *post_get_file_request_create_internal(
    char *file_id
    ) {
    post_get_file_request_t *post_get_file_request_local_var = malloc(sizeof(post_get_file_request_t));
    if (!post_get_file_request_local_var) {
        return NULL;
    }
    post_get_file_request_local_var->file_id = file_id;

    post_get_file_request_local_var->_library_owned = 1;
    return post_get_file_request_local_var;
}

__attribute__((deprecated)) post_get_file_request_t *post_get_file_request_create(
    char *file_id
    ) {
    return post_get_file_request_create_internal (
        file_id
        );
}

void post_get_file_request_free(post_get_file_request_t *post_get_file_request) {
    if(NULL == post_get_file_request){
        return ;
    }
    if(post_get_file_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_file_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_file_request->file_id) {
        free(post_get_file_request->file_id);
        post_get_file_request->file_id = NULL;
    }
    free(post_get_file_request);
}

cJSON *post_get_file_request_convertToJSON(post_get_file_request_t *post_get_file_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_file_request->file_id
    if (!post_get_file_request->file_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "file_id", post_get_file_request->file_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_get_file_request_t *post_get_file_request_parseFromJSON(cJSON *post_get_file_requestJSON){

    post_get_file_request_t *post_get_file_request_local_var = NULL;

    // post_get_file_request->file_id
    cJSON *file_id = cJSON_GetObjectItemCaseSensitive(post_get_file_requestJSON, "file_id");
    if (cJSON_IsNull(file_id)) {
        file_id = NULL;
    }
    if (!file_id) {
        goto end;
    }

    
    if(!cJSON_IsString(file_id))
    {
    goto end; //String
    }


    post_get_file_request_local_var = post_get_file_request_create_internal (
        strdup(file_id->valuestring)
        );

    return post_get_file_request_local_var;
end:
    return NULL;

}
