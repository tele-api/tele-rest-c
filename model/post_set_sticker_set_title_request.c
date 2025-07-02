#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_set_title_request.h"



static post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_create_internal(
    char *name,
    char *title
    ) {
    post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_local_var = malloc(sizeof(post_set_sticker_set_title_request_t));
    if (!post_set_sticker_set_title_request_local_var) {
        return NULL;
    }
    post_set_sticker_set_title_request_local_var->name = name;
    post_set_sticker_set_title_request_local_var->title = title;

    post_set_sticker_set_title_request_local_var->_library_owned = 1;
    return post_set_sticker_set_title_request_local_var;
}

__attribute__((deprecated)) post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_create(
    char *name,
    char *title
    ) {
    return post_set_sticker_set_title_request_create_internal (
        name,
        title
        );
}

void post_set_sticker_set_title_request_free(post_set_sticker_set_title_request_t *post_set_sticker_set_title_request) {
    if(NULL == post_set_sticker_set_title_request){
        return ;
    }
    if(post_set_sticker_set_title_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_set_title_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_sticker_set_title_request->name) {
        free(post_set_sticker_set_title_request->name);
        post_set_sticker_set_title_request->name = NULL;
    }
    if (post_set_sticker_set_title_request->title) {
        free(post_set_sticker_set_title_request->title);
        post_set_sticker_set_title_request->title = NULL;
    }
    free(post_set_sticker_set_title_request);
}

cJSON *post_set_sticker_set_title_request_convertToJSON(post_set_sticker_set_title_request_t *post_set_sticker_set_title_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_sticker_set_title_request->name
    if (!post_set_sticker_set_title_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", post_set_sticker_set_title_request->name) == NULL) {
    goto fail; //String
    }


    // post_set_sticker_set_title_request->title
    if (!post_set_sticker_set_title_request->title) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "title", post_set_sticker_set_title_request->title) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_parseFromJSON(cJSON *post_set_sticker_set_title_requestJSON){

    post_set_sticker_set_title_request_t *post_set_sticker_set_title_request_local_var = NULL;

    // post_set_sticker_set_title_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_set_sticker_set_title_requestJSON, "name");
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

    // post_set_sticker_set_title_request->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(post_set_sticker_set_title_requestJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (!title) {
        goto end;
    }

    
    if(!cJSON_IsString(title))
    {
    goto end; //String
    }


    post_set_sticker_set_title_request_local_var = post_set_sticker_set_title_request_create_internal (
        strdup(name->valuestring),
        strdup(title->valuestring)
        );

    return post_set_sticker_set_title_request_local_var;
end:
    return NULL;

}
