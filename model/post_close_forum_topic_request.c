#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "post_close_forum_topic_request.h"



static post_close_forum_topic_request_t *post_close_forum_topic_request_create_internal(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int message_thread_id
    ) {
    post_close_forum_topic_request_t *post_close_forum_topic_request_local_var = malloc(sizeof(post_close_forum_topic_request_t));
    if (!post_close_forum_topic_request_local_var) {
        return NULL;
    }
    post_close_forum_topic_request_local_var->chat_id = chat_id;
    post_close_forum_topic_request_local_var->message_thread_id = message_thread_id;

    post_close_forum_topic_request_local_var->_library_owned = 1;
    return post_close_forum_topic_request_local_var;
}

__attribute__((deprecated)) post_close_forum_topic_request_t *post_close_forum_topic_request_create(
    post_restrict_chat_member_request_chat_id_t *chat_id,
    int message_thread_id
    ) {
    return post_close_forum_topic_request_create_internal (
        chat_id,
        message_thread_id
        );
}

void post_close_forum_topic_request_free(post_close_forum_topic_request_t *post_close_forum_topic_request) {
    if(NULL == post_close_forum_topic_request){
        return ;
    }
    if(post_close_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "post_close_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (post_close_forum_topic_request->chat_id) {
        post_restrict_chat_member_request_chat_id_free(post_close_forum_topic_request->chat_id);
        post_close_forum_topic_request->chat_id = NULL;
    }
    free(post_close_forum_topic_request);
}

cJSON *post_close_forum_topic_request_convertToJSON(post_close_forum_topic_request_t *post_close_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // post_close_forum_topic_request->chat_id
    if (!post_close_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = post_restrict_chat_member_request_chat_id_convertToJSON(post_close_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // post_close_forum_topic_request->message_thread_id
    if (!post_close_forum_topic_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", post_close_forum_topic_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

post_close_forum_topic_request_t *post_close_forum_topic_request_parseFromJSON(cJSON *post_close_forum_topic_requestJSON){

    post_close_forum_topic_request_t *post_close_forum_topic_request_local_var = NULL;

    // define the local variable for post_close_forum_topic_request->chat_id
    post_restrict_chat_member_request_chat_id_t *chat_id_local_nonprim = NULL;

    // post_close_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(post_close_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = post_restrict_chat_member_request_chat_id_parseFromJSON(chat_id); //nonprimitive

    // post_close_forum_topic_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(post_close_forum_topic_requestJSON, "message_thread_id");
    if (cJSON_IsNull(message_thread_id)) {
        message_thread_id = NULL;
    }
    if (!message_thread_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(message_thread_id))
    {
    goto end; //Numeric
    }


    post_close_forum_topic_request_local_var = post_close_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble
        );

    return post_close_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        post_restrict_chat_member_request_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
