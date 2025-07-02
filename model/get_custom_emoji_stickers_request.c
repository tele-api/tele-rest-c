#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_custom_emoji_stickers_request.h"



static get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_create_internal(
    list_t *custom_emoji_ids
    ) {
    get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_local_var = malloc(sizeof(get_custom_emoji_stickers_request_t));
    if (!get_custom_emoji_stickers_request_local_var) {
        return NULL;
    }
    get_custom_emoji_stickers_request_local_var->custom_emoji_ids = custom_emoji_ids;

    get_custom_emoji_stickers_request_local_var->_library_owned = 1;
    return get_custom_emoji_stickers_request_local_var;
}

__attribute__((deprecated)) get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_create(
    list_t *custom_emoji_ids
    ) {
    return get_custom_emoji_stickers_request_create_internal (
        custom_emoji_ids
        );
}

void get_custom_emoji_stickers_request_free(get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request) {
    if(NULL == get_custom_emoji_stickers_request){
        return ;
    }
    if(get_custom_emoji_stickers_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_custom_emoji_stickers_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_custom_emoji_stickers_request->custom_emoji_ids) {
        list_ForEach(listEntry, get_custom_emoji_stickers_request->custom_emoji_ids) {
            free(listEntry->data);
        }
        list_freeList(get_custom_emoji_stickers_request->custom_emoji_ids);
        get_custom_emoji_stickers_request->custom_emoji_ids = NULL;
    }
    free(get_custom_emoji_stickers_request);
}

cJSON *get_custom_emoji_stickers_request_convertToJSON(get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request) {
    cJSON *item = cJSON_CreateObject();

    // get_custom_emoji_stickers_request->custom_emoji_ids
    if (!get_custom_emoji_stickers_request->custom_emoji_ids) {
        goto fail;
    }
    cJSON *custom_emoji_ids = cJSON_AddArrayToObject(item, "custom_emoji_ids");
    if(custom_emoji_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *custom_emoji_idsListEntry;
    list_ForEach(custom_emoji_idsListEntry, get_custom_emoji_stickers_request->custom_emoji_ids) {
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

get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_parseFromJSON(cJSON *get_custom_emoji_stickers_requestJSON){

    get_custom_emoji_stickers_request_t *get_custom_emoji_stickers_request_local_var = NULL;

    // define the local list for get_custom_emoji_stickers_request->custom_emoji_ids
    list_t *custom_emoji_idsList = NULL;

    // get_custom_emoji_stickers_request->custom_emoji_ids
    cJSON *custom_emoji_ids = cJSON_GetObjectItemCaseSensitive(get_custom_emoji_stickers_requestJSON, "custom_emoji_ids");
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


    get_custom_emoji_stickers_request_local_var = get_custom_emoji_stickers_request_create_internal (
        custom_emoji_idsList
        );

    return get_custom_emoji_stickers_request_local_var;
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
