#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_set_sticker_emoji_list_post_request.h"



static _set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request_create_internal(
    char *sticker,
    list_t *emoji_list
    ) {
    _set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request_local_var = malloc(sizeof(_set_sticker_emoji_list_post_request_t));
    if (!_set_sticker_emoji_list_post_request_local_var) {
        return NULL;
    }
    _set_sticker_emoji_list_post_request_local_var->sticker = sticker;
    _set_sticker_emoji_list_post_request_local_var->emoji_list = emoji_list;

    _set_sticker_emoji_list_post_request_local_var->_library_owned = 1;
    return _set_sticker_emoji_list_post_request_local_var;
}

__attribute__((deprecated)) _set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request_create(
    char *sticker,
    list_t *emoji_list
    ) {
    return _set_sticker_emoji_list_post_request_create_internal (
        sticker,
        emoji_list
        );
}

void _set_sticker_emoji_list_post_request_free(_set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request) {
    if(NULL == _set_sticker_emoji_list_post_request){
        return ;
    }
    if(_set_sticker_emoji_list_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_set_sticker_emoji_list_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_set_sticker_emoji_list_post_request->sticker) {
        free(_set_sticker_emoji_list_post_request->sticker);
        _set_sticker_emoji_list_post_request->sticker = NULL;
    }
    if (_set_sticker_emoji_list_post_request->emoji_list) {
        list_ForEach(listEntry, _set_sticker_emoji_list_post_request->emoji_list) {
            free(listEntry->data);
        }
        list_freeList(_set_sticker_emoji_list_post_request->emoji_list);
        _set_sticker_emoji_list_post_request->emoji_list = NULL;
    }
    free(_set_sticker_emoji_list_post_request);
}

cJSON *_set_sticker_emoji_list_post_request_convertToJSON(_set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _set_sticker_emoji_list_post_request->sticker
    if (!_set_sticker_emoji_list_post_request->sticker) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "sticker", _set_sticker_emoji_list_post_request->sticker) == NULL) {
    goto fail; //String
    }


    // _set_sticker_emoji_list_post_request->emoji_list
    if (!_set_sticker_emoji_list_post_request->emoji_list) {
        goto fail;
    }
    cJSON *emoji_list = cJSON_AddArrayToObject(item, "emoji_list");
    if(emoji_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *emoji_listListEntry;
    list_ForEach(emoji_listListEntry, _set_sticker_emoji_list_post_request->emoji_list) {
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

_set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request_parseFromJSON(cJSON *_set_sticker_emoji_list_post_requestJSON){

    _set_sticker_emoji_list_post_request_t *_set_sticker_emoji_list_post_request_local_var = NULL;

    // define the local list for _set_sticker_emoji_list_post_request->emoji_list
    list_t *emoji_listList = NULL;

    // _set_sticker_emoji_list_post_request->sticker
    cJSON *sticker = cJSON_GetObjectItemCaseSensitive(_set_sticker_emoji_list_post_requestJSON, "sticker");
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

    // _set_sticker_emoji_list_post_request->emoji_list
    cJSON *emoji_list = cJSON_GetObjectItemCaseSensitive(_set_sticker_emoji_list_post_requestJSON, "emoji_list");
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


    _set_sticker_emoji_list_post_request_local_var = _set_sticker_emoji_list_post_request_create_internal (
        strdup(sticker->valuestring),
        emoji_listList
        );

    return _set_sticker_emoji_list_post_request_local_var;
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
