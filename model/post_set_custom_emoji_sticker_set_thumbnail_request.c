#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_custom_emoji_sticker_set_thumbnail_request.h"



static post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_create_internal(
    char *name,
    char *custom_emoji_id
    ) {
    post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_local_var = malloc(sizeof(post_set_custom_emoji_sticker_set_thumbnail_request_t));
    if (!post_set_custom_emoji_sticker_set_thumbnail_request_local_var) {
        return NULL;
    }
    post_set_custom_emoji_sticker_set_thumbnail_request_local_var->name = name;
    post_set_custom_emoji_sticker_set_thumbnail_request_local_var->custom_emoji_id = custom_emoji_id;

    post_set_custom_emoji_sticker_set_thumbnail_request_local_var->_library_owned = 1;
    return post_set_custom_emoji_sticker_set_thumbnail_request_local_var;
}

__attribute__((deprecated)) post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_create(
    char *name,
    char *custom_emoji_id
    ) {
    return post_set_custom_emoji_sticker_set_thumbnail_request_create_internal (
        name,
        custom_emoji_id
        );
}

void post_set_custom_emoji_sticker_set_thumbnail_request_free(post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request) {
    if(NULL == post_set_custom_emoji_sticker_set_thumbnail_request){
        return ;
    }
    if(post_set_custom_emoji_sticker_set_thumbnail_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_custom_emoji_sticker_set_thumbnail_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_custom_emoji_sticker_set_thumbnail_request->name) {
        free(post_set_custom_emoji_sticker_set_thumbnail_request->name);
        post_set_custom_emoji_sticker_set_thumbnail_request->name = NULL;
    }
    if (post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) {
        free(post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id);
        post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id = NULL;
    }
    free(post_set_custom_emoji_sticker_set_thumbnail_request);
}

cJSON *post_set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_custom_emoji_sticker_set_thumbnail_request->name
    if (!post_set_custom_emoji_sticker_set_thumbnail_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", post_set_custom_emoji_sticker_set_thumbnail_request->name) == NULL) {
    goto fail; //String
    }


    // post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id
    if(post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "custom_emoji_id", post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) == NULL) {
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

post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_parseFromJSON(cJSON *post_set_custom_emoji_sticker_set_thumbnail_requestJSON){

    post_set_custom_emoji_sticker_set_thumbnail_request_t *post_set_custom_emoji_sticker_set_thumbnail_request_local_var = NULL;

    // post_set_custom_emoji_sticker_set_thumbnail_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(post_set_custom_emoji_sticker_set_thumbnail_requestJSON, "name");
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

    // post_set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(post_set_custom_emoji_sticker_set_thumbnail_requestJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (custom_emoji_id) { 
    if(!cJSON_IsString(custom_emoji_id) && !cJSON_IsNull(custom_emoji_id))
    {
    goto end; //String
    }
    }


    post_set_custom_emoji_sticker_set_thumbnail_request_local_var = post_set_custom_emoji_sticker_set_thumbnail_request_create_internal (
        strdup(name->valuestring),
        custom_emoji_id && !cJSON_IsNull(custom_emoji_id) ? strdup(custom_emoji_id->valuestring) : NULL
        );

    return post_set_custom_emoji_sticker_set_thumbnail_request_local_var;
end:
    return NULL;

}
