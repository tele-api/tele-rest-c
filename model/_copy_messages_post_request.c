#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_copy_messages_post_request.h"



static _copy_messages_post_request_t *_copy_messages_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_messages_post_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
    ) {
    _copy_messages_post_request_t *_copy_messages_post_request_local_var = malloc(sizeof(_copy_messages_post_request_t));
    if (!_copy_messages_post_request_local_var) {
        return NULL;
    }
    _copy_messages_post_request_local_var->chat_id = chat_id;
    _copy_messages_post_request_local_var->from_chat_id = from_chat_id;
    _copy_messages_post_request_local_var->message_ids = message_ids;
    _copy_messages_post_request_local_var->message_thread_id = message_thread_id;
    _copy_messages_post_request_local_var->disable_notification = disable_notification;
    _copy_messages_post_request_local_var->protect_content = protect_content;
    _copy_messages_post_request_local_var->remove_caption = remove_caption;

    _copy_messages_post_request_local_var->_library_owned = 1;
    return _copy_messages_post_request_local_var;
}

__attribute__((deprecated)) _copy_messages_post_request_t *_copy_messages_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_messages_post_request_from_chat_id_t *from_chat_id,
    list_t *message_ids,
    int message_thread_id,
    int disable_notification,
    int protect_content,
    int remove_caption
    ) {
    return _copy_messages_post_request_create_internal (
        chat_id,
        from_chat_id,
        message_ids,
        message_thread_id,
        disable_notification,
        protect_content,
        remove_caption
        );
}

void _copy_messages_post_request_free(_copy_messages_post_request_t *_copy_messages_post_request) {
    if(NULL == _copy_messages_post_request){
        return ;
    }
    if(_copy_messages_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_copy_messages_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_copy_messages_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_copy_messages_post_request->chat_id);
        _copy_messages_post_request->chat_id = NULL;
    }
    if (_copy_messages_post_request->from_chat_id) {
        _forward_messages_post_request_from_chat_id_free(_copy_messages_post_request->from_chat_id);
        _copy_messages_post_request->from_chat_id = NULL;
    }
    if (_copy_messages_post_request->message_ids) {
        list_ForEach(listEntry, _copy_messages_post_request->message_ids) {
            free(listEntry->data);
        }
        list_freeList(_copy_messages_post_request->message_ids);
        _copy_messages_post_request->message_ids = NULL;
    }
    free(_copy_messages_post_request);
}

cJSON *_copy_messages_post_request_convertToJSON(_copy_messages_post_request_t *_copy_messages_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _copy_messages_post_request->chat_id
    if (!_copy_messages_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_copy_messages_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _copy_messages_post_request->from_chat_id
    if (!_copy_messages_post_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = _forward_messages_post_request_from_chat_id_convertToJSON(_copy_messages_post_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _copy_messages_post_request->message_ids
    if (!_copy_messages_post_request->message_ids) {
        goto fail;
    }
    cJSON *message_ids = cJSON_AddArrayToObject(item, "message_ids");
    if(message_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *message_idsListEntry;
    list_ForEach(message_idsListEntry, _copy_messages_post_request->message_ids) {
    if(cJSON_AddNumberToObject(message_ids, "", *(double *)message_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }


    // _copy_messages_post_request->message_thread_id
    if(_copy_messages_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _copy_messages_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _copy_messages_post_request->disable_notification
    if(_copy_messages_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _copy_messages_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_messages_post_request->protect_content
    if(_copy_messages_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _copy_messages_post_request->protect_content) == NULL) {
    goto fail; //Bool
    }
    }


    // _copy_messages_post_request->remove_caption
    if(_copy_messages_post_request->remove_caption) {
    if(cJSON_AddBoolToObject(item, "remove_caption", _copy_messages_post_request->remove_caption) == NULL) {
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

_copy_messages_post_request_t *_copy_messages_post_request_parseFromJSON(cJSON *_copy_messages_post_requestJSON){

    _copy_messages_post_request_t *_copy_messages_post_request_local_var = NULL;

    // define the local variable for _copy_messages_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _copy_messages_post_request->from_chat_id
    _forward_messages_post_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // define the local list for _copy_messages_post_request->message_ids
    list_t *message_idsList = NULL;

    // _copy_messages_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _copy_messages_post_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = _forward_messages_post_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // _copy_messages_post_request->message_ids
    cJSON *message_ids = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "message_ids");
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

    // _copy_messages_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _copy_messages_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _copy_messages_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }

    // _copy_messages_post_request->remove_caption
    cJSON *remove_caption = cJSON_GetObjectItemCaseSensitive(_copy_messages_post_requestJSON, "remove_caption");
    if (cJSON_IsNull(remove_caption)) {
        remove_caption = NULL;
    }
    if (remove_caption) { 
    if(!cJSON_IsBool(remove_caption))
    {
    goto end; //Bool
    }
    }


    _copy_messages_post_request_local_var = _copy_messages_post_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_idsList,
        message_thread_id ? message_thread_id->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0,
        remove_caption ? remove_caption->valueint : 0
        );

    return _copy_messages_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        _forward_messages_post_request_from_chat_id_free(from_chat_id_local_nonprim);
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
