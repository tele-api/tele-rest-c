#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_set_sticker_emoji_list_request.h"



static post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_create_internal(
    char *sticker,
    list_t *emoji_list
    ) {
    post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_local_var = malloc(sizeof(post_set_sticker_emoji_list_request_t));
    if (!post_set_sticker_emoji_list_request_local_var) {
        return NULL;
    }
    post_set_sticker_emoji_list_request_local_var->sticker = sticker;
    post_set_sticker_emoji_list_request_local_var->emoji_list = emoji_list;

    post_set_sticker_emoji_list_request_local_var->_library_owned = 1;
    return post_set_sticker_emoji_list_request_local_var;
}

__attribute__((deprecated)) post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_create(
    char *sticker,
    list_t *emoji_list
    ) {
    return post_set_sticker_emoji_list_request_create_internal (
        sticker,
        emoji_list
        );
}

void post_set_sticker_emoji_list_request_free(post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request) {
    if(NULL == post_set_sticker_emoji_list_request){
        return ;
    }
    if(post_set_sticker_emoji_list_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_set_sticker_emoji_list_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_set_sticker_emoji_list_request->sticker) {
        free(post_set_sticker_emoji_list_request->sticker);
        post_set_sticker_emoji_list_request->sticker = NULL;
    }
    if (post_set_sticker_emoji_list_request->emoji_list) {
        list_ForEach(listEntry, post_set_sticker_emoji_list_request->emoji_list) {
            free(listEntry->data);
        }
        list_freeList(post_set_sticker_emoji_list_request->emoji_list);
        post_set_sticker_emoji_list_request->emoji_list = NULL;
    }
    free(post_set_sticker_emoji_list_request);
}

cJSON *post_set_sticker_emoji_list_request_convertToJSON(post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request) {
    cJSON *item = cJSON_CreateObject();

    // post_set_sticker_emoji_list_request->sticker
    if (!post_set_sticker_emoji_list_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", post_set_sticker_emoji_list_request->sticker) == NULL) {
    goto fail; //String
    }


    // post_set_sticker_emoji_list_request->emoji_list
    if (!post_set_sticker_emoji_list_request->emoji_list) {
        goto fail;
    }
    cJSON *emoji_list = cJSON_AddArrayToObject(item, "emoji_list");
    if(emoji_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *emoji_listListEntry;
    list_ForEach(emoji_listListEntry, post_set_sticker_emoji_list_request->emoji_list) {
    if(cJSON_AddStringToObject(emoji_list, "", emoji_listListEntry->data) == NULL)
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

post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_parseFromJSON(cJSON *post_set_sticker_emoji_list_requestJSON){

    post_set_sticker_emoji_list_request_t *post_set_sticker_emoji_list_request_local_var = NULL;

    // define the local list for post_set_sticker_emoji_list_request->emoji_list
    list_t *emoji_listList = NULL;

    // post_set_sticker_emoji_list_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(post_set_sticker_emoji_list_requestJSON, "sticker");
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

    // post_set_sticker_emoji_list_request->emoji_list
    cJSON *emoji_list = cJSON_GetObjectItemCaseSensitive(post_set_sticker_emoji_list_requestJSON, "emoji_list");
    if (cJSON_IsNull(emoji_list)) {
        emoji_list = NULL;
    }
    if (!emoji_list) {
        goto end;
    }

    
    cJSON *emoji_list_local = NULL;
    if(!cJSON_IsArray(emoji_list)) {
        goto end;//primitive container
    }
    emoji_listList = list_createList();

    cJSON_ArrayForEach(emoji_list_local, emoji_list)
    {
        if(!cJSON_IsString(emoji_list_local))
        {
            goto end;
        }
        list_addElement(emoji_listList , strdup(emoji_list_local->valuestring));
    }


    post_set_sticker_emoji_list_request_local_var = post_set_sticker_emoji_list_request_create_internal (
        strdup(sticker->valuestring),
        emoji_listList
        );

    return post_set_sticker_emoji_list_request_local_var;
end:
    if (emoji_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, emoji_listList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(emoji_listList);
        emoji_listList = NULL;
    }
    return NULL;

}
