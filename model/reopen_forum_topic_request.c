#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reopen_forum_topic_request.h"



static reopen_forum_topic_request_t *reopen_forum_topic_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    reopen_forum_topic_request_t *reopen_forum_topic_request_local_var = malloc(sizeof(reopen_forum_topic_request_t));
    if (!reopen_forum_topic_request_local_var) {
        return NULL;
    }
    reopen_forum_topic_request_local_var->chat_id = chat_id;
    reopen_forum_topic_request_local_var->message_thread_id = message_thread_id;

    reopen_forum_topic_request_local_var->_library_owned = 1;
    return reopen_forum_topic_request_local_var;
}

__attribute__((deprecated)) reopen_forum_topic_request_t *reopen_forum_topic_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    return reopen_forum_topic_request_create_internal (
        chat_id,
        message_thread_id
        );
}

void reopen_forum_topic_request_free(reopen_forum_topic_request_t *reopen_forum_topic_request) {
    if(NULL == reopen_forum_topic_request){
        return ;
    }
    if(reopen_forum_topic_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reopen_forum_topic_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reopen_forum_topic_request->chat_id) {
        bot_command_scope_chat_chat_id_free(reopen_forum_topic_request->chat_id);
        reopen_forum_topic_request->chat_id = NULL;
    }
    free(reopen_forum_topic_request);
}

cJSON *reopen_forum_topic_request_convertToJSON(reopen_forum_topic_request_t *reopen_forum_topic_request) {
    cJSON *item = cJSON_CreateObject();

    // reopen_forum_topic_request->chat_id
    if (!reopen_forum_topic_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(reopen_forum_topic_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // reopen_forum_topic_request->message_thread_id
    if (!reopen_forum_topic_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", reopen_forum_topic_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reopen_forum_topic_request_t *reopen_forum_topic_request_parseFromJSON(cJSON *reopen_forum_topic_requestJSON){

    reopen_forum_topic_request_t *reopen_forum_topic_request_local_var = NULL;

    // define the local variable for reopen_forum_topic_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // reopen_forum_topic_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(reopen_forum_topic_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // reopen_forum_topic_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(reopen_forum_topic_requestJSON, "message_thread_id");
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


    reopen_forum_topic_request_local_var = reopen_forum_topic_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble
        );

    return reopen_forum_topic_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
