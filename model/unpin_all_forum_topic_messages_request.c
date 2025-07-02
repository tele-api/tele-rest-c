#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "unpin_all_forum_topic_messages_request.h"



static unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request_create_internal(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request_local_var = malloc(sizeof(unpin_all_forum_topic_messages_request_t));
    if (!unpin_all_forum_topic_messages_request_local_var) {
        return NULL;
    }
    unpin_all_forum_topic_messages_request_local_var->chat_id = chat_id;
    unpin_all_forum_topic_messages_request_local_var->message_thread_id = message_thread_id;

    unpin_all_forum_topic_messages_request_local_var->_library_owned = 1;
    return unpin_all_forum_topic_messages_request_local_var;
}

__attribute__((deprecated)) unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request_create(
    bot_command_scope_chat_chat_id_t *chat_id,
    int message_thread_id
    ) {
    return unpin_all_forum_topic_messages_request_create_internal (
        chat_id,
        message_thread_id
        );
}

void unpin_all_forum_topic_messages_request_free(unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request) {
    if(NULL == unpin_all_forum_topic_messages_request){
        return ;
    }
    if(unpin_all_forum_topic_messages_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "unpin_all_forum_topic_messages_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (unpin_all_forum_topic_messages_request->chat_id) {
        bot_command_scope_chat_chat_id_free(unpin_all_forum_topic_messages_request->chat_id);
        unpin_all_forum_topic_messages_request->chat_id = NULL;
    }
    free(unpin_all_forum_topic_messages_request);
}

cJSON *unpin_all_forum_topic_messages_request_convertToJSON(unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request) {
    cJSON *item = cJSON_CreateObject();

    // unpin_all_forum_topic_messages_request->chat_id
    if (!unpin_all_forum_topic_messages_request->chat_id) {
        goto fail;
    }
    cJSON *chat_id_local_JSON = bot_command_scope_chat_chat_id_convertToJSON(unpin_all_forum_topic_messages_request->chat_id);
    if(chat_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "chat_id", chat_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // unpin_all_forum_topic_messages_request->message_thread_id
    if (!unpin_all_forum_topic_messages_request->message_thread_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "message_thread_id", unpin_all_forum_topic_messages_request->message_thread_id) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request_parseFromJSON(cJSON *unpin_all_forum_topic_messages_requestJSON){

    unpin_all_forum_topic_messages_request_t *unpin_all_forum_topic_messages_request_local_var = NULL;

    // define the local variable for unpin_all_forum_topic_messages_request->chat_id
    bot_command_scope_chat_chat_id_t *chat_id_local_nonprim = NULL;

    // unpin_all_forum_topic_messages_request->chat_id
    cJSON *chat_id = cJSON_GetObjectItemCaseSensitive(unpin_all_forum_topic_messages_requestJSON, "chat_id");
    if (cJSON_IsNull(chat_id)) {
        chat_id = NULL;
    }
    if (!chat_id) {
        goto end;
    }

    
    chat_id_local_nonprim = bot_command_scope_chat_chat_id_parseFromJSON(chat_id); //nonprimitive

    // unpin_all_forum_topic_messages_request->message_thread_id
    cJSON *message_thread_id = cJSON_GetObjectItemCaseSensitive(unpin_all_forum_topic_messages_requestJSON, "message_thread_id");
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


    unpin_all_forum_topic_messages_request_local_var = unpin_all_forum_topic_messages_request_create_internal (
        chat_id_local_nonprim,
        message_thread_id->valuedouble
        );

    return unpin_all_forum_topic_messages_request_local_var;
end:
    if (chat_id_local_nonprim) {
        bot_command_scope_chat_chat_id_free(chat_id_local_nonprim);
        chat_id_local_nonprim = NULL;
    }
    return NULL;

}
