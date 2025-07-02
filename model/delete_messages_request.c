#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delete_messages_request.h"



static delete_messages_request_t *delete_messages_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    list_t *message_ids
    ) {
    delete_messages_request_t *delete_messages_request_local_var = malloc(sizeof(delete_messages_request_t));
    if (!delete_messages_request_local_var) {
        return NULL;
    }
    delete_messages_request_local_var->chat_id = chat_id;
    delete_messages_request_local_var->message_ids = message_ids;

    delete_messages_request_local_var->_library_owned = 1;
    return delete_messages_request_local_var;
}

__attribute__((deprecated)) delete_messages_request_t *delete_messages_request_create(
    send_message_request_chat_id_t *chat_id,
    list_t *message_ids
    ) {
    return delete_messages_request_create_internal (
        chat_id,
        message_ids
        );
}

void delete_messages_request_free(delete_messages_request_t *delete_messages_request) {
    if(NULL == delete_messages_request){
        return ;
    }
    if(delete_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "delete_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (delete_messages_request->chat_id) {
        send_message_request_chat_id_free(delete_messages_request->chat_id);
        delete_messages_request->chat_id = NULL;
    }
    if (delete_messages_request->message_ids) {
        list_ForEach(listEntry, delete_messages_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(delete_messages_request->message_ids);
        delete_messages_request->message_ids = NULL;
    }
    free(delete_messages_request);
}

cJSON *delete_messages_request_convertToJSON(delete_messages_request_t *delete_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // delete_messages_request->chat_id
    if (!delete_messages_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(delete_messages_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // delete_messages_request->message_ids
    if (!delete_messages_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, delete_messages_request->message_ids) {
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

delete_messages_request_t *delete_messages_request_parseFromJSON(cJSON *delete_messages_requestJSON){

    delete_messages_request_t *delete_messages_request_local_var = NULL;

    // define the local variable for delete_messages_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for delete_messages_request->message_ids
    list_t *message_idsList = NULL;

    // delete_messages_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(delete_messages_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // delete_messages_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(delete_messages_requestJSON, "message_ids");
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


    delete_messages_request_local_var = delete_messages_request_create_internal (
        chat_id_local_nonprim,
        message_idsList
        );

    return delete_messages_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
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
