#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "_forward_message_post_request.h"



static _forward_message_post_request_t *_forward_message_post_request_create_internal(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    _forward_message_post_request_t *_forward_message_post_request_local_var = malloc(sizeof(_forward_message_post_request_t));
    if (!_forward_message_post_request_local_var) {
        return NULL;
    }
    _forward_message_post_request_local_var->chat_id = chat_id;
    _forward_message_post_request_local_var->from_chat_id = from_chat_id;
    _forward_message_post_request_local_var->message_id = message_id;
    _forward_message_post_request_local_var->message_thread_id = message_thread_id;
    _forward_message_post_request_local_var->video_start_timestamp = video_start_timestamp;
    _forward_message_post_request_local_var->disable_notification = disable_notification;
    _forward_message_post_request_local_var->protect_content = protect_content;

    _forward_message_post_request_local_var->_library_owned = 1;
    return _forward_message_post_request_local_var;
}

__attribute__((deprecated)) _forward_message_post_request_t *_forward_message_post_request_create(
    _send_message_post_request_chat_id_t *chat_id,
    _forward_message_post_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    return _forward_message_post_request_create_internal (
        chat_id,
        from_chat_id,
        message_id,
        message_thread_id,
        video_start_timestamp,
        disable_notification,
        protect_content
        );
}

void _forward_message_post_request_free(_forward_message_post_request_t *_forward_message_post_request) {
    if(NULL == _forward_message_post_request){
        return ;
    }
    if(_forward_message_post_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "_forward_message_post_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (_forward_message_post_request->chat_id) {
        _send_message_post_request_chat_id_free(_forward_message_post_request->chat_id);
        _forward_message_post_request->chat_id = NULL;
    }
    if (_forward_message_post_request->from_chat_id) {
        _forward_message_post_request_from_chat_id_free(_forward_message_post_request->from_chat_id);
        _forward_message_post_request->from_chat_id = NULL;
    }
    free(_forward_message_post_request);
}

cJSON *_forward_message_post_request_convertToJSON(_forward_message_post_request_t *_forward_message_post_request) {
    cJSON *item = cJSON_CreateObject();

    // _forward_message_post_request->chat_id
    if (!_forward_message_post_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = _send_message_post_request_chat_id_convertToJSON(_forward_message_post_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _forward_message_post_request->from_chat_id
    if (!_forward_message_post_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = _forward_message_post_request_from_chat_id_convertToJSON(_forward_message_post_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // _forward_message_post_request->message_id
    if (!_forward_message_post_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", _forward_message_post_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // _forward_message_post_request->message_thread_id
    if(_forward_message_post_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", _forward_message_post_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // _forward_message_post_request->video_start_timestamp
    if(_forward_message_post_request->video_start_timestamp) {
    if(cJSON_AddNumberToObject(item, "video_start_timestamp", _forward_message_post_request->video_start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // _forward_message_post_request->disable_notification
    if(_forward_message_post_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", _forward_message_post_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // _forward_message_post_request->protect_content
    if(_forward_message_post_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", _forward_message_post_request->protect_content) == NULL) {
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

_forward_message_post_request_t *_forward_message_post_request_parseFromJSON(cJSON *_forward_message_post_requestJSON){

    _forward_message_post_request_t *_forward_message_post_request_local_var = NULL;

    // define the local variable for _forward_message_post_request->chat_id
    _send_message_post_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for _forward_message_post_request->from_chat_id
    _forward_message_post_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // _forward_message_post_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = _send_message_post_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // _forward_message_post_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = _forward_message_post_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // _forward_message_post_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "message_id");
    if (cJSON_IsNull(message_id)) {
        message_id = NULL;
    }
    if (!message_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_id))
    {
    goto end; //Numeric
    }

    // _forward_message_post_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // _forward_message_post_request->video_start_timestamp
    cJSON *video_start_timestamp = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "video_start_timestamp");
    if (cJSON_IsNull(video_start_timestamp)) {
        video_start_timestamp = NULL;
    }
    if (video_start_timestamp) { 
    if(!cJSON_IsNumber(video_start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // _forward_message_post_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // _forward_message_post_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(_forward_message_post_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }


    _forward_message_post_request_local_var = _forward_message_post_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_id->valuedouble,
        message_thread_id ? message_thread_id->valuedouble : 0,
        video_start_timestamp ? video_start_timestamp->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0
        );

    return _forward_message_post_request_local_var;
end:
    if (chat_id_local_nonprim) {
        _send_message_post_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        _forward_message_post_request_from_chat_id_free(from_chat_id_local_nonprim);
        from_chat_id_local_nonprim = NULL;
    }
    return NULL;

}
