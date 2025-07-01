#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_get_custom_emoji_stickers_post_request.h"



static _get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request_create_internal(
    list_t *custom_emoji_ids
    ) {
    _get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request_local_var = malloc(sizeof(_get_custom_emoji_stickers_post_request_t));
    if (!_get_custom_emoji_stickers_post_request_local_var) {
        return NULL;
    }
    _get_custom_emoji_stickers_post_request_local_var->custom_emoji_ids = custom_emoji_ids;

    _get_custom_emoji_stickers_post_request_local_var->_library_owned = 1;
    return _get_custom_emoji_stickers_post_request_local_var;
}

__attribute__((deprecated)) _get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request_create(
    list_t *custom_emoji_ids
    ) {
    return _get_custom_emoji_stickers_post_request_create_internal (
        custom_emoji_ids
        );
}

void _get_custom_emoji_stickers_post_request_free(_get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request) {
    if(NULL == _get_custom_emoji_stickers_post_request){
        return ;
    }
    if(_get_custom_emoji_stickers_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_get_custom_emoji_stickers_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_get_custom_emoji_stickers_post_request->custom_emoji_ids) {
        list_ForEach(listEntry, _get_custom_emoji_stickers_post_request->custom_emoji_ids) {
            free(listEntry->data);
        }
        list_freeList(_get_custom_emoji_stickers_post_request->custom_emoji_ids);
        _get_custom_emoji_stickers_post_request->custom_emoji_ids = NULL;
    }
    free(_get_custom_emoji_stickers_post_request);
}

cJSON *_get_custom_emoji_stickers_post_request_convertToJSON(_get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _get_custom_emoji_stickers_post_request->custom_emoji_ids
    if (!_get_custom_emoji_stickers_post_request->custom_emoji_ids) {
        goto fail;
    }
    cJSON *custom_emoji_ids = cJSON_AddArrayToObject(item, "custom_emoji_ids");
    if(custom_emoji_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *custom_emoji_idsListEntry;
    list_ForEach(custom_emoji_idsListEntry, _get_custom_emoji_stickers_post_request->custom_emoji_ids) {
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

_get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request_parseFromJSON(cJSON *_get_custom_emoji_stickers_post_requestJSON){

    _get_custom_emoji_stickers_post_request_t *_get_custom_emoji_stickers_post_request_local_var = NULL;

    // define the local list for _get_custom_emoji_stickers_post_request->custom_emoji_ids
    list_t *custom_emoji_idsList = NULL;

    // _get_custom_emoji_stickers_post_request->custom_emoji_ids
    cJSON *custom_emoji_ids = cJSON_GetObjectItemCaseSensitive(_get_custom_emoji_stickers_post_requestJSON, "custom_emoji_ids");
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


    _get_custom_emoji_stickers_post_request_local_var = _get_custom_emoji_stickers_post_request_create_internal (
        custom_emoji_idsList
        );

    return _get_custom_emoji_stickers_post_request_local_var;
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
