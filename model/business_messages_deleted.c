#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "business_messages_deleted.h"



static business_messages_deleted_t *business_messages_deleted_create_internal(
    char *business_connection_id,
    chat_t *chat,
    list_t *message_ids
    ) {
    business_messages_deleted_t *business_messages_deleted_local_var = malloc(sizeof(business_messages_deleted_t));
    if (!business_messages_deleted_local_var) {
        return NULL;
    }
    business_messages_deleted_local_var->business_connection_id = business_connection_id;
    business_messages_deleted_local_var->chat = chat;
    business_messages_deleted_local_var->message_ids = message_ids;

    business_messages_deleted_local_var->_library_owned = 1;
    return business_messages_deleted_local_var;
}

__attribute__((deprecated)) business_messages_deleted_t *business_messages_deleted_create(
    char *business_connection_id,
    chat_t *chat,
    list_t *message_ids
    ) {
    return business_messages_deleted_create_internal (
        business_connection_id,
        chat,
        message_ids
        );
}

void business_messages_deleted_free(business_messages_deleted_t *business_messages_deleted) {
    if(NULL == business_messages_deleted){
        return ;
    }
    if(business_messages_deleted->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "business_messages_deleted_free");
        return ;
    }
    listEntry_t *listEntry;
    if (business_messages_deleted->business_connection_id) {
        free(business_messages_deleted->business_connection_id);
        business_messages_deleted->business_connection_id = NULL;
    }
    if (business_messages_deleted->chat) {
        chat_free(business_messages_deleted->chat);
        business_messages_deleted->chat = NULL;
    }
    if (business_messages_deleted->message_ids) {
        list_ForEach(listEntry, business_messages_deleted->message_ids) {
            free(listEntry->data);
        }
        list_freeList(business_messages_deleted->message_ids);
        business_messages_deleted->message_ids = NULL;
    }
    free(business_messages_deleted);
}

cJSON *business_messages_deleted_convertToJSON(business_messages_deleted_t *business_messages_deleted) {
    cJSON *item = cJSON_CreateObject();

    // business_messages_deleted->business_connection_id
    if (!business_messages_deleted->business_connection_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "business_connection_id", business_messages_deleted->business_connection_id) == NULL) {
    goto fail; //String
    }


    // business_messages_deleted->chat
    if (!business_messages_deleted->chat) {
        goto fail;
    }
    cJSON *chat_local_JSON = chat_convertToJSON(business_messages_deleted->chat);
    if(chat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat", chat_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // business_messages_deleted->message_ids
    if (!business_messages_deleted->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, business_messages_deleted->message_ids) {
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

business_messages_deleted_t *business_messages_deleted_parseFromJSON(cJSON *business_messages_deletedJSON){

    business_messages_deleted_t *business_messages_deleted_local_var = NULL;

    // define the local variable for business_messages_deleted->chat
    chat_t *chat_local_nonprim = NULL;

    // define the local list for business_messages_deleted->message_ids
    list_t *message_idsList = NULL;

    // business_messages_deleted->business_connection_id
    cJSON *business_connection_id = cJSON_GetObjectItemCaseSensitive(business_messages_deletedJSON, "business_connection_id");
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

    // business_messages_deleted->chat
    cJSON *chat = cJSON_GetObjectItemCaseSensitive(business_messages_deletedJSON, "chat");
    if (cJSON_IsNull(chat)) {
        chat = NULL;
    }
    if (!chat) {
        goto end;
    }

    
    chat_local_nonprim = chat_parseFromJSON(chat); //nonprimitive

    // business_messages_deleted->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(business_messages_deletedJSON, "message_ids");
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


    business_messages_deleted_local_var = business_messages_deleted_create_internal (
        strdup(business_connection_id->valuestring),
        chat_local_nonprim,
        message_idsList
        );

    return business_messages_deleted_local_var;
end:
    if (chat_local_nonprim) {
        chat_free(chat_local_nonprim);
        chat_local_nonprim = NULL;
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
