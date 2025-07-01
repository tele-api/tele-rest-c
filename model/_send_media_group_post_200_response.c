#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_send_media_group_post_200_response.h"



static _send_media_group_post_200_response_t *_send_media_group_post_200_response_create_internal(
    int ok,
    list_t *result
    ) {
    _send_media_group_post_200_response_t *_send_media_group_post_200_response_local_var = malloc(sizeof(_send_media_group_post_200_response_t));
    if (!_send_media_group_post_200_response_local_var) {
        return NULL;
    }
    _send_media_group_post_200_response_local_var->ok = ok;
    _send_media_group_post_200_response_local_var->result = result;

    _send_media_group_post_200_response_local_var->_library_owned = 1;
    return _send_media_group_post_200_response_local_var;
}

__attribute__((deprecated)) _send_media_group_post_200_response_t *_send_media_group_post_200_response_create(
    int ok,
    list_t *result
    ) {
    return _send_media_group_post_200_response_create_internal (
        ok,
        result
        );
}

void _send_media_group_post_200_response_free(_send_media_group_post_200_response_t *_send_media_group_post_200_response) {
    if(NULL == _send_media_group_post_200_response){
        return ;
    }
    if(_send_media_group_post_200_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_send_media_group_post_200_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_send_media_group_post_200_response->result) {
        list_ForEach(listEntry, _send_media_group_post_200_response->result) {
            message_free(listEntry->data);
        }
        list_freeList(_send_media_group_post_200_response->result);
        _send_media_group_post_200_response->result = NULL;
    }
    free(_send_media_group_post_200_response);
}

cJSON *_send_media_group_post_200_response_convertToJSON(_send_media_group_post_200_response_t *_send_media_group_post_200_response) {
    cJSON *item = cJSON_CreateObject();

    // _send_media_group_post_200_response->ok
    if (!_send_media_group_post_200_response->ok) {
        goto fail;
    }
    if(cJSON_AddBoolToObject(item, "ok", _send_media_group_post_200_response->ok) == NULL) {
    goto fail; //Bool
    }


    // _send_media_group_post_200_response->result
    if (!_send_media_group_post_200_response->result) {
        goto fail;
    }
    cJSON *result = cJSON_AddArrayToObject(item, "result");
    if(result == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultListEntry;
    if (_send_media_group_post_200_response->result) {
    list_ForEach(resultListEntry, _send_media_group_post_200_response->result) {
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

_send_media_group_post_200_response_t *_send_media_group_post_200_response_parseFromJSON(cJSON *_send_media_group_post_200_responseJSON){

    _send_media_group_post_200_response_t *_send_media_group_post_200_response_local_var = NULL;

    // define the local list for _send_media_group_post_200_response->result
    list_t *resultList = NULL;

    // _send_media_group_post_200_response->ok
    cJSON *ok = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_200_responseJSON, "ok");
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

    // _send_media_group_post_200_response->result
    cJSON *result = cJSON_GetObjectItemCaseSensitive(_send_media_group_post_200_responseJSON, "result");
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


    _send_media_group_post_200_response_local_var = _send_media_group_post_200_response_create_internal (
        ok->valueint,
        resultList
        );

    return _send_media_group_post_200_response_local_var;
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
