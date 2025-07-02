#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "forward_message_request.h"



static forward_message_request_t *forward_message_request_create_internal(
    send_message_request_chat_id_t *chat_id,
    forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    forward_message_request_t *forward_message_request_local_var = malloc(sizeof(forward_message_request_t));
    if (!forward_message_request_local_var) {
        return NULL;
    }
    forward_message_request_local_var->chat_id = chat_id;
    forward_message_request_local_var->from_chat_id = from_chat_id;
    forward_message_request_local_var->message_id = message_id;
    forward_message_request_local_var->message_thread_id = message_thread_id;
    forward_message_request_local_var->video_start_timestamp = video_start_timestamp;
    forward_message_request_local_var->disable_notification = disable_notification;
    forward_message_request_local_var->protect_content = protect_content;

    forward_message_request_local_var->_library_owned = 1;
    return forward_message_request_local_var;
}

__attribute__((deprecated)) forward_message_request_t *forward_message_request_create(
    send_message_request_chat_id_t *chat_id,
    forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    return forward_message_request_create_internal (
        chat_id,
        from_chat_id,
        message_id,
        message_thread_id,
        video_start_timestamp,
        disable_notification,
        protect_content
        );
}

void forward_message_request_free(forward_message_request_t *forward_message_request) {
    if(NULL == forward_message_request){
        return ;
    }
    if(forward_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "forward_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (forward_message_request->chat_id) {
        send_message_request_chat_id_free(forward_message_request->chat_id);
        forward_message_request->chat_id = NULL;
    }
    if (forward_message_request->from_chat_id) {
        forward_message_request_from_chat_id_free(forward_message_request->from_chat_id);
        forward_message_request->from_chat_id = NULL;
    }
    free(forward_message_request);
}

cJSON *forward_message_request_convertToJSON(forward_message_request_t *forward_message_request) {
    cJSON *item = cJSON_CreateObject();

    // forward_message_request->chat_id
    if (!forward_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = send_message_request_chat_id_convertToJSON(forward_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // forward_message_request->from_chat_id
    if (!forward_message_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = forward_message_request_from_chat_id_convertToJSON(forward_message_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // forward_message_request->message_id
    if (!forward_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", forward_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // forward_message_request->message_thread_id
    if(forward_message_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", forward_message_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // forward_message_request->video_start_timestamp
    if(forward_message_request->video_start_timestamp) {
    if(cJSON_AddNumberToObject(item, "video_start_timestamp", forward_message_request->video_start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // forward_message_request->disable_notification
    if(forward_message_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", forward_message_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // forward_message_request->protect_content
    if(forward_message_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", forward_message_request->protect_content) == NULL) {
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

forward_message_request_t *forward_message_request_parseFromJSON(cJSON *forward_message_requestJSON){

    forward_message_request_t *forward_message_request_local_var = NULL;

    // define the local variable for forward_message_request->chat_id
    send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for forward_message_request->from_chat_id
    forward_message_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // forward_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // forward_message_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = forward_message_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // forward_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "message_id");
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

    // forward_message_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // forward_message_request->video_start_timestamp
    cJSON *video_start_timestamp = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "video_start_timestamp");
    if (cJSON_IsNull(video_start_timestamp)) {
        video_start_timestamp = NULL;
    }
    if (video_start_timestamp) { 
    if(!cJSON_IsNumber(video_start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // forward_message_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // forward_message_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(forward_message_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }


    forward_message_request_local_var = forward_message_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_id->valuedouble,
        message_thread_id ? message_thread_id->valuedouble : 0,
        video_start_timestamp ? video_start_timestamp->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0
        );

    return forward_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        forward_message_request_from_chat_id_free(from_chat_id_local_nonprim);
        from_chat_id_local_nonprim = NULL;
    }
    return NULL;

}
