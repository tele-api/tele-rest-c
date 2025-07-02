#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forward_messages_response.h"



static forward_messages_response_t *forward_messages_response_create_internal(
    int ok,
    list_t *result
    ) {
    forward_messages_response_t *forward_messages_response_local_var = malloc(sizeof(forward_messages_response_t));
    if (!forward_messages_response_local_var) {
        return NULL;
    }
    forward_messages_response_local_var->ok = ok;
    forward_messages_response_local_var->result = result;

    forward_messages_response_local_var->_library_owned = 1;
    return forward_messages_response_local_var;
}

__attribute__((deprecated)) forward_messages_response_t *forward_messages_response_create(
    int ok,
    list_t *result
    ) {
    return forward_messages_response_create_internal (
        ok,
        result
        );
}

void forward_messages_response_free(forward_messages_response_t *forward_messages_response) {
    if(NULL == forward_messages_response){
        return ;
    }
    if(forward_messages_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forward_messages_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forward_messages_response->result) {
        list_ForEach(listEntry, forward_messages_response->result) {
            message_id_free(listEntry->data);
        }
        list_freeList(forward_messages_response->result);
        forward_messages_response->result = NULL;
    }
    free(forward_messages_response);
}

cJSON *forward_messages_response_convertToJSON(forward_messages_response_t *forward_messages_response) {
    cJSON *item = cJSON_CreateObject();

    // forward_messages_response->ok
    if (!forward_messages_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", forward_messages_response->ok) == NULL) {
    goto fail; //Bool
    }


    // forward_messages_response->result
    if (!forward_messages_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (forward_messages_response->result) {
    list_ForEach(resultListEntry, forward_messages_response->result) {
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

forward_messages_response_t *forward_messages_response_parseFromJSON(cJSON *forward_messages_responseJSON){

    forward_messages_response_t *forward_messages_response_local_var = NULL;

    // define the local list for forward_messages_response->result
    list_t *resultList = NULL;

    // forward_messages_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(forward_messages_responseJSON, "ok");
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

    // forward_messages_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(forward_messages_responseJSON, "result");
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


    forward_messages_response_local_var = forward_messages_response_create_internal (
        ok->valueint,
        resultList
        );

    return forward_messages_response_local_var;
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
