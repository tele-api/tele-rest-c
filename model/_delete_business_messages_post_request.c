#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_delete_business_messages_post_request.h"



static _delete_business_messages_post_request_t *_delete_business_messages_post_request_create_internal(
    char *business_connection_id,
    list_t *message_ids
    ) {
    _delete_business_messages_post_request_t *_delete_business_messages_post_request_local_var = malloc(sizeof(_delete_business_messages_post_request_t));
    if (!_delete_business_messages_post_request_local_var) {
        return NULL;
    }
    _delete_business_messages_post_request_local_var->business_connection_id = business_connection_id;
    _delete_business_messages_post_request_local_var->message_ids = message_ids;

    _delete_business_messages_post_request_local_var->_library_owned = 1;
    return _delete_business_messages_post_request_local_var;
}

__attribute__((deprecated)) _delete_business_messages_post_request_t *_delete_business_messages_post_request_create(
    char *business_connection_id,
    list_t *message_ids
    ) {
    return _delete_business_messages_post_request_create_internal (
        business_connection_id,
        message_ids
        );
}

void _delete_business_messages_post_request_free(_delete_business_messages_post_request_t *_delete_business_messages_post_request) {
    if(NULL == _delete_business_messages_post_request){
        return ;
    }
    if(_delete_business_messages_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_delete_business_messages_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_delete_business_messages_post_request->business_connection_id) {
        free(_delete_business_messages_post_request->business_connection_id);
        _delete_business_messages_post_request->business_connection_id = NULL;
    }
    if (_delete_business_messages_post_request->message_ids) {
        list_ForEach(listEntry, _delete_business_messages_post_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(_delete_business_messages_post_request->message_ids);
        _delete_business_messages_post_request->message_ids = NULL;
    }
    free(_delete_business_messages_post_request);
}

cJSON *_delete_business_messages_post_request_convertToJSON(_delete_business_messages_post_request_t *_delete_business_messages_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _delete_business_messages_post_request->business_connection_id
    if (!_delete_business_messages_post_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", _delete_business_messages_post_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // _delete_business_messages_post_request->message_ids
    if (!_delete_business_messages_post_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, _delete_business_messages_post_request->message_ids) {
    if(cJSON_AddNumberToObject(message_ids, "", *(double *)message_idsListEntry->data) == NULL)
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

_delete_business_messages_post_request_t *_delete_business_messages_post_request_parseFromJSON(cJSON *_delete_business_messages_post_requestJSON){

    _delete_business_messages_post_request_t *_delete_business_messages_post_request_local_var = NULL;

    // define the local list for _delete_business_messages_post_request->message_ids
    list_t *message_idsList = NULL;

    // _delete_business_messages_post_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(_delete_business_messages_post_requestJSON, "business_connection_id");
    if (cJSON_IsNull(business_connection_id)) {
        business_connection_id = NULL;
    }
    if (!business_connection_id) {
        goto end;
    }

    
    if(!cJSON_IsString(business_connection_id))
    {
    goto end; //String
    }

    // _delete_business_messages_post_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(_delete_business_messages_post_requestJSON, "message_ids");
    if (cJSON_IsNull(message_ids)) {
        message_ids = NULL;
    }
    if (!message_ids) {
        goto end;
    }

    
    cJSON *message_ids_local = NULL;
    if(!cJSON_IsArray(message_ids)) {
        goto end;//primitive container
    }
    message_idsList = list_createList();

    cJSON_ArrayForEach(message_ids_local, message_ids)
    {
        if(!cJSON_IsNumber(message_ids_local))
        {
            goto end;
        }
        double *message_ids_local_value = calloc(1, sizeof(double));
        if(!message_ids_local_value)
        {
            goto end;
        }
        *message_ids_local_value = message_ids_local->valuedouble;
        list_addElement(message_idsList , message_ids_local_value);
    }


    _delete_business_messages_post_request_local_var = _delete_business_messages_post_request_create_internal (
        strdup(business_connection_id->valuestring),
        message_idsList
        );

    return _delete_business_messages_post_request_local_var;
end:
    if (message_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, message_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(message_idsList);
        message_idsList = NULL;
    }
    return NULL;

}
