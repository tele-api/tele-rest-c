#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_custom_emoji_stickers_response.h"



static get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_create_internal(
    int ok,
    list_t *result
    ) {
    get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_local_var = malloc(sizeof(get_custom_emoji_stickers_response_t));
    if (!get_custom_emoji_stickers_response_local_var) {
        return NULL;
    }
    get_custom_emoji_stickers_response_local_var->ok = ok;
    get_custom_emoji_stickers_response_local_var->result = result;

    get_custom_emoji_stickers_response_local_var->_library_owned = 1;
    return get_custom_emoji_stickers_response_local_var;
}

__attribute__((deprecated)) get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_create(
    int ok,
    list_t *result
    ) {
    return get_custom_emoji_stickers_response_create_internal (
        ok,
        result
        );
}

void get_custom_emoji_stickers_response_free(get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response) {
    if(NULL == get_custom_emoji_stickers_response){
        return ;
    }
    if(get_custom_emoji_stickers_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_custom_emoji_stickers_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_custom_emoji_stickers_response->result) {
        list_ForEach(listEntry, get_custom_emoji_stickers_response->result) {
            sticker_free(listEntry->data);
        }
        list_freeList(get_custom_emoji_stickers_response->result);
        get_custom_emoji_stickers_response->result = NULL;
    }
    free(get_custom_emoji_stickers_response);
}

cJSON *get_custom_emoji_stickers_response_convertToJSON(get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response) {
    cJSON *item = cJSON_CreateObject();

    // get_custom_emoji_stickers_response->ok
    if (!get_custom_emoji_stickers_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_custom_emoji_stickers_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_custom_emoji_stickers_response->result
    if (!get_custom_emoji_stickers_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (get_custom_emoji_stickers_response->result) {
    list_ForEach(resultListEntry, get_custom_emoji_stickers_response->result) {
    cJSON *itemLocal = sticker_convertToJSON(resultListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(result, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_parseFromJSON(cJSON *get_custom_emoji_stickers_responseJSON){

    get_custom_emoji_stickers_response_t *get_custom_emoji_stickers_response_local_var = NULL;

    // define the local list for get_custom_emoji_stickers_response->result
    list_t *resultList = NULL;

    // get_custom_emoji_stickers_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_custom_emoji_stickers_responseJSON, "ok");
    if (cJSON_IsNull(ok)) {
        ok = NULL;
    }
    if (!ok) {
        goto end;
    }

    
    if(!cJSON_IsBool(ok))
    {
    goto end; //Bool
    }

    // get_custom_emoji_stickers_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_custom_emoji_stickers_responseJSON, "result");
    if (cJSON_IsNull(result)) {
        result = NULL;
    }
    if (!result) {
        goto end;
    }

    
    cJSON *result_local_nonprimitive = NULL;
    if(!cJSON_IsArray(result)){
        goto end; //nonprimitive container
    }

    resultList = list_createList();

    cJSON_ArrayForEach(result_local_nonprimitive,result )
    {
        if(!cJSON_IsObject(result_local_nonprimitive)){
            goto end;
        }
        sticker_t *resultItem = sticker_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    get_custom_emoji_stickers_response_local_var = get_custom_emoji_stickers_response_create_internal (
        ok->valueint,
        resultList
        );

    return get_custom_emoji_stickers_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            sticker_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
