#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "copy_messages_response.h"



static copy_messages_response_t *copy_messages_response_create_internal(
    int ok,
    list_t *result
    ) {
    copy_messages_response_t *copy_messages_response_local_var = malloc(sizeof(copy_messages_response_t));
    if (!copy_messages_response_local_var) {
        return NULL;
    }
    copy_messages_response_local_var->ok = ok;
    copy_messages_response_local_var->result = result;

    copy_messages_response_local_var->_library_owned = 1;
    return copy_messages_response_local_var;
}

__attribute__((deprecated)) copy_messages_response_t *copy_messages_response_create(
    int ok,
    list_t *result
    ) {
    return copy_messages_response_create_internal (
        ok,
        result
        );
}

void copy_messages_response_free(copy_messages_response_t *copy_messages_response) {
    if(NULL == copy_messages_response){
        return ;
    }
    if(copy_messages_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "copy_messages_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (copy_messages_response->result) {
        list_ForEach(listEntry, copy_messages_response->result) {
            message_id_free(listEntry->data);
        }
        list_freeList(copy_messages_response->result);
        copy_messages_response->result = NULL;
    }
    free(copy_messages_response);
}

cJSON *copy_messages_response_convertToJSON(copy_messages_response_t *copy_messages_response) {
    cJSON *item = cJSON_CreateObject();

    // copy_messages_response->ok
    if (!copy_messages_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", copy_messages_response->ok) == NULL) {
    goto fail; //Bool
    }


    // copy_messages_response->result
    if (!copy_messages_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (copy_messages_response->result) {
    list_ForEach(resultListEntry, copy_messages_response->result) {
    cJSON *itemLocal = message_id_convertToJSON(resultListEntry->data);
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

copy_messages_response_t *copy_messages_response_parseFromJSON(cJSON *copy_messages_responseJSON){

    copy_messages_response_t *copy_messages_response_local_var = NULL;

    // define the local list for copy_messages_response->result
    list_t *resultList = NULL;

    // copy_messages_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(copy_messages_responseJSON, "ok");
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

    // copy_messages_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(copy_messages_responseJSON, "result");
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
        message_id_t *resultItem = message_id_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    copy_messages_response_local_var = copy_messages_response_create_internal (
        ok->valueint,
        resultList
        );

    return copy_messages_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            message_id_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
