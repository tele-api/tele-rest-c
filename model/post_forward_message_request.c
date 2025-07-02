#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_forward_message_request.h"



static post_forward_message_request_t *post_forward_message_request_create_internal(
    post_send_message_request_chat_id_t *chat_id,
    post_forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    post_forward_message_request_t *post_forward_message_request_local_var = malloc(sizeof(post_forward_message_request_t));
    if (!post_forward_message_request_local_var) {
        return NULL;
    }
    post_forward_message_request_local_var->chat_id = chat_id;
    post_forward_message_request_local_var->from_chat_id = from_chat_id;
    post_forward_message_request_local_var->message_id = message_id;
    post_forward_message_request_local_var->message_thread_id = message_thread_id;
    post_forward_message_request_local_var->video_start_timestamp = video_start_timestamp;
    post_forward_message_request_local_var->disable_notification = disable_notification;
    post_forward_message_request_local_var->protect_content = protect_content;

    post_forward_message_request_local_var->_library_owned = 1;
    return post_forward_message_request_local_var;
}

__attribute__((deprecated)) post_forward_message_request_t *post_forward_message_request_create(
    post_send_message_request_chat_id_t *chat_id,
    post_forward_message_request_from_chat_id_t *from_chat_id,
    int message_id,
    int message_thread_id,
    int video_start_timestamp,
    int disable_notification,
    int protect_content
    ) {
    return post_forward_message_request_create_internal (
        chat_id,
        from_chat_id,
        message_id,
        message_thread_id,
        video_start_timestamp,
        disable_notification,
        protect_content
        );
}

void post_forward_message_request_free(post_forward_message_request_t *post_forward_message_request) {
    if(NULL == post_forward_message_request){
        return ;
    }
    if(post_forward_message_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_forward_message_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_forward_message_request->chat_id) {
        post_send_message_request_chat_id_free(post_forward_message_request->chat_id);
        post_forward_message_request->chat_id = NULL;
    }
    if (post_forward_message_request->from_chat_id) {
        post_forward_message_request_from_chat_id_free(post_forward_message_request->from_chat_id);
        post_forward_message_request->from_chat_id = NULL;
    }
    free(post_forward_message_request);
}

cJSON *post_forward_message_request_convertToJSON(post_forward_message_request_t *post_forward_message_request) {
    cJSON *item = cJSON_CreateObject();

    // post_forward_message_request->chat_id
    if (!post_forward_message_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_send_message_request_chat_id_convertToJSON(post_forward_message_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_forward_message_request->from_chat_id
    if (!post_forward_message_request->from_chat_id) {
        goto fail;
    }
    cJSON *from_chat_id_local_JSON = post_forward_message_request_from_chat_id_convertToJSON(post_forward_message_request->from_chat_id);
    if(from_chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "from_chat_id", from_chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_forward_message_request->message_id
    if (!post_forward_message_request->message_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_id", post_forward_message_request->message_id) == NULL) {
    goto fail; //Numeric
    }


    // post_forward_message_request->message_thread_id
    if(post_forward_message_request->message_thread_id) {
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_forward_message_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_forward_message_request->video_start_timestamp
    if(post_forward_message_request->video_start_timestamp) {
    if(cJSON_AddNumberToObject(item, "video_start_timestamp", post_forward_message_request->video_start_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // post_forward_message_request->disable_notification
    if(post_forward_message_request->disable_notification) {
    if(cJSON_AddBoolToObject(item, "disable_notification", post_forward_message_request->disable_notification) == NULL) {
    goto fail; //Bool
    }
    }


    // post_forward_message_request->protect_content
    if(post_forward_message_request->protect_content) {
    if(cJSON_AddBoolToObject(item, "protect_content", post_forward_message_request->protect_content) == NULL) {
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

post_forward_message_request_t *post_forward_message_request_parseFromJSON(cJSON *post_forward_message_requestJSON){

    post_forward_message_request_t *post_forward_message_request_local_var = NULL;

    // define the local variable for post_forward_message_request->chat_id
    post_send_message_request_chat_id_t *chat_id_local_nonprim = NULL;

    // define the local variable for post_forward_message_request->from_chat_id
    post_forward_message_request_from_chat_id_t *from_chat_id_local_nonprim = NULL;

    // post_forward_message_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_send_message_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_forward_message_request->from_chat_id
    cJSON *from_chat_id = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "from_chat_id");
    if (cJSON_IsNull(from_chat_id)) {
        from_chat_id = NULL;
    }
    if (!from_chat_id) {
        goto end;
    }

    
    from_chat_id_local_nonprim = post_forward_message_request_from_chat_id_parseFromJSON(from_chat_id); //nonprimitive

    // post_forward_message_request->message_id
    cJSON *message_id = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "message_id");
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

    // post_forward_message_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (message_thread_id) { 
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }
    }

    // post_forward_message_request->video_start_timestamp
    cJSON *video_start_timestamp = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "video_start_timestamp");
    if (cJSON_IsNull(video_start_timestamp)) {
        video_start_timestamp = NULL;
    }
    if (video_start_timestamp) { 
    if(!cJSON_IsNumber(video_start_timestamp))
    {
    goto end; //Numeric
    }
    }

    // post_forward_message_request->disable_notification
    cJSON *disable_notification = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "disable_notification");
    if (cJSON_IsNull(disable_notification)) {
        disable_notification = NULL;
    }
    if (disable_notification) { 
    if(!cJSON_IsBool(disable_notification))
    {
    goto end; //Bool
    }
    }

    // post_forward_message_request->protect_content
    cJSON *protect_content = cJSON_GetObjectItemCaseSensitive(post_forward_message_requestJSON, "protect_content");
    if (cJSON_IsNull(protect_content)) {
        protect_content = NULL;
    }
    if (protect_content) { 
    if(!cJSON_IsBool(protect_content))
    {
    goto end; //Bool
    }
    }


    post_forward_message_request_local_var = post_forward_message_request_create_internal (
        chat_id_local_nonprim,
        from_chat_id_local_nonprim,
        message_id->valuedouble,
        message_thread_id ? message_thread_id->valuedouble : 0,
        video_start_timestamp ? video_start_timestamp->valuedouble : 0,
        disable_notification ? disable_notification->valueint : 0,
        protect_content ? protect_content->valueint : 0
        );

    return post_forward_message_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_send_message_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    if (from_chat_id_local_nonprim) {
        post_forward_message_request_from_chat_id_free(from_chat_id_local_nonprim);
        from_chat_id_local_nonprim = NULL;
    }
    return NULL;

}
