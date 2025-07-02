#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "copy_messages_request.h"



static copy_messages_request_t *copy_messages_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    forward_messages_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
    ) {
    copy_messages_request_t *copy_messages_request_local_var = malloc(sizeof(copy_messages_request_t));
    if (!copy_messages_request_local_var) {
        return NULL;
    }
    copy_messages_request_local_var->chat_id = chat_id;
    copy_messages_request_local_var->from_chat_id = from_chat_id;
    copy_messages_request_local_var->message_ids = message_ids;
    copy_messages_request_local_var->message_thread_id = message_thread_id;
    copy_messages_request_local_var->disable_notification = disable_notification;
    copy_messages_request_local_var->protect_content = protect_content;
    copy_messages_request_local_var->remove_caption = remove_caption;

    copy_messages_request_local_var->_library_owned = 1;
    return copy_messages_request_local_var;
}

__attribute__((deprecated)) copy_messages_request_t *copy_messages_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_messages_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
    ) {
    return copy_messages_request_create_internal (
        chat_id,
        from_chat_id,
        message_ids,
        message_thread_id,
        disable_notification,
        protect_content,
        remove_caption
        );
}

void copy_messages_request_free(copy_messages_request_t *copy_messages_request) {
    if(NULL == copy_messages_request){
        return ;
    }
    if(copy_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "copy_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (copy_messages_request->chat_id) {
        send_message_request_chat_id_free(copy_messages_request->chat_id);
        copy_messages_request->chat_id = NULL;
    }
    if (copy_messages_request->from_chat_id) {
        forward_messages_request_from_chat_id_free(copy_messages_request->from_chat_id);
        copy_messages_request->from_chat_id = NULL;
    }
    if (copy_messages_request->message_ids) {
        list_ForEach(listEntry, copy_messages_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(copy_messages_request->message_ids);
        copy_messages_request->message_ids = NULL;
    }
    free(copy_messages_request);
}

cJSON *copy_messages_request_convertToJSON(copy_messages_request_t *copy_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // copy_messages_request->chat_id
    if (!copy_messages_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(copy_messages_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // copy_messages_request->from_chat_id
    if (!copy_messages_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = forward_messages_request_from_chat_id_convertToJSON(copy_messages_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // copy_messages_request->message_ids
    if (!copy_messages_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, copy_messages_request->message_ids) {
    if(cJSON_AddNumberToObject(message_ids, "", *(double *)message_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // copy_messages_request->message_thread_id
    if(copy_messages_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", copy_messages_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // copy_messages_request->disable_notification
    if(copy_messages_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", copy_messages_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // copy_messages_request->protect_content
    if(copy_messages_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", copy_messages_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // copy_messages_request->remove_caption
    if(copy_messages_request->remove_caption) {
    if(cJSON_AddBoolToObject(item, "remove_caption", copy_messages_request->remove_caption) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

copy_messages_request_t *copy_messages_request_parseFromJSON(cJSON *copy_messages_requestJSON){

    copy_messages_request_t *copy_messages_request_local_var = NULL;

    // define the local variable for copy_messages_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for copy_messages_request->from_chat_id
    forward_messages_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // define the local list for copy_messages_request->message_ids
    list_t *message_idsList = NULL;

    // copy_messages_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // copy_messages_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = forward_messages_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // copy_messages_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "message_ids");
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

    // copy_messages_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // copy_messages_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // copy_messages_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // copy_messages_request->remove_caption
    cJSON *remove_caption = cJSON_GetObjectItemCaseSensitive(copy_messages_requestJSON, "remove_caption");
    if (cJSON_IsNull(remove_caption)) {
        remove_caption = NULL;
    }
    if (remove_caption) { 
    if(!cJSON_IsBool(remove_caption))
    {
    goto end; //Bool
    }
    }


    copy_messages_request_local_var = copy_messages_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_idsList,
        message_thread_id ? message_thread_id->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        remove_caption ? remove_caption->valueint : 0
        );

    return copy_messages_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        forward_messages_request_from_chat_id_free(from_chat_id_local_nonprim);
        from_chat_id_local_nonprim = NULL;
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
