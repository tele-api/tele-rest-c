#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_media_group_response.h"



static send_media_group_response_t *send_media_group_response_create_internal(
    int ok,
    list_t *result
    ) {
    send_media_group_response_t *send_media_group_response_local_var = malloc(sizeof(send_media_group_response_t));
    if (!send_media_group_response_local_var) {
        return NULL;
    }
    send_media_group_response_local_var->ok = ok;
    send_media_group_response_local_var->result = result;

    send_media_group_response_local_var->_library_owned = 1;
    return send_media_group_response_local_var;
}

__attribute__((deprecated)) send_media_group_response_t *send_media_group_response_create(
    int ok,
    list_t *result
    ) {
    return send_media_group_response_create_internal (
        ok,
        result
        );
}

void send_media_group_response_free(send_media_group_response_t *send_media_group_response) {
    if(NULL == send_media_group_response){
        return ;
    }
    if(send_media_group_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "send_media_group_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (send_media_group_response->result) {
        list_ForEach(listEntry, send_media_group_response->result) {
            message_free(listEntry->data);
        }
        list_freeList(send_media_group_response->result);
        send_media_group_response->result = NULL;
    }
    free(send_media_group_response);
}

cJSON *send_media_group_response_convertToJSON(send_media_group_response_t *send_media_group_response) {
    cJSON *item = cJSON_CreateObject();

    // send_media_group_response->ok
    if (!send_media_group_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", send_media_group_response->ok) == NULL) {
    goto fail; //Bool
    }


    // send_media_group_response->result
    if (!send_media_group_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (send_media_group_response->result) {
    list_ForEach(resultListEntry, send_media_group_response->result) {
    cJSON *itemLocal = message_convertToJSON(resultListEntry->data);
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

send_media_group_response_t *send_media_group_response_parseFromJSON(cJSON *send_media_group_responseJSON){

    send_media_group_response_t *send_media_group_response_local_var = NULL;

    // define the local list for send_media_group_response->result
    list_t *resultList = NULL;

    // send_media_group_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(send_media_group_responseJSON, "ok");
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

    // send_media_group_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(send_media_group_responseJSON, "result");
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
        message_t *resultItem = message_parseFromJSON(result_local_nonprimitive);

        list_addElement(resultList, resultItem);
    }


    send_media_group_response_local_var = send_media_group_response_create_internal (
        ok->valueint,
        resultList
        );

    return send_media_group_response_local_var;
end:
    if (resultList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultList) {
            message_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultList);
        resultList = NULL;
    }
    return NULL;

}
