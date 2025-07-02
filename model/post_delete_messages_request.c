#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_delete_messages_request.h"



static post_delete_messages_request_t *post_delete_messages_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    list_t *message_ids
    ) {
    post_delete_messages_request_t *post_delete_messages_request_local_var = malloc(sizeof(post_delete_messages_request_t));
    if (!post_delete_messages_request_local_var) {
        return NULL;
    }
    post_delete_messages_request_local_var->chat_id = chat_id;
    post_delete_messages_request_local_var->message_ids = message_ids;

    post_delete_messages_request_local_var->_library_owned = 1;
    return post_delete_messages_request_local_var;
}

__attribute__((deprecated)) post_delete_messages_request_t *post_delete_messages_request_create(
    post_send_message_request_chat_id_t *chat_id,
    list_t *message_ids
    ) {
    return post_delete_messages_request_create_internal (
        chat_id,
        message_ids
        );
}

void post_delete_messages_request_free(post_delete_messages_request_t *post_delete_messages_request) {
    if(NULL == post_delete_messages_request){
        return ;
    }
    if(post_delete_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_delete_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_delete_messages_request->chat_id) {
        post_send_message_request_chat_id_free(post_delete_messages_request->chat_id);
        post_delete_messages_request->chat_id = NULL;
    }
    if (post_delete_messages_request->message_ids) {
        list_ForEach(listEntry, post_delete_messages_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(post_delete_messages_request->message_ids);
        post_delete_messages_request->message_ids = NULL;
    }
    free(post_delete_messages_request);
}

cJSON *post_delete_messages_request_convertToJSON(post_delete_messages_request_t *post_delete_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // post_delete_messages_request->chat_id
    if (!post_delete_messages_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_delete_messages_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_delete_messages_request->message_ids
    if (!post_delete_messages_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, post_delete_messages_request->message_ids) {
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

post_delete_messages_request_t *post_delete_messages_request_parseFromJSON(cJSON *post_delete_messages_requestJSON){

    post_delete_messages_request_t *post_delete_messages_request_local_var = NULL;

    // define the local variable for post_delete_messages_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local list for post_delete_messages_request->message_ids
    list_t *message_idsList = NULL;

    // post_delete_messages_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_delete_messages_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_delete_messages_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(post_delete_messages_requestJSON, "message_ids");
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


    post_delete_messages_request_local_var = post_delete_messages_request_create_internal (
        chat_id_local_nonprim,
        message_idsList
        );

    return post_delete_messages_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
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
