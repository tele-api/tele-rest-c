#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_custom_emoji_sticker_set_thumbnail_request.h"



static set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_create_internal(
    char *name,
    char *custom_emoji_id
    ) {
    set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_local_var = malloc(sizeof(set_custom_emoji_sticker_set_thumbnail_request_t));
    if (!set_custom_emoji_sticker_set_thumbnail_request_local_var) {
        return NULL;
    }
    set_custom_emoji_sticker_set_thumbnail_request_local_var->name = name;
    set_custom_emoji_sticker_set_thumbnail_request_local_var->custom_emoji_id = custom_emoji_id;

    set_custom_emoji_sticker_set_thumbnail_request_local_var->_library_owned = 1;
    return set_custom_emoji_sticker_set_thumbnail_request_local_var;
}

__attribute__((deprecated)) set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_create(
    char *name,
    char *custom_emoji_id
    ) {
    return set_custom_emoji_sticker_set_thumbnail_request_create_internal (
        name,
        custom_emoji_id
        );
}

void set_custom_emoji_sticker_set_thumbnail_request_free(set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request) {
    if(NULL == set_custom_emoji_sticker_set_thumbnail_request){
        return ;
    }
    if(set_custom_emoji_sticker_set_thumbnail_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_custom_emoji_sticker_set_thumbnail_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_custom_emoji_sticker_set_thumbnail_request->name) {
        free(set_custom_emoji_sticker_set_thumbnail_request->name);
        set_custom_emoji_sticker_set_thumbnail_request->name = NULL;
    }
    if (set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) {
        free(set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id);
        set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id = NULL;
    }
    free(set_custom_emoji_sticker_set_thumbnail_request);
}

cJSON *set_custom_emoji_sticker_set_thumbnail_request_convertToJSON(set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request) {
    cJSON *item = cJSON_CreateObject();

    // set_custom_emoji_sticker_set_thumbnail_request->name
    if (!set_custom_emoji_sticker_set_thumbnail_request->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", set_custom_emoji_sticker_set_thumbnail_request->name) == NULL) {
    goto fail; //String
    }


    // set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id
    if(set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) {
    if(cJSON_AddStringToObject(item, "custom_emoji_id", set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id) == NULL) {
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

set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_parseFromJSON(cJSON *set_custom_emoji_sticker_set_thumbnail_requestJSON){

    set_custom_emoji_sticker_set_thumbnail_request_t *set_custom_emoji_sticker_set_thumbnail_request_local_var = NULL;

    // set_custom_emoji_sticker_set_thumbnail_request->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(set_custom_emoji_sticker_set_thumbnail_requestJSON, "name");
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

    // set_custom_emoji_sticker_set_thumbnail_request->custom_emoji_id
    cJSON *custom_emoji_id = cJSON_GetObjectItemCaseSensitive(set_custom_emoji_sticker_set_thumbnail_requestJSON, "custom_emoji_id");
    if (cJSON_IsNull(custom_emoji_id)) {
        custom_emoji_id = NULL;
    }
    if (custom_emoji_id) { 
    if(!cJSON_IsString(custom_emoji_id) && !cJSON_IsNull(custom_emoji_id))
    {
    goto end; //String
    }
    }


    set_custom_emoji_sticker_set_thumbnail_request_local_var = set_custom_emoji_sticker_set_thumbnail_request_create_internal (
        strdup(name->valuestring),
        custom_emoji_id && !cJSON_IsNull(custom_emoji_id) ? strdup(custom_emoji_id->valuestring) : NULL
        );

    return set_custom_emoji_sticker_set_thumbnail_request_local_var;
end:
    return NULL;

}
