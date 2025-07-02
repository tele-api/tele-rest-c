#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "set_sticker_emoji_list_request.h"



static set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_create_internal(
    char *sticker,
    list_t *emoji_list
    ) {
    set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_local_var = malloc(sizeof(set_sticker_emoji_list_request_t));
    if (!set_sticker_emoji_list_request_local_var) {
        return NULL;
    }
    set_sticker_emoji_list_request_local_var->sticker = sticker;
    set_sticker_emoji_list_request_local_var->emoji_list = emoji_list;

    set_sticker_emoji_list_request_local_var->_library_owned = 1;
    return set_sticker_emoji_list_request_local_var;
}

__attribute__((deprecated)) set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_create(
    char *sticker,
    list_t *emoji_list
    ) {
    return set_sticker_emoji_list_request_create_internal (
        sticker,
        emoji_list
        );
}

void set_sticker_emoji_list_request_free(set_sticker_emoji_list_request_t *set_sticker_emoji_list_request) {
    if(NULL == set_sticker_emoji_list_request){
        return ;
    }
    if(set_sticker_emoji_list_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "set_sticker_emoji_list_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (set_sticker_emoji_list_request->sticker) {
        free(set_sticker_emoji_list_request->sticker);
        set_sticker_emoji_list_request->sticker = NULL;
    }
    if (set_sticker_emoji_list_request->emoji_list) {
        list_ForEach(listEntry, set_sticker_emoji_list_request->emoji_list) {
            free(listEntry->data);
        }
        list_freeList(set_sticker_emoji_list_request->emoji_list);
        set_sticker_emoji_list_request->emoji_list = NULL;
    }
    free(set_sticker_emoji_list_request);
}

cJSON *set_sticker_emoji_list_request_convertToJSON(set_sticker_emoji_list_request_t *set_sticker_emoji_list_request) {
    cJSON *item = cJSON_CreateObject();

    // set_sticker_emoji_list_request->sticker
    if (!set_sticker_emoji_list_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", set_sticker_emoji_list_request->sticker) == NULL) {
    goto fail; //String
    }


    // set_sticker_emoji_list_request->emoji_list
    if (!set_sticker_emoji_list_request->emoji_list) {
        goto fail;
    }
    cJSON *emoji_list = cJSON_AddArrayToObject(item, "emoji_list");
    if(emoji_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *emoji_listListEntry;
    list_ForEach(emoji_listListEntry, set_sticker_emoji_list_request->emoji_list) {
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

set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_parseFromJSON(cJSON *set_sticker_emoji_list_requestJSON){

    set_sticker_emoji_list_request_t *set_sticker_emoji_list_request_local_var = NULL;

    // define the local list for set_sticker_emoji_list_request->emoji_list
    list_t *emoji_listList = NULL;

    // set_sticker_emoji_list_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(set_sticker_emoji_list_requestJSON, "sticker");
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

    // set_sticker_emoji_list_request->emoji_list
    cJSON *emoji_list = cJSON_GetObjectItemCaseSensitive(set_sticker_emoji_list_requestJSON, "emoji_list");
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


    set_sticker_emoji_list_request_local_var = set_sticker_emoji_list_request_create_internal (
        strdup(sticker->valuestring),
        emoji_listList
        );

    return set_sticker_emoji_list_request_local_var;
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
