#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_get_custom_emoji_stickers_request.h"



static post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_create_internal(
    list_t *custom_emoji_ids
    ) {
    post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_local_var = malloc(sizeof(post_get_custom_emoji_stickers_request_t));
    if (!post_get_custom_emoji_stickers_request_local_var) {
        return NULL;
    }
    post_get_custom_emoji_stickers_request_local_var->custom_emoji_ids = custom_emoji_ids;

    post_get_custom_emoji_stickers_request_local_var->_library_owned = 1;
    return post_get_custom_emoji_stickers_request_local_var;
}

__attribute__((deprecated)) post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_create(
    list_t *custom_emoji_ids
    ) {
    return post_get_custom_emoji_stickers_request_create_internal (
        custom_emoji_ids
        );
}

void post_get_custom_emoji_stickers_request_free(post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request) {
    if(NULL == post_get_custom_emoji_stickers_request){
        return ;
    }
    if(post_get_custom_emoji_stickers_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_get_custom_emoji_stickers_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_get_custom_emoji_stickers_request->custom_emoji_ids) {
        list_ForEach(listEntry, post_get_custom_emoji_stickers_request->custom_emoji_ids) {
            free(listEntry->data);
        }
        list_freeList(post_get_custom_emoji_stickers_request->custom_emoji_ids);
        post_get_custom_emoji_stickers_request->custom_emoji_ids = NULL;
    }
    free(post_get_custom_emoji_stickers_request);
}

cJSON *post_get_custom_emoji_stickers_request_convertToJSON(post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request) {
    cJSON *item = cJSON_CreateObject();

    // post_get_custom_emoji_stickers_request->custom_emoji_ids
    if (!post_get_custom_emoji_stickers_request->custom_emoji_ids) {
        goto fail;
    }
    cJSON *custom_emoji_ids = cJSON_AddArrayToObject(item, "custom_emoji_ids");
    if(custom_emoji_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *custom_emoji_idsListEntry;
    list_ForEach(custom_emoji_idsListEntry, post_get_custom_emoji_stickers_request->custom_emoji_ids) {
    if(cJSON_AddStringToObject(custom_emoji_ids, "", custom_emoji_idsListEntry->data) == NULL)
    {
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

post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_parseFromJSON(cJSON *post_get_custom_emoji_stickers_requestJSON){

    post_get_custom_emoji_stickers_request_t *post_get_custom_emoji_stickers_request_local_var = NULL;

    // define the local list for post_get_custom_emoji_stickers_request->custom_emoji_ids
    list_t *custom_emoji_idsList = NULL;

    // post_get_custom_emoji_stickers_request->custom_emoji_ids
    cJSON *custom_emoji_ids = cJSON_GetObjectItemCaseSensitive(post_get_custom_emoji_stickers_requestJSON, "custom_emoji_ids");
    if (cJSON_IsNull(custom_emoji_ids)) {
        custom_emoji_ids = NULL;
    }
    if (!custom_emoji_ids) {
        goto end;
    }

    
    cJSON *custom_emoji_ids_local = NULL;
    if(!cJSON_IsArray(custom_emoji_ids)) {
        goto end;//primitive container
    }
    custom_emoji_idsList = list_createList();

    cJSON_ArrayForEach(custom_emoji_ids_local, custom_emoji_ids)
    {
        if(!cJSON_IsString(custom_emoji_ids_local))
        {
            goto end;
        }
        list_addElement(custom_emoji_idsList , strdup(custom_emoji_ids_local->valuestring));
    }


    post_get_custom_emoji_stickers_request_local_var = post_get_custom_emoji_stickers_request_create_internal (
        custom_emoji_idsList
        );

    return post_get_custom_emoji_stickers_request_local_var;
end:
    if (custom_emoji_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, custom_emoji_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(custom_emoji_idsList);
        custom_emoji_idsList = NULL;
    }
    return NULL;

}
