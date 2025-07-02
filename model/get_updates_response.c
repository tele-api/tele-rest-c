#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "get_updates_response.h"



static get_updates_response_t *get_updates_response_create_internal(
    int ok,
    list_t *result
    ) {
    get_updates_response_t *get_updates_response_local_var = malloc(sizeof(get_updates_response_t));
    if (!get_updates_response_local_var) {
        return NULL;
    }
    get_updates_response_local_var->ok = ok;
    get_updates_response_local_var->result = result;

    get_updates_response_local_var->_library_owned = 1;
    return get_updates_response_local_var;
}

__attribute__((deprecated)) get_updates_response_t *get_updates_response_create(
    int ok,
    list_t *result
    ) {
    return get_updates_response_create_internal (
        ok,
        result
        );
}

void get_updates_response_free(get_updates_response_t *get_updates_response) {
    if(NULL == get_updates_response){
        return ;
    }
    if(get_updates_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "get_updates_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (get_updates_response->result) {
        list_ForEach(listEntry, get_updates_response->result) {
            update_free(listEntry->data);
        }
        list_freeList(get_updates_response->result);
        get_updates_response->result = NULL;
    }
    free(get_updates_response);
}

cJSON *get_updates_response_convertToJSON(get_updates_response_t *get_updates_response) {
    cJSON *item = cJSON_CreateObject();

    // get_updates_response->ok
    if (!get_updates_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", get_updates_response->ok) == NULL) {
    goto fail; //Bool
    }


    // get_updates_response->result
    if (!get_updates_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (get_updates_response->result) {
    list_ForEach(resultListEntry, get_updates_response->result) {
    cJSON *itemLocal = update_convertToJSON(resultListEntry->data);
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

get_updates_response_t *get_updates_response_parseFromJSON(cJSON *get_updates_responseJSON){

    get_updates_response_t *get_updates_response_local_var = NULL;

    // define the local list for get_updates_response->result
    list_t *resultList = NULL;

    // get_updates_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(get_updates_responseJSON, "ok");
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

    // get_updates_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(get_updates_responseJSON, "result");
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
        update_t *resultItem = update_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    get_updates_response_local_var = get_updates_response_create_internal (
        ok->valueint,
        resultList
        );

    return get_updates_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            update_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
