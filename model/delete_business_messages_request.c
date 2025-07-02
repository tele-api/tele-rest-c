#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_business_messages_request.h"



static delete_business_messages_request_t *delete_business_messages_request_create_internal(
    char *business_connection_id,
    list_t *message_ids
    ) {
    delete_business_messages_request_t *delete_business_messages_request_local_var = malloc(sizeof(delete_business_messages_request_t));
    if (!delete_business_messages_request_local_var) {
        return NULL;
    }
    delete_business_messages_request_local_var->business_connection_id = business_connection_id;
    delete_business_messages_request_local_var->message_ids = message_ids;

    delete_business_messages_request_local_var->_library_owned = 1;
    return delete_business_messages_request_local_var;
}

__attribute__((deprecated)) delete_business_messages_request_t *delete_business_messages_request_create(
    char *business_connection_id,
    list_t *message_ids
    ) {
    return delete_business_messages_request_create_internal (
        business_connection_id,
        message_ids
        );
}

void delete_business_messages_request_free(delete_business_messages_request_t *delete_business_messages_request) {
    if(NULL == delete_business_messages_request){
        return ;
    }
    if(delete_business_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_business_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_business_messages_request->business_connection_id) {
        free(delete_business_messages_request->business_connection_id);
        delete_business_messages_request->business_connection_id = NULL;
    }
    if (delete_business_messages_request->message_ids) {
        list_ForEach(listEntry, delete_business_messages_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(delete_business_messages_request->message_ids);
        delete_business_messages_request->message_ids = NULL;
    }
    free(delete_business_messages_request);
}

cJSON *delete_business_messages_request_convertToJSON(delete_business_messages_request_t *delete_business_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_business_messages_request->business_connection_id
    if (!delete_business_messages_request->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", delete_business_messages_request->business_connection_id) == NULL) {
    goto fail; //String
    }


    // delete_business_messages_request->message_ids
    if (!delete_business_messages_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, delete_business_messages_request->message_ids) {
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

delete_business_messages_request_t *delete_business_messages_request_parseFromJSON(cJSON *delete_business_messages_requestJSON){

    delete_business_messages_request_t *delete_business_messages_request_local_var = NULL;

    // define the local list for delete_business_messages_request->message_ids
    list_t *message_idsList = NULL;

    // delete_business_messages_request->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(delete_business_messages_requestJSON, "business_connection_id");
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

    // delete_business_messages_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(delete_business_messages_requestJSON, "message_ids");
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


    delete_business_messages_request_local_var = delete_business_messages_request_create_internal (
        strdup(business_connection_id->valuestring),
        message_idsList
        );

    return delete_business_messages_request_local_var;
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
